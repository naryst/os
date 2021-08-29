#include <stdio.h>

int main(int argc, char **argv){
    if(argc == 1){
        printf("you did not specify number of lines\n");
    }
    char *s = argv[1];
    int n;
    sscanf(s, "%d", &n);
    int tabs = n-1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < tabs; j++) printf(" ");
        tabs--;
        for(int j = 0; j < 2*i - 1; j++) printf("*");
        printf("\n");
    }
}