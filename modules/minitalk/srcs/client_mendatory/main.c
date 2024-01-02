/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:21:24 by achappui          #+#    #+#             */
/*   Updated: 2024/01/02 12:51:49 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*g_packet;

void	prepare_packet(char *str)
{
	unsigned int	len;
	unsigned int	i;

	len = (unsigned int)ft_strlen(str);
	ft_printf("STRING LEN: %u\n", len);
	g_packet = (char *)malloc((ft_strlen(str) + sizeof(int)) * sizeof(char));
	if (!g_packet)
		exit(write(2, "[CLIENT] MALLOC ERROR !\n", 24));
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

void	packet_sender(int sig, siginfo_t *info, void *ptr)
{
	static unsigned char	mask = 0;
	static unsigned int		i = UINT_MAX;

	(void)ptr;
	(void)sig;
	mask /= 2;
	if (mask == 0)
	{
		mask = 1 << 7;
		i++;
		if (i > 3 && g_packet[i] == '\0')
		{
			//ft_printf("[CLIENT] Message was sent !\n");
			exit(0);
		}
	}
	if (g_packet[i] & mask)
		kill(info->si_pid, SIGUSR1);
	else
		kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argc;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = &packet_sender;
	sigaction(SIGUSR1, &sa, NULL);
	//ft_printf("[CLIENT] %d\n", getpid());
	prepare_packet(argv[2]);
	kill(ft_atoi(argv[1]), SIGUSR1);
	while (1)
		pause();
	return (0);
}
