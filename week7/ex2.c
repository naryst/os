#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main(){
    int N;
    printf("Plesse enter integer N parametr:\n");
    scanf("%d",&N);
    if(N < 0){
        printf("N should be > 0\n");
        return 1;
    }
    int *arr = malloc(N * sizeof(int));
    int t = 0;
    for(int i = 0; i < N; i++){
        arr[i] = t;
        t++;
    }
    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}