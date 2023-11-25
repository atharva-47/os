#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void typeline(char *filename, char op, int n_lines) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File %s not found.\n", filename);
        return;
    }

    char line[256];
    int line_count = 0;

    if (op == '+') {
        while (fgets(line, sizeof(line), file) && line_count < n_lines) {
            printf("%s", line);
            line_count++;
        }
    } else if (op == '-') {
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
    }

    fclose(file);
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

        if (strcmp(args[0], "typeline") == 0 && args[1] != NULL && args[2] != NULL) {
            if (args[1][0] == '+') {
                int n_lines = atoi(args[1] + 1); // Extracting the number after '+'
                typeline(args[2], '+', n_lines);
            } else if (args[1][0] == '-') {
                typeline(args[2], '-', 0); // Passing 0 to indicate printing all lines
            }
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

