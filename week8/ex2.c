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
        sleep(1);
    }
}
//while running program si may be 0 and
//may take value in range of from 100 to 1000
//so remains 0 anytime 