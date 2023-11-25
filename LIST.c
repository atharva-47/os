#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void list_files(char *dirname, char op) {
    struct dirent *entry;
    DIR *dp;

    dp = opendir(dirname);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        struct stat file_stat;
        char path[100];
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        if (stat(path, &file_stat) == 0) {
            switch (op) {
                case 'f':
                    printf("%s\n", entry->d_name);
                    break;
                case 'n':
                    printf("%s\n", entry->d_name);
                    break;
                case 'i':
                    printf("Name: %s, Inode: %lu\n", entry->d_name, file_stat.st_ino);
                    break;
            }
        }
    }

    closedir(dp);
}

int main() {
    char buff[100];

    while (1) {
        printf("myshell$ ");
        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = '\0';  // Remove the trailing newline

        char *args[10];
        char *token = strtok(buff, " ");
        int i = 0;

        while (token != NULL && i < 9) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        if (strcmp(args[0], "list") == 0 && args[1] != NULL && args[2] != NULL) {
            list_files(args[2], args[1][0]);
        }
    }

    return 0;
}

