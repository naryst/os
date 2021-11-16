#include <stdio.h>
#include <malloc.h>

int main(){

    FILE *f = fopen("input.txt", "r");
    int n = 3, m = 5;

    int *E = malloc(m * sizeof(int));
    int *A = malloc(m * sizeof(int));
    int (*R)[n] = malloc(sizeof(int[m][n]));
    int (*C)[n] = malloc(sizeof(int[m][n]));

    for(int i = 0; i < n; i++){
        fscanf(f, "%d", &E[i]);
    }

    for(int i = 0; i < n; i++){
        fscanf(f, "%d", &A[i]);
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            fscanf(f, "%d", &C[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            fscanf(f, "%d", &R[i][j]);
        }
    }

    int *deadLock = calloc(0, m * sizeof(int));

    for(int k = 0; k < m; k++){
        for(int i = 0; i < m; i++){
            int ok = 1;
            for(int j = 0; j < n ; j++){
                if(A[j] - R[i][j] < 0) ok = 0;
            }
            if(ok != 0) for(int j = 0; j < n; j++){
                A[j] += C[i][j];
                R[i][j] = 0;
                deadLock[i] = 0;
            }
            else if(ok == 0){
                deadLock[i] = 1;
            }
        }
    }
    int deadLockNumber = 0;
    for(int i = 0; i < m; i++){
        if(deadLock[i] == 1) deadLockNumber++;
    }
    if(deadLockNumber == 0){
        printf("Where is no deadLock\n");
    }
    else{
        printf("Algorithm detected %d deadLock\n", deadLockNumber);
    }
    return 0;
}