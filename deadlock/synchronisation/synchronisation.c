#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> 

pthread_t tid[2];
int counter;// globale int variable
pthread_mutex_t lock;

void * func1(void * arg){
    pthread_mutex_lock(&lock); //Der kritische Bereich ist gesperrt

    counter ++;
    printf("Thread %d started!\n",counter);
    sleep(5);
    printf("Thread %d finished!\n",counter);

    pthread_mutex_unlock(&lock); //Der kritische Bereich ist ausgesperrt

}

int main(){

    if(pthread_mutex_init(&lock,NULL)< 0){// lock initialisieren
        printf("Error in mutex");
        exit(1);
    }

    int i;
    for(i = 0; i<2;i++){
        pthread_create(&tid[i],NULL,&func1,NULL);
        printf("Thread %d is getting created\n",i+1);
    }

    for(i=0 ; i< 2 ; i++){
        pthread_join(tid[i],NULL);
    }
    
    pthread_mutex_destroy(&lock);
    exit(0);
}