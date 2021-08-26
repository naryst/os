#include <stdio.h>

void swap (int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main(int argc, char **argv){
    printf("Enter 2 integers ");
    int n, m;
    scanf("%d %d", &n, &m);
    swap(&n, &m);
    printf("Swapped integers: %d %d", n, m);
}