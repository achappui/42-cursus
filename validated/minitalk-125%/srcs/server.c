/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:29:29 by achappui          #+#    #+#             */
/*   Updated: 2024/01/13 15:20:10 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	getting_len(int sig, t_reception *r)
{
	static unsigned int	mask1 = 1U << 31U;

	if (sig == SIGUSR1)
		r->len |= mask1;
	mask1 /= 2;
	if (mask1 == 0)
	{
		mask1 = 1U << 31U;
		r->str = (char *)ft_calloc(r->len + 1, sizeof(char));
		if (!r->str)
		{
			ft_printf("[SERVER] MALLOC ERROR\n");
			kill(r->client_pid, SIGUSR2);
			exit(1);
		}
		r->state = GETTING_STR;
	}
}

void	getting_str(int sig, t_reception *r)
{
	static unsigned char	mask = 1U << 7U;
	static unsigned int		i = 0;

	if (sig == SIGUSR1)
		r->str[i] |= mask;
	mask /= 2;
	if (mask == 0)
	{
		mask = 1U << 7U;
		i++;
		if (i == r->len)
		{
			i = 0;
			r->state = PROCESS_END;
		}
	}
}

void	end_process(t_reception *r)
{
	int	tmp_pid;

	write(1, r->str, r->len);
	write(1, "\n", 1);
	free(r->str);
	tmp_pid = r->client_pid;
	r->client_pid = 0;
	r->str = NULL;
	r->len = 0;
	r->state = ASK_FIRST_BIT;
	kill(tmp_pid, SIGUSR2);
}

void	packet_receiver(int sig, siginfo_t *info, void *ptr)
{
	static t_reception	r = {.client_pid = 0, .len = 0, .str = NULL, \
								.state = ASK_FIRST_BIT};

	(void)ptr;
	if (r.client_pid == 0)
		r.client_pid = info->si_pid;
	if (r.state == ASK_FIRST_BIT)
		r.state = GETTING_LEN;
	else if (r.state == GETTING_LEN)
		getting_len(sig, &r);
	else if (r.state == GETTING_STR)
		getting_str(sig, &r);
	if (r.state == PROCESS_END)
		end_process(&r);
	else
		kill(r.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = &packet_receiver;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("[SERVER] %d\n", getpid());
	while (1)
		pause();
	return (0);
}
