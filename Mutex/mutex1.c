#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif

//synchronisation Fehler und das Programm erzeugt nicht die richtige Antwort
int shared = 0;
//pthread_mutex_t mutex;

void *tueWas(void * threadId){
   // pthread_mutex_lock(&mutex);
   
    long id ;
    id =  (long)threadId;
    printf("Die gemeinsame Variable wird inkrementiert...\n");
    for(int i = 0; i <(int)(id+1)*10000;++i){
        shared += 1;
        
    }
    printf("Die gemeinsame Variable ist %d\n",shared);
   // pthread_mutex_unlock(&mutex);
    return 0;
    
   
}


int main(){
    pthread_t threads[NUM_THREADS];
    
  /*  if(pthread_mutex_init(&mutex,NULL)< 0){
        printf("Error");
    }*/

    for(int i = 0; i < NUM_THREADS; ++i){
        long j = i;
        pthread_create(&threads[i],NULL,&tueWas,(void*)j);
    }

    for(int i = 0; i< NUM_THREADS; ++i){
        pthread_join(threads[i],NULL);
    }

    /*pthread_mutex_destroy(&mutex);*/
    printf("%d\n",shared);
    exit(EXIT_SUCCESS);
}
