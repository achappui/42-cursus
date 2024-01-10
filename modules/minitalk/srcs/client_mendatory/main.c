/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:21:24 by achappui          #+#    #+#             */
/*   Updated: 2024/01/10 19:44:07 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*g_packet = NULL;

static void	end_process(char error)
{
	free(g_packet);
	g_packet = NULL;
	if (error)
		ft_printf("[SERVER] Message could not be delivered ! \
					(malloc error)\n");
	else
		ft_printf("[SERVER] Message was successfully delivered !\n");
	exit(0);
}

static void	prepare_packet()
{
	unsigned int	len;
	unsigned int	i;
	char 			*str;

	str = g_packet;
	len = (unsigned int)ft_strlen(str);
	g_packet = (char *)malloc((ft_strlen(str) + sizeof(int)) * sizeof(char));
	if (!g_packet)
	{
		ft_printf("[CLIENT] Message could not be sent ! (malloc error)\n");
		exit(1);
	}
	g_packet[0] = (char)(len >> 24);
	g_packet[1] = (char)(len >> 16);
	g_packet[2] = (char)(len >> 8);
	g_packet[3] = (char)(len >> 0);
	i = 0;
	g_packet += 4;
	while (str[i] != '\0')
	{
		g_packet[i] = str[i];
		i++;
	}
	g_packet[i] = '\0';
	g_packet -= 4;
}

static void	packet_sender(int sig, siginfo_t *info, void *ptr)
{
	static unsigned char	mask = 0;
	static unsigned int		i = UINT_MAX;
	static char				state = PACKET_NOT_READY;

	(void)ptr;
	(void)sig;
	if (state == PACKET_NOT_READY)
	{
		prepare_packet();
		state = PACKET_READY;
	}
	mask /= 2;
	if (mask == 0)
	{
		mask = 1 << 7;
		i++;
		if (sig == SIGUSR2)
			end_process(!(i > 3 && g_packet[i] == '\0'));
	}
	if (g_packet[i] & mask)
		kill(info->si_pid, SIGUSR1);
	else
		kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	unsigned int		i;

	(void)argc;
	i = 0;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = &packet_sender;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_packet = argv[2];
	kill(ft_atoi(argv[1]), SIGUSR1);
	while (i < 200)
	{
		usleep(10);
		if (g_packet != argv[2]) //nan car g_packet et initialiser avant et non a la reception du signal du serveur
			while (1)
				pause();
		i++;
	}
	if (g_packet != argv[2] && g_packet != NULL)
		free(g_packet);
	ft_printf("[CLIENT] Could not reach the server !\n");
	return (0);
}
