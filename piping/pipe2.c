#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(){
    
    char buffer[256];
    int f1;
    sprintf(buffer,"This is the first output!\n\n");
    int fds[2];
    pipe(fds);
    printf("buffer 1: %s\n",buffer);

    f1 = fork();

    if(f1 < 0){
        perror("error in fork\n");
        exit(1);
    }else if(f1 == 0){
        printf("This is CHILD process\n");
        int child_pid = getpid();
        char buffer2[5];
        
        read(fds[0],&buffer2,5);
        close(fds[0]);
        printf("message : %s\n",buffer2);
        printf("CHILD report : my ID : %d\n",child_pid);
        int i;
        for(i=10;i>0;i--){
            printf("countdown :%d\n",i);
            sleep(1);
        }
    }else{
        int status;
        
        
        
        write(fds[1],"Hallo",5);
        close(fds[1]);
        
        printf("This is parent process.");
        printf("Parent report : my pid = %d child pid = %d\n",getpid(),f1);

        waitpid(-1,&status,0);
        if(WIFEXITED(status)){
            printf("Child has returned %u\n",WEXITSTATUS(status));
        }
    }

    exit(0);

}