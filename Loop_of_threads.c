#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;
/*to statically initialize the mutex use PTHREAD_MUTEX_INITIALIZER
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;*/
void *routine(void *arg)
{
    for(int i = 0; i<1000000; i++) {
        pthread_mutex_lock(&mutex);
        ++mails;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t thread[4];
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i<4; i++) {
        if(pthread_create(thread+i, NULL, routine, NULL) != 0) {
            perror("Failed to create thread");
        }
        printf("Thread %d created\n", i);
    }
    for(int i = 0; i<4; i++) {
        if(pthread_join(thread[i], NULL) != 0) {
            perror("Failed to join thread");
        }
        printf("Thread %d finished\n", i);
        printf("Mails: %d\n after thread %d completion\n", mails, i);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}