#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/syscall.h>
extern int errno;

int main(){
    struct sched_param param;
    pid_t pid;
    pid = getpid();
    printf("%u\n",pid);
    param.sched_priority = sched_get_priority_max(SCHED_FIFO);

    if(sched_setscheduler(pid,SCHED_FIFO,&param)==-1){
        fprintf(stderr,"Error : %s",strerror(errno));
        exit(0);
    }

    if(sched_getscheduler(pid)== SCHED_OTHER){
        printf("Scheduling policy: Other scheduler\n");
    }
    
    else if(sched_getscheduler(pid)== SCHED_FIFO){
        printf("Scheduling policy: FIFO");
    }
    
    return 0;
}