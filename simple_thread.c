#include <linux/types.h>
#include <linux/time.h>
#include <stdio.h>
#include <pthread.h>
void *routine(void *arg){
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    printf("Time: %ld seconds and %ld nanoseconds\n:", ts.tv_sec, ts.tv_nsec);
    return NULL;
}
int main(){
    pthread_t thread1;
    pthread_create(&thread1, NULL, (void*) routine, NULL);
    pthread_join(thread1, NULL);
    return 0;
}