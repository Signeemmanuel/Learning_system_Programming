#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

static int gdata = 111;
int main()
{
    pid_t id1, id2, cpid1, cpid2;
    id1 = fork();
    int status1, status2;
    

    if (id1 == -1)
    {
        
        printf("Error: fork() 1 failed\n");
        exit(-1);
    }
    else if (id1 == 0)
    {
        sleep(3);
        printf("This is the First child: PID is (%d)\n", getpid());
        printf("My parent PId is (%d)\n\n", getppid());
        exit(1);
    }
    else
    {
        id2 = fork();

        if (id2 == -1)
        {
            printf("Error: fork() 2 failed\n");
            exit(-1);
        }
        else if (id2 == 0)
        {   sleep(5);
            printf("This is the Second child: PID is (%d)\n", getpid());
            printf("My parent PId is (%d)\n\n", getppid());
            exit(2);
        }
        else
        {
            printf("This is the parent: PID is (%d) \n", getpid());
            printf("Waiting for First Child\n");
            cpid1 = waitpid(id1, &status1, 0);
            printf("First child Status Code is (%d)\n", status1 % 255);
            printf("waiting for Second Child\n");
            cpid2 = waitpid(id2, &status2, 0);
            printf("Second child Status Code is (%d)\n", status2 % 255);
            
            printf("My Children PID are (%d) and (%d)\n\n", id1, id2);
        }
    }
    return (0);
}