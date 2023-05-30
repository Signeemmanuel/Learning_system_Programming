#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

static void generate_message()
{
    printf("Generated SIGALRM\n");

    alarm(2);
}

int main()
{
    signal(SIGALRM, generate_message);
    alarm(2);

    while(1);
}