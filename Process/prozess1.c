#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	//fork() create a child process. Falls der Wert von fork() kleiner als 0 ist , dann konnte der CHILD-Prozess nicht erzeugt werden. Wenn der Wert von fork() größer als 0 ist ,dann wird er zum Parent Prozess geschickt.
	// Ist der Wert von fork() gleich 0 ist , dann sind wir im Child Prozess. 
	//wait , der aktuell laufende Prozess wird suspendiert und wartet darauf, bis der CHILD-Prozess terminiert wird.
	// waitpid(), der aktuell laufende Prozess wird suspendiert und wartet auf  die Veränderung des Zustands des CHILD-Prozesses bei pid
	pid_t pid = fork();
	pid_t w;
	int status;

	if(pid < 0){
		printf("failed\n");
	}else if(pid == 0){
		printf("This is Child process\n");
		printf("Child process reported : My ID : %d\n",getpid());

		int i;
		for(i = 10;i>=0;i--){
			printf("countdown: %d\n",i);
			sleep(1);
		
		}
		
	}else{
		sleep(5);
		printf("This is the parent process\n");
		printf("Parent process reported : My ID : %d and CHILD PID : %d\n",getpid(),pid);
		//wait(int *status)

		do{
			w = waitpid(pid,&status,0);
			if(w==-1){
				printf("error waitpid");
				exit(EXIT_FAILURE);
			}
			if(WIFEXITED(status)){
				printf("Child process terminated. status %d\n : %d",WEXITSTATUS(status));
			}else if(WIFSIGNALED(status)){
				printf("Killed by sigmal %d\n",WTERMSIG(status));
			}else if(WIFSTOPPED(status)){
				printf("stopped by signal %d\n",WSTOPSIG(status));
			}
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
		exit(EXIT_SUCCESS);
		
	}



	return 0;
}
