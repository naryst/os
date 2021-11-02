#include <stdio.h>
#include <dirent.h>
  
int main()
{
    struct dirent *de; 

    DIR *dr = opendir("/");
  
    while ((de = readdir(dr)) != NULL)
            printf("%s ", de->d_name);
  
    closedir(dr);    
    printf("\n");
    return 0;
}
