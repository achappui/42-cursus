/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:29:29 by achappui          #+#    #+#             */
/*   Updated: 2024/01/10 19:44:10 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	getting_len(siginfo_t *info, unsigned int *len, char **str, char *state)
{
	static unsigned int	mask1 = 1U << 31U;

	if (info->si_signo == SIGUSR1)
		*len |= mask1;
	mask1 /= 2;
	if (mask1 == 0)
	{
		mask1 = 1U << 31U;
		*str = (char *)ft_calloc(*len + 1, sizeof(char));
		if (!*str)
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("[SERVER] MALLOC ERROR\n");
			exit(1);
		}
		*state = GETTING_STR;
	}
}

void	getting_str(int sig, unsigned int *len, char **str, char *state)
{
	static unsigned char	mask = 1U << 7U;
	static unsigned int		i = 0;

	if (sig == SIGUSR1)
		(*str)[i] |= mask;
	mask /= 2;
	if (mask == 0)
	{
		mask = 1U << 7U;
		i++;
		if (i == *len)
		{
			i = 0;
			*state = PROCESS_END;
		}
	}
}

void	end_process(pid_t client_pid, char **str, unsigned int *len, char *state)
{
	write(1, *str, *len);
	write(1, "\n", 1);
	free(*str);
	*str = NULL;
	*len = 0;
	*state = ASK_FIRST_BIT;
	kill(client_pid, SIGUSR2);
}

void	handle_sigusr(int sig, siginfo_t *info, void *ptr)
{
	static unsigned int	len = 0;
	static char			*str = NULL;
	static char			state = ASK_FIRST_BIT;

	(void)ptr;
	if (state == ASK_FIRST_BIT)
		state = GETTING_LEN;
	else if (state == GETTING_LEN)
		getting_len(info, &len, &str, &state);
	else if (state == GETTING_STR)
		getting_str(sig, &len, &str, &state);
	if (state == PROCESS_END)
		end_process(info->si_pid, &str, &len, &state);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = &handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("[SERVER] %d\n", getpid());
	while (1)
		pause();
	return (0);
}
