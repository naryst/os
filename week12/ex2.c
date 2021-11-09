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
    if(fd < 0){
        EXIT_FAILURE;
    }
    else{
        while(1){
            struct input_event evt;
            read(fd, &evt, sizeof(evt));
            if(evt.type == 1) printf("%s 0x%04x (%d)\n", events[evt.value], evt.code, evt.code);
        }
    }
    return 0;
}