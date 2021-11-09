#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>

int main(){
    char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd = open(dev, O_RDONLY);
    char *events[2] = {"PRESSED", "RELEASED"};

    printf("press P + E if you want to get message I passed the Exam!\n");
    printf("press C + A + P if you want to get message Get some cappuccino!\n");
    printf("press O + S if you want to get message I love OS course!\n");

    int *pressedKeys = calloc(256, sizeof(int));
    if(fd < 0){
        EXIT_FAILURE;
    }
    else{
        while(1){
            struct input_event currentEvt;
            read(fd, &currentEvt, sizeof(currentEvt));

            if(currentEvt.type == 1 && currentEvt.value != 0){
                pressedKeys[currentEvt.code] = 1;
            }

            if(currentEvt.type == 1 && currentEvt.value == 0){
                pressedKeys[currentEvt.code] = 0;
            }

            if(pressedKeys[25] != 0 && pressedKeys[18] != 0){
                printf("I passed the Exam!\n");
                pressedKeys[25] = 0;
                pressedKeys[18] = 0;
            }

            if(pressedKeys[46] &&  pressedKeys[30] &&  pressedKeys[25]){
                printf("Get some cappuccino!\n");
                pressedKeys[46] = 0;
                pressedKeys[30] = 0;
                pressedKeys[25] = 0;
            }

            if(pressedKeys[24] != 0 && pressedKeys[31] != 0){
                printf("I love OS course!\n");
                pressedKeys[24] = 0;
                pressedKeys[31] = 0;
            }          
        }
    }
    return 0;
}