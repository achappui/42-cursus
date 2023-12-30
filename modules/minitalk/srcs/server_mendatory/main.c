/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:29:29 by achappui          #+#    #+#             */
/*   Updated: 2023/12/28 18:14:02 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	g_sig;

int	receive_clientpid()
{
	int				client_pid;
	unsigned int	mask;

	client_pid = 0;
	mask = 1 << (sizeof(int) * 8 - 1);
	//printf("MASK %u:\n", mask);
	while (mask != 0)
	{
		pause();
		if (g_sig == 1)
			client_pid |= mask;
		mask /= 2;
	}
	return (client_pid);
}

size_t	receive_stringlen()
{
	size_t	strlen;
	size_t	mask;

	strlen = 0;
	mask = 1ULL << (sizeof(size_t) * 8 - 1);
	while (mask != 0)
	{
		pause();
		if (g_sig == 1)
			strlen |= mask;
		mask /= 2;
		//kill(client_pid, SIGUSR1);
	}
	return (strlen);
}

char	*receive_string(size_t len)
{
	char			*str;
	unsigned char	mask;
	size_t			i;

	str = (char *)calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mask = 1 << 7;
		while (mask != 0)
		{
			pause();
			if (g_sig == 1)
				str[i] |= mask;
			mask /= 2;
			//kill(client_pid, SIGUSR1);
		}
		i++;
	}
	return (str);
}

void handle_sigusr(int sig)
{
	if (sig == SIGUSR1)
	{
		//printf("Bien recu (1)\n");
		g_sig = 1;
	}
	else if (sig == SIGUSR2)
	{
		//printf("Bien recu (2)\n");
		g_sig = 2;
	}
}

int main()
{
    int					pid;
	struct sigaction	sa;
	int					client_pid;
	size_t				stringlen;
	char				*str;

	pid = getpid();
	sa.sa_handler = &handle_sigusr;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("PID du serveur : %d\n", pid);
    printf("En attente du signal...\n");

	client_pid = receive_clientpid();
	stringlen = receive_stringlen();
	str = receive_string(stringlen);

	printf("Client_pid: %d\n", client_pid);
	printf("Stringlen: %lu\n", stringlen);
	printf("String: %s\n", str);
	free(str);
    return (0);
}


// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

// void handle_sigusr1(int sig) {
//     (void)sig;
//     printf("Ceci est un 1 !\n");
// }

// void handle_sigusr0(int sig) {
//     (void)sig;
//     printf("Ceci est un 0 !\n");
// }

// int main() {
//     int pid = getpid();
//     printf("PID du serveur : %d\n", pid);

//     struct sigaction sa1;
//     sa1.sa_handler = &handle_sigusr1;
//     sigaction(SIGUSR1, &sa1, NULL);
// 	struct sigaction sa0;
//     sa0.sa_handler = &handle_sigusr0;
//     sigaction(SIGUSR2, &sa0, NULL);

//     printf("En attente du signal...\n");
//     pause();

//     return 0;
// }
