#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static void signal_handler(int signo)
{
    if(signo == SIGUSR2)
        printf("Child: Cought SIGUSR2\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
    int i;

    printf("\n Child: I am new process called by execl()\n");
    printf(" Child: new program PID is (%d)\n\n", getpid());
    
    if (signal(SIGUSR2, signal_handler) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGUSR2\n");
        exit(-1);
    }

    for(i = 0; i < argc; i++)
    {
        printf("Child: argv[%d] = %s: \n", i, argv[i]);
    }
    sleep(5);
    printf("\nChild: Sending kill system call to parent\n");
    kill(getppid(), SIGUSR1);

    sleep(10);
    printf("\nChild: Exiting\n");
    return 0;
}