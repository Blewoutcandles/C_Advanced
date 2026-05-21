#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *routine(void *arg){
    int *value = (int*)arg;
    printf("This thread id is: %lu\n" , pthread_self());
    printf("The process id : %d, invoking thread no: %d\n", getpid(), *value);
    return NULL;
}

int main(){
    pthread_t thread1, thread2;
    int invoking_thread = 1;
    pthread_create(&thread1, NULL, routine, &invoking_thread);
    sleep(2);
    invoking_thread = 2;
    pthread_create(&thread2, NULL, routine, &invoking_thread);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
