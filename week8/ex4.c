#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int duration = 10;
    size_t space = 1024 * 1024 * 1024;

    for (int i = 0; i < duration; i++) {
        int* array = (int*) malloc(space);
        memset(array, 0, space);
        struct rusage usage;
        int who = RUSAGE_SELF;
        getrusage(who, &usage);
        printf("%ld\n", usage.ru_maxrss);
        sleep(1);
    }
}