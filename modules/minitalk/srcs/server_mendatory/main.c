/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:29:29 by achappui          #+#    #+#             */
/*   Updated: 2023/12/28 13:34:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr(int sig)
{
	if (sig == SIGUSR1)
    	printf("Ceci est un 1 !\n");
	else if (sig == SIGUSR2)
    	printf("Ceci est un 0 !\n");
}

int main()
{
    int				pid;
	struct sigaction sa;

	pid = getpid();
	sa.sa_handler = &handle_sigusr;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("PID du serveur : %d\n", pid);
    printf("En attente du signal...\n");
	while (1)
	{
		pause();
		printf("sending process ID: %d\n", sa.)
	}

    return 0;
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
