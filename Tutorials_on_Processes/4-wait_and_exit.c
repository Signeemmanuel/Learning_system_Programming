#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>


int main()
{
    pid_t cpid;
    int status = 0;

    cpid = fork();
    
    if(cpid == -1)
    {
        exit(-1);
    }
    if(cpid == 0)
    {
        printf("\n Child executing first its pid = (%d) \n", getpid());
        sleep(20);
        printf("Child pid = (%d)\n", getpid());
        exit(3);
    }
    else
    {
        printf("\n Parent executing before wait()\n");
        cpid = wait(&status);
        printf("\n wait() in parent done\n Parent pid = (%d)\n", getpid());
        printf("\n cpid returned is (%d)\n", status);
        printf("\n status = (%d)\n", status);
    }

    return 0;
}