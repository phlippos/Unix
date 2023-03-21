#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;

void *function1() {
    pthread_mutex_lock(&first_mutex); // to acquire the resource/mutex lock
    printf("Thread ONE hat first_mutex\n");
    
    pthread_mutex_lock(&second_mutex);
    printf("Thread ONE hat second_mutex\n");
    printf("Thread ONE ist suspend\n");
    //sleep(1);
    
    pthread_mutex_unlock(&second_mutex); // to release the resource
    printf("Thread ONE hat freigegeben: second_mutex\n");
    pthread_mutex_unlock(&first_mutex);
    printf("Thread ONE hat freigegeben: first_mutex\n");
}

void *function2() {
    sleep(1);
    pthread_mutex_lock(&second_mutex);
    printf("Thread TWO hat second_mutex\n");
    
    pthread_mutex_lock(&first_mutex);
    printf("Thread TWO hat first_mutex\n");
    printf("Thread TWO ist suspend\n");
    // sleep(1);
    pthread_mutex_unlock(&first_mutex);
    printf("Thread TWO hat freigegeben: first_mutex\n");
    pthread_mutex_unlock(&second_mutex);
    printf("Thread TWO hat freigegeben: second_mutex\n");
}

int main() {
    pthread_mutex_init(&first_mutex,NULL); //initialize the lock
    pthread_mutex_init(&second_mutex,NULL);
    pthread_t one, two;
    pthread_create(&one, NULL, function1, NULL); // create thread
    pthread_create(&two, NULL, function2, NULL);
    pthread_join(one, NULL);
    pthread_join(two, NULL);
    printf("Threads gemerged\n");
   // pthread_mutex_destroy(&first_mutex);
   // pthread_mutex_destroy(&second_mutex);
    return 0;
}