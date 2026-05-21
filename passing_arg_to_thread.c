#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define SIZE 6
int arr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
void *routine(void *arg){
    int index = *(int*)arg;
    printf("%d ", arr[index]);
    fflush(stdout);
    return NULL;
}

int main(){
    pthread_t thread[10];
    
    int i = 0;
    for(; i < SIZE; i++) {
        pthread_create(thread+i, NULL, routine, &i);
    }
    for(int j = 0; j < SIZE; j++) {
        pthread_join(thread[j], NULL);
    }
    printf("\n");
    
    return 0;
}