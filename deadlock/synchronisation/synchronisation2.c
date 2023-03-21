#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> 

pthread_t tid[2];
int counter;// globale int variable
pthread_mutex_t lock[2];

void * func1(void * arg){
    pthread_mutex_lock(&lock[0]); //Der kritische Bereich ist gesperrt
    sleep(1);
    pthread_mutex_lock(&lock[1]);
    counter++;
    printf("Thread %d started!\n",counter);
    
    printf("Thread %d finished!\n",counter);
    pthread_mutex_unlock(&lock[1]);
    pthread_mutex_unlock(&lock[0]); //Der kritische Bereich ist ausgesperrt

}


void * func2(void * arg){
    pthread_mutex_lock(&lock[1]); //Der kritische Bereich ist gesperrt
    sleep(1);
    pthread_mutex_lock(&lock[0]);
    counter++;
    printf("Thread %d started!\n",counter);
    
    printf("Thread %d finished!\n",counter);
    pthread_mutex_unlock(&lock[0]);
    pthread_mutex_unlock(&lock[1]); //Der kritische Bereich ist ausgesperrt

}

int main(){

    if(pthread_mutex_init(&lock[1],NULL)< 0 && pthread_mutex_init(&lock[1],NULL)< 0){// lock initialisieren
        printf("Error in mutex");
        exit(1);
    }

    int i;
    
        pthread_create(&tid[0],NULL,&func1,NULL);
        pthread_create(&tid[1],NULL,&func2,NULL);
        printf("Thread are getting created\n");
    

    for(i=0 ; i< 2 ; i++){
        pthread_join(tid[i],NULL);
    }
    printf("Tyyyy");
    pthread_mutex_destroy(&lock[0]);
    pthread_mutex_destroy(&lock[1]);
    exit(0);
}