#include <linux/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(){
    int pid = fork();
    printf("%d\n", pid);
    if(pid == 0){
        printf("Child process with pid: %d\n", getpid());
        printf("Parent process with pid: %d\n", getppid());
    }else{
        printf("Parent process with pid: %d\n", getpid());
    }
    /*the process has different memory spaces, so changes made in one process won't affect 
    the other */
    return 0;
}