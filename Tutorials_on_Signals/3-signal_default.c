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
    if(signal(SIGINT, signal_handler) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGINT\n");
        exit(EXIT_FAILURE);
    }
        
    if(signal(SIGTERM, SIG_DFL) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGTERM\n");
        exit(EXIT_FAILURE);
    }  
    while(1);
}
