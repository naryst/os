#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    while(1){
        char command[100];
        scanf("%[^\n]%*c", &command);
        system(command);
    }
    return 0;
}
