#include <stdio.h>
int main(){
    int* pc;
    int c;
    c = 22;
    printf("address of c:%d\n", &c);
    printf("value of c:%d\n", c);
    pc = &c;
    printf("address of pointer pc:%d\n", pc);
    printf("content of a pointer pc:%d", *pc);
    c = 11;
    printf("address of a pointer pc:%d\n",pc);
    printf("content of a pointer pc:%d\n",*pc);
    *pc = 2;
    printf("address of c:%d\n", &c);
    printf("value of c:%d\n", c);
    return 0;
}
