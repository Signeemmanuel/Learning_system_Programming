/*
Write a program that creates a child process using the fork() system call. The child process should execute a long-running task, such as computing the factorial of a large number. The parent process should be able to terminate the child process using a SIGINT signal.
*/
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static void signal_handler(int signo)
{
    if (signo == SIGINT)
    {
        printf("Cought SIGINT\n");
    }
    exit(EXIT_SUCCESS);
}

int main()
{
    pid_t cpid;
    int i, num1, num2, fact, result;
    
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        fprintf(stderr, " Couldn't handle SIGINT\n");
    }

    cpid = fork();    
    if(cpid == -1)
    {
        fprintf(stderr, " Fork failed\n");
        return -1;
    }
    else if (cpid == 0)
    {
        printf("\n Child: This is the child process with process id (%d)\n", getpid());
        printf(" Chlid: My perent has a PID of (%d)\n", getppid());

        num1 = 1;
        num2 = 2;
        fact = 100;
        printf("\n Child: Before executing factorial\n");
        for (i = 0; i < fact; i++)
        {
            result = num1 + num2;
            num1 = num2;
            num2 = result;
        }
        sleep(5);
        printf("\n The100th factorial is (%d)\n", result);
        printf(" Child: Exiting\n");
        return result;
    }
    else
    {
        printf("\n Parent: This is the perent with a PID of (%d)\n", getpid());
        printf(" Parent: My Child's PID is (%d)\n", cpid);
        
        sleep(3);
        printf("\n Parent: Perent About to send kill child process with SIGINT signal\n");
        kill(cpid, SIGINT);

        sleep(5);
        printf(" Parent: Exiting\n");
    }
    return (0);
}