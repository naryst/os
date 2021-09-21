#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "string.h"
#include <stdlib.h>

#define bufferSize 8 // max size of the buffer

// enumerator type to determine type of the thread
enum type{
    PRODUCER,
    CONSUMER
} typedef type;

int producerSleep = 0;
int consumerSleep = 0;
int counter = 0;
int buffer[bufferSize];

void sleepProcess(type t){ 
    if(t == PRODUCER){
        producerSleep = 1;
    }
    if(t == CONSUMER){
        consumerSleep = 1;
    }
}


void wakeUpProcess(type t){
    if(t == PRODUCER){
        producerSleep = 0;
    }
    if(t == CONSUMER){
        consumerSleep = 0;
    }
}

int data = 3;

void *producer(){
    while(1){
        printf("producer is working\n");
        if(counter == bufferSize){
            sleepProcess(PRODUCER);
        }
        if(producerSleep == 0){
            buffer[counter]  = data; //initializing new element of buffer with data
            counter++; //increasing counter for the eleemnts of the buffer
            if(counter > 0){
                wakeUpProcess(CONSUMER); // wakeup consumer if buffer is nonemty
            }
        }
    }
}

void *consumer(){
    while(1){
        if(counter < 0 || counter > bufferSize){
            printf("ЕБАНАТ\n");
            exit(1);
        }
        printf("consumer is working\n");
        if(counter == 0){
            sleepProcess(CONSUMER);
        }
        if(consumerSleep == 0){
            buffer[counter] = 0; //remove data from the last element of the buffer
            //sleep(0.01); // sleep for 10ms to this thread to meet race condition
            counter--; // decreasing counter for the eleemnts of the buffer
            if(counter < bufferSize){
                wakeUpProcess(PRODUCER);
            }
        }
    }
}

int main(){
    pthread_t consumerThread;
    pthread_t producerThread;
    pthread_create(&consumerThread, NULL, *consumer, NULL);
    pthread_create(&producerThread, NULL, *producer, NULL);
    pthread_exit(NULL);
    return 0;
}