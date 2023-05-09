#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    printf("Running ps using execlp\n");
    execlp("ps", "ps", "ax", 0);
    printf("\nDone.\n");
    
    exit(0);
}