#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int i = 0;
void *routine(void *arg){
    int *value = (int*) malloc(sizeof(int));
    for(; i< 1000000; i++);
    *value = i;
    printf("Address of return_from_thread: %p\n", value);
    return value;
}

int main(){
    pthread_t thread1, thread2;
    void *return_from_thread;
    pthread_create(&thread1, NULL, routine, NULL);
    pthread_join(thread1, &return_from_thread);
    printf("Value of returned value from thread 1: %d \n", *(int*)return_from_thread);
    printf("Address of return_from_thread: %p\n", return_from_thread);
    free(return_from_thread);
    return 0;
}