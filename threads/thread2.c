#include <stido.h>
#include <pthred.h>

void *PrintHello(void *threadid){

	long tid;
	tid= (long)threadid;
	sleep(1);
	printf("Hallo, ich bin Thread: %l",tid);
}

int main(){
	//threads(multithreading)	
	//Anwendungen müssen mehrere Aufgaben gleichzeitig ausführen.
	//pthread_create :  Der Befehl wird für die Erzeugung von Thread genutzt.
	//pthread_exit : wird für die Terminierung von Thread benutzt.
	//pthread_join : Thread wartet auf die Terminierung von Thread
	//pthread_self : für die Nahme der Threadkennung(TID) von aktuellem Thread
	//pthread_equal : vergleicht 2 Threads miteinander, ob sie gleich sind oder nicht.Wenn sie gleich sind, dann wird non-zero-value ,sonst 0.
	//pthread_cancel : für das Schicken von cancellation  zu Thread
	//pthread_detach :  bir diziyi ayırmak için kullanılır. Ayrılmış iş parçacığı sonlandırıldığında bir iş parçacığının katılmasını gerektirmez. Thredler in kaynakları iş parçacığının ayrılması durumunda sonlandırıldıktan soonra otomatik olarak serbest bırakılır.

	long t;
	int wieviel;

	printf("Wie viel Thread möchten Sie ?\n");
	scanf("%d",wieviel);
	pthread_t threads[wieviel];

	printf("Ich erstelle %d Threads ",wieviel);

	for(t = 0;t<wieviel;t++){
		pthread_creat(&threads[t],NULL,&PrintHello,(void *)t);
		pthread_join(pthread_self(),NULL);
	}

	printf("Hauptprogramm: Fertig\n");
	pthread_exit(NULL);

	
}
