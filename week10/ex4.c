#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

void get_stat(char *path, char *fileName, struct stat *fileStat){
    char *localPath = (char*)malloc(256);
    strcpy(localPath, path);
    char *filePath = strcat(localPath, "/");
    filePath = strcat(filePath, fileName);
    stat(filePath, fileStat);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "please enter the directory you want to scan\n");
        exit(EXIT_FAILURE);
    }

    printf("File----Hard Links\n");

    char *dirName = argv[1];
    DIR *dir = opendir(dirName);
    struct dirent *dp;

    while ((dp = readdir (dir)) != NULL ) {
        struct stat fileStat;
        get_stat(dirName, dp->d_name, &fileStat);

        int counter = 0;

        struct dirent *dp1;
        DIR *dir1 = opendir(dirName);
        char *linkedFiles[256];

        while ((dp1 = readdir (dir1)) != NULL){
            struct stat fileStat1;
            get_stat(dirName, dp1->d_name, &fileStat1);
            if(fileStat1.st_ino == fileStat.st_ino){
                linkedFiles[counter] = dp1->d_name;
                counter++;
            }
        }

        closedir(dir1);
        if(counter > 1){
            printf("%s----", dp->d_name);
            for(int i = 0; i < counter; i++){
                printf("%s ", linkedFiles[i]);
            }
            printf("\n");
        }
    }
    closedir(dir);
    return 0;
}