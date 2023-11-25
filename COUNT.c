#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void count(char *fn, char op) {
    FILE *file = fopen(fn, "r");
    if (file == NULL) {
        printf("File %s not found\n", fn);
        return;
    }

    int cc = 0, wc = 0, lc = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        cc++;

        if (c == ' ' || c == '\t' || c == '\n') {
            wc++;

            if (c == '\n')
                lc++;
        }
    }
    fclose(file);

    switch (op) {
    case 'c':
        printf("No. of Characters:%d\n", cc);
        break;
    case 'w':
        printf("No. of Words:%d\n", wc);
        break;
    case 'l':
        printf("No. of lines:%d\n", lc);
        break;
    }
}

int main() {
    char buff[80];

    while (1) {
        printf("myshell$");
        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = '\0';

        char *args[10];
        char *token = strtok(buff, " ");
        int i = 0;

        while (token != NULL && i < 9) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (strcmp(args[0], "count") == 0) {
            count(args[2], args[1][0]); // Changed "==" to "="
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










