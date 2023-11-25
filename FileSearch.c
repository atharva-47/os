#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void count(char *filename, char *pattern) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File %s not found.\n", filename);
        return;
    }

    int count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        char *found = strstr(line, pattern);
        while (found != NULL) {
            count++;
            found = strstr(found + 1, pattern);
        }
    }

    fclose(file);
    printf("Occurrences of '%s' in %s: %d\n", pattern, filename, count);
}

void search(char cmd, char *filename, char *pattern) {
    switch (cmd) {
        case 'f':
            // Display first occurrence of pattern in the file
            // Implement this functionality
            break;
        case 'a':
            // Search all occurrences of pattern in the file
            // Implement this functionality
            break;
        case 'c':
            // Count the number of occurrences of pattern in the file
            count(filename, pattern);
            break;
        default:
            printf("Invalid search command.\n");
            break;
    }
}

int main() {
    char buff[80];

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

        if (strcmp(args[0], "search") == 0 && i >= 4) {
            search(args[1][0], args[2], args[3]);
        } else {
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                if (execvp(args[0], args) == -1) {
                    perror("execvp");
                    exit(EXIT_FAILURE);
                }
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}

