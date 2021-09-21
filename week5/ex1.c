#include<stdio.h>
#include <pthread.h>

void* jobF(void* args){
    int *n = (int*) args;
    printf("Hello form thread %d\n", *n);
    return NULL;
}

int main(){
    pthread_t thread;
    printf("Enter some number for n:\n");
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        if(pthread_create(&thread, NULL, *jobF, &i)){
            printf("thread cannot be created\n");
            pthread_exit(NULL);
        }
        else{
            printf("Thread was created\n");
        }
       //command for strict order of output
       pthread_join(thread, NULL);
    }

    printf("Hello form the main thread\n", n);
}