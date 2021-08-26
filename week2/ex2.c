#include <stdio.h>
#include <string.h>
int main(){
    char buf[256];
    fgets(buf, sizeof(buf), stdin);
    int len = strlen(buf);
    for(int i = len-1; i >= 0; i--){
        printf("%c", buf[i]);
    }
    return 0;
}