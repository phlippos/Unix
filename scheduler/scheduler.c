#include <stdio.h>
#include <stdlib.h>
#include <linux/sched.h>
#include <sched.h>
#include <unistd.h>
#include <string.h>
#include <sys/syscall.h>
#include <stdint.h>
#include <errno.h>
extern int errno;
/*
[AUFGABE] Alle Header-Dateien müssen hinzugefügt werden, um die folgenden Funktionen/Typen
zu unterstützen:
printf, memset, syscall, atoi, uint64_t.
*/
// Definiert in sched_setattr(2)
struct sched_attr {
uint32_t size; // Size of this structure
uint32_t sched_policy; // Policy (SCHED_*)
uint64_t sched_flags; // Flags
int32_t sched_nice; // Nice value (SCHED_OTHER, SCHED_BATCH)
uint32_t sched_priority; // Static priority (SCHED_FIFO, SCHED_RR)
// Die restlichen Felder sind für SCHED_DEADLINE
uint64_t sched_runtime;
uint64_t sched_deadline;
uint64_t sched_period;
};

int main (int argc, char *argv[])
{
    if(argc != 4){
        printf("Fehler bei command line Argument\n");
        exit(1);
    }
    struct sched_param param;
    struct sched_attr attributes;
    int returnVal;
    int pid;
    int runtime;
    int period;
    int x;
    // [AUFGABE] Arguments parsen
    runtime = atoi(argv[1]);
    period = atoi(argv[2]);
    pid = atoi(argv[3]);

    printf("pid is: %d\n", pid);
    printf("runtime is: %d\n", runtime);
    printf("pid period is: %d\n", period);
    printf("--- Scheduling Policy Changer v1 ---\n");
    printf("trying to change scheduling policy of PID: %i\n", pid);
    memset(&attributes, 0, sizeof(struct sched_attr)); // alle Komponenten-Werte der
    //"sched_attr"-Variable werden auf 0 gesetzt
    if (runtime == period) {
    // [AUFGABE] policy -> SCHED_OTHER
        attributes.sched_policy = SCHED_OTHER;
    }
    else {
    // [AUFGABE] policy -> SCHED_DEADLINE
    // [AUFGABE] muss auch runtime, deadline und period gesetzt werden
        attributes.sched_policy=SCHED_DEADLINE;
        attributes.sched_runtime = runtime;
        attributes.sched_deadline = period;
        attributes.sched_period = period;      
    }
    x= syscall(SYS_sched_setattr,pid,&attributes,0);
    printf("Rückgabewert von syscall = %d\n",x);
    // [AUFGABE] Rückgabe-Wert von syscall
    if(x == -1){
        printf("FehlerNr ist %d\n",errno);
        fprintf(stderr,"Fehler :  %s\n",strerror(errno));
        exit(1);
    }
    // [AUFGABE] FehlerNr, falls syscall nicht erfolgreich ist.

    syscall(SYS_sched_getattr,pid,&attributes,sizeof(attributes),0);
    if(attributes.sched_policy ==SCHED_DEADLINE)
        printf("policy : deadline");
    else
        printf("policy : other ");
    
    return(0);
}