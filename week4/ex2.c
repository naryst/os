#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid1 = fork();
    pid_t pid2 = fork();
    pid_t pid3 = fork();
    pid_t pid4 = fork();
    pid_t pid5 = fork();
    sleep(500);
    return 0;
}
/* pstree for this task will look like
ex2─┬─ex2─┬─ex2───ex2
    │     └─ex2
    ├─ex2───ex2
    └─ex2
in total we created 8 processes
for the 5 froks we will have pstree
ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
    │     │     │     └─ex2
    │     │     ├─ex2───ex2
    │     │     └─ex2
    │     ├─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2───ex2
    │     └─ex2
    ├─ex2───ex2
    └─ex2
was created 32 processes
so we can conclude that number of created processes is equal to
2^n where n is number of forks()
*/