#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int n;
    n = fork();
    if(n == 0){
        printf("hello from the child [%d - %d]\n", getpid(), n);
    }
    else{
        wait(NULL);
        printf("hello from the parent [%d - %d]\n", getpid(), n);
    }
    return 0;
}

// fork()  value of the child process is 0, as child proccess
// starts working after fork command and dont call it
// fork() of the parent proccess is equal to the getpid() of the child
// process as fork() of the parent creates the child process