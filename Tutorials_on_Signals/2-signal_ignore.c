#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static void signal_handler(int signo)
{
    if(signo == SIGINT)
        printf("Cought SIGINT\n");
    else if(signo == SIGTERM)
        printf("Cought SIGTERM\n");
    exit(EXIT_SUCCESS);
}

int main()
{
    if(signal(SIGINT, SIG_IGN) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGINT\n");
        exit(-1);
    }
        
    if(signal(SIGTERM, signal_handler) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGTERM\n");
        exit(-1);
    }  
    while(1);
}
