#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>


// Allocate in data segment - Global data
static int gdata = 111;
int main()
{
    int istack = 222;
    pid_t childPid;

    // Allocated in stact segment
    switch(childPid = fork())
    {
        case -1:
            printf("\n Fork() error:");
            exit(-1);
        case 0:
            printf("\n I am child process \n");
            gdata *= 3;
            istack *= 3;
            printf("\n pid  (%d), gdata = (%d), istack = (%id)\n", getpid(), gdata, istack);
            sleep(5);
            break;
        default:
        printf("\n I am parent process \n");
        printf("\n pid  (%d), gdata = (%d), istack = (%id)\n", getpid(), gdata, istack);
        sleep(5);
        break;
    }
    exit(0);
}