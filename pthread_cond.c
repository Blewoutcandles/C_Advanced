#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

int fuel = 0;

void *fuelfilling(void *arg)
{
    while(1){
        for(int i = 0; i < 4; i++){
            pthread_mutex_lock(&mutex);
            fuel += 20;
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&cond);
            printf("Signalling done : %d with fuel : %d\n", i, fuel);
        }
            
        printf("Fuel filling is done: %d\n", fuel);
        sleep(2);
    }
    
    return NULL;
}

void *watingcars(void *arg)
{
    while(1){
        pthread_mutex_lock(&mutex);
        while(fuel < 40){
            pthread_cond_wait(&cond, &mutex);
            /*pthread_cond_wait Equivalent to pthread_mutex_unlock(&mutex) and 
            then block the thread until the condition variable is signaled. 
            Once the thread is unblocked, 
            it automatically re-acquires the mutex before returning from the function.
            */
        }
        fuel -= 40;
        pthread_mutex_unlock(&mutex);
        printf("Car is filled with fuel: %d\n", fuel);
        sleep(2);
    }

    return NULL;
}

int main()
{
    pthread_t thread1, thread2[2];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    
    pthread_create(&thread1, NULL, fuelfilling, NULL);
    sleep(2);
    for(int i = 0; i < 2; i++){
        pthread_create(&thread2[i], NULL, watingcars, NULL);
    }

    pthread_join(thread1, NULL);
    for(int i = 0; i < 2; i++){
        pthread_join(thread2[i], NULL);
    }

    return 0;
}