#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *ar, int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            if(ar[j] > ar[j+1]){
                temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int* a = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    bubble_sort(a, n);
    for(int k = 0; k < n; k++){
        printf("%d ", a[k]);
    }
    printf("\n");
}