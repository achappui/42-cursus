#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>






int	main()
{
	int test = 0b101100011;

	printf("%d\n", test & 0b001000000);
	return (0);
}

// int x = 0;

// void handle_sigusr(int sig) {
//     if (x == 0) {
//         printf("(HINT) Remember that multiplication  is repetitive addition!\n");
//     }
// }

// int main(int argc, char* argv[]) {

// 	struct sigset_t	sigset;

// 	sigemptyset(sigset);

//     int pid = fork();
//     if (pid == -1) {
//         return 1;
//     }
    
//     if (pid == 0) {
//         // Child process
//         sleep(2);
//         kill(getppid(), SIGUSR1);
//     } else {
//         // Parent process
//         struct sigaction sa;
//         sa.sa_flags = SA_RESTART;
//         sa.sa_handler = &handle_sigusr;
//         sigaction(SIGUSR1, &sa, NULL);
        
//         printf("What is the result of 3 x 5?: ");
//         scanf("%d", &x);
//         if (x == 15) {
//             printf("Right!\n");
//         } else {
//             printf("Wrong\n");
//         }
//         //wait(NULL);
//     }
//     return 0;
// }