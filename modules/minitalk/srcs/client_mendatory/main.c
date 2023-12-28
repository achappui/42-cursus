#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define PID		1
#define STRING	2

// le plan: envoyer SIGUSR1 pour 1 et SIGUSR2 pour 0, envoyer la longueur de la string dans le premier long, puis 

int main(int argc, char* argv[]) {
	(void)argc;
	if (atoi(argv[2]) == 1)
		kill(atoi(argv[PID]), SIGUSR1);
	else if (atoi(argv[2]) == 0)
		kill(atoi(argv[PID]), SIGUSR2);
	printf("programme fini");
    return 0;
}