#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    pid_t cpid;
    pid_t cpid2;
    int status = 0;

    cpid = fork();
    if(cpid == -1)
    {
        exit(-1);
    }
    else if(cpid == 0)
    {
        printf("\tchild-1 executinf its pid = (%d)", getpid());
        sleep(10);
        printf("\t child1 exited\n");
        exit(0);
    }
    else
    {

        cpid2 = fork();
        if(cpid == -1)
        {
            exit(-1);
        }
        else if(cpid == 0)
        {
            printf("\t child-1 executinf its pid = (%d)\n", getpid());
            sleep(10);
            printf("\t child1 exited\n");
            exit(1);
        }
        else
        {
            printf("\n Parent executing its pid = (%d)\n", getpid());
            cpid = wait(&status);
            printf("\n cpid return is (%d)\n", cpid);
            printf(" status is (%d)\n", status);
            cpid = wait(&status);
            printf("\n cpid return is (%d)\n", cpid);
            printf(" status is (%d)\n", status);
            printf(" Parent exited\n");
        }
    }
    return 0;
}