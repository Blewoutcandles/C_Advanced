#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define SIZE 10
void *routine(void *arg){
    int *value = (int*)arg;
    for(int i = 0; i< SIZE; i++){
        printf("%d ", value[i]);
    }
    return NULL;
}

int main(){
    pthread_t thread1;
    int arr[SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    pthread_create(&thread1, NULL, routine, (void*)arr);
    pthread_join(thread1, NULL);
    return 0;
}