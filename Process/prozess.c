#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	//fork() create a child process. Falls der Wert von fork() kleiner als 0 ist , dann konnte der CHILD-Prozess nicht erzeugt werden. Wenn der Wert von fork() größer als 0 ist ,dann wird er zum Parent Prozess geschickt.
	// Ist der Wert von fork() gleich 0 ist , dann sind wir im Child Prozess. 

	pid_t pid = fork();
	
	if(pid < 0){
		printf("Failed !\n");
	}else if(pid == 0){
		printf("This is CHILD-process\n");
	}else{
		printf("This is PARENT-process\n");
	}

	return 0;
}
