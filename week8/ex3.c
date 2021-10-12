#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <unistd.h>

int main() {
    int DURATION = 10;
    size_t space = 1024 * 1024 * 1024;

    for (int i = 0; i < DURATION; i++) {
        int* array = (int*) malloc(space);
        memset(array, 0, space);
        free(array);
        sleep(1);
    }
}
//while running res parameter takes value appximatly 1gb
//cpu% takes value from 20 to 30
//mem% takes value from 2.5 to 5.5
//virt is constantly 2364