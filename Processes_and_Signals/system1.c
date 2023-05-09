#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Running ps using system\n");
    system("ps ax");
    printf("\nDone.\n");

    exit(0);
}