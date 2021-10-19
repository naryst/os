#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

const int MOD = 1<<9;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int *pageCounter = malloc(n*sizeof(int));
    int *isInTable = (int*)calloc(10000, sizeof(int));
    int *pageNumber = malloc(n*sizeof(int));

    for(int i=0; i<n; i++){
        pageCounter[i] = -1;
        pageNumber[i] = -1;
    }
    int currentTime = 1;
    int *R = malloc(n*sizeof(int));
    double hit = 0, miss = 0;
    for(int i = 0; i < m; i++){
        int page, time;
        scanf("%d %d",&time, &page);
        printf("%d\n", isInTable[page]);
        if(isInTable[page]) hit++;
        else if(!isInTable[page]) miss++;

        if(time != currentTime){
            for(int j = 0; j < n; j++){
                if(pageCounter[j] != -1) pageCounter[j] = ((R[j] << 7) + (pageCounter[j] >> 1)) % MOD;
                int a = pageCounter[j];
                R[j] = 0;
            }
            currentTime = time;
        }
        if(isInTable[page]){
            int id = -1;
            for(int j = 0; j < n; j++){
                if(pageNumber[j] == page){
                    id = j;
                }
            }
            R[id] = 1;
        }
        else if(!isInTable[page]){
            int free = 0;
            for(int k = 0; k < n; k++){
                if(pageCounter[k] == -1){
                    pageCounter[k] = 0;
                    pageNumber[k] = page;
                    isInTable[page] = 1;
                    free = 1;
                    R[k] = 1;
                    break;
                }
            }
            if(!free){
                int minCounter = MOD;
                int minPage = 1e6 + 1;
                int minID = n;
                for(int j = 0; j < n; j++){
                    if(pageCounter[j] < minCounter){
                        minCounter = pageCounter[j];
                        minPage = pageNumber[j];
                        minID = j;
                    }
                    if(pageCounter[j] == minCounter && pageNumber[j] < minPage){
                        minPage = pageNumber[j];
                        minID = j;
                    }
                }
                isInTable[minPage] = 0;
                pageNumber[minID] = page;
                pageCounter[minID] = 0;
                isInTable[page] = 1;
                R[minID] = 1;
            }
        }
    }
    double ans;
    if(miss == 0) ans = 1;
    else ans = hit/miss;
    printf("%.9lf\n", ans);
    printf("%f %f\n", hit, miss);
    return 0;
}
