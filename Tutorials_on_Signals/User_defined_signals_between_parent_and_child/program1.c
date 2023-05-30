#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>


static void signal_handler(int signo)
{
    if(signo == SIGUSR1)
        printf(" Parent: Cought SIGUSR1\n");
    exit(EXIT_SUCCESS);
}

int main()
{
    pid_t cpid;
    int status;

    cpid = fork();
    if(cpid == -1)
    {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if(cpid == 0)
    {
        printf("\n Child: This is the child process before the excl system  call\n");
        execl("./program2", "arg1", "arg2", NULL);
        printf("Child: This Line of code will never be executed\n");
    }
    else
    {
        if(signal(SIGUSR1, signal_handler) == SIG_ERR)
        {
            fprintf(stderr, "Cannot handle SIGUSR1\n");
            exit(-1);
        }
        printf("\n Parent: Perent executing before wait, My childs PID is (%d)\n", cpid);
        sleep(2);
        printf("\n Parent: Sending kill system call to child\n");
        kill(cpid, SIGUSR2);
        cpid = wait(&status);
        printf("\n Parent: Parent execting after wait, My PID is (%d)\n", getpid());
        printf(" Parent: Child returned with a PID of (%d)\n", cpid);
        printf(" Parent: Status code returned is (%d)\n", status);
    }
    return 0;
}