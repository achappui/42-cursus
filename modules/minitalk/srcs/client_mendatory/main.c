/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:21:24 by achappui          #+#    #+#             */
/*   Updated: 2023/12/28 18:13:40 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_clientpid(int server_pid, int client_pid)
{
	unsigned int	mask;

	mask = 1 << (sizeof(int) * 8 - 1);
	while (mask != 0)
	{
		if (client_pid & mask)
		{
			//printf("1`\n");
			kill(server_pid, SIGUSR1);
		}
		else
		{
			//printf("2`\n");
			kill(server_pid, SIGUSR2);
		}
		usleep(60);
		mask /= 2;
		//pause();
	}
}

void	send_stringlen(int server_pid, size_t len)
{
	size_t mask;

	mask = 1ULL << (sizeof(size_t) * 8 - 1);
	while (mask != 0)
	{
		if (len & mask)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(30);
		mask /= 2;
		//pause();
	}
}

void	send_string(int server_pid, char *str, size_t len)
{
	unsigned char	mask;
	size_t			i;

	i = 0;
	while (i < len)
	{
		mask = 1 << 7;
		while (mask != 0)
		{
			if (str[i] & mask)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			mask /= 2;
			usleep(30);
			//pause();
		}
		i++;
	}
}

void handle_sigusr(int sig)
{
	(void)sig;
	return ;
}

int main(int argc, char* argv[])
{

	int					server_pid;
	int					client_pid;
	size_t				stringlen;
	struct sigaction	sa;

	(void)argc;

	printf("Client_pid: %d\n", getpid());

	sa.sa_handler = &handle_sigusr;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

	server_pid = atoi(argv[1]);
	client_pid = getpid();
	stringlen = strlen(argv[2]);

	send_clientpid(server_pid, client_pid);
	send_stringlen(server_pid, stringlen);
	send_string(server_pid, argv[2], stringlen);

	printf("Tout a ete envoyer !!!");

    return 0;
}