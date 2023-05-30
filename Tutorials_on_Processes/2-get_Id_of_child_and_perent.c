#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    pid_t id;

    printf("Perent Process: Executed by the perent process before fork() - PID = (%d)\n", getpid());

    id = fork();

    if(id < 0)
    {
        printf("\n fork failed");
        exit(-1);
    }

    if(id > 0)
    {
        printf("\n Perent Process: I have created process withID = (%d)\n", id);
        sleep(30);
    }
    else
    {
        printf("\n I am child process, id value is (%d) \n", id);
        printf("\n Child process id is (%d) \n", getpid());
        printf("\n The creator of the child process is (%d) \n", getppid());
    }
    return 0;

}