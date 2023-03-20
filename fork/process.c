#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    fork();
    fork();
    fork();
    printf("Hello world,My ID is: %u\n",getpid());
    sleep(5);
    exit(0);

}