/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:21:24 by achappui          #+#    #+#             */
/*   Updated: 2024/01/13 15:12:58 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_com	g_com = {.packet = NULL, .server_reached = 0, .server_pid = 0};

static void	end_process(int sig, char error)
{
	free(g_com.packet);
	g_com.packet = NULL;
	if (sig == SIGUSR2)
	{
		if (error)
			ft_printf("[SERVER] MALLOC ERROR\n");
		else
			ft_printf("[SERVER] Message was successfully delivered !\n");
	}
	exit(0);
}

static void	prepare_packet(char *str)
{
	unsigned int	len;
	unsigned int	i;

	len = (unsigned int)ft_strlen(str);
	g_com.packet = (char *)malloc((len + sizeof(int)) * sizeof(char));
	if (!g_com.packet)
	{
		ft_printf("[CLIENT] Could not make the packet ! (malloc error)\n");
		exit(1);
	}
	g_com.packet[0] = (char)(len >> 24);
	g_com.packet[1] = (char)(len >> 16);
	g_com.packet[2] = (char)(len >> 8);
	g_com.packet[3] = (char)(len >> 0);
	g_com.packet += 4;
	i = 0;
	while (str[i] != '\0')
	{
		g_com.packet[i] = str[i];
		i++;
	}
	g_com.packet[i] = '\0';
	g_com.packet -= 4;
}

static void	packet_sender(int sig)
{
	static unsigned char	mask = 0;
	static unsigned int		i = UINT_MAX;

	if (g_com.server_reached == 0)
		g_com.server_reached = 1;
	mask /= 2;
	if (mask == 0)
	{
		mask = 1 << 7;
		i++;
		if (sig == SIGUSR2 || (i > 3 && g_com.packet[i] == '\0'))
			end_process(sig, !(i > 3 && g_com.packet[i] == '\0'));
	}
	if (g_com.packet[i] & mask)
		kill(g_com.server_pid, SIGUSR1);
	else
		kill(g_com.server_pid, SIGUSR2);
}

void	check_arguments(int argc, char *argv[])
{
	if (argc != 3 || ft_atoi(argv[1]) <= 0)
	{
		ft_printf("Invalid arguments.\n");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	unsigned int		i;

	check_arguments(argc, argv);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &packet_sender;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	prepare_packet(argv[2]);
	g_com.server_pid = ft_atoi(argv[1]);
	i = 0;
	kill(g_com.server_pid, SIGUSR1);
	while (i < 400)
	{
		usleep(10);
		if (g_com.server_reached)
			while (1)
				pause();
		i++;
	}
	if (g_com.packet)
		free(g_com.packet);
	ft_printf("[CLIENT] Could not reach the server !\n");
	return (0);
}
