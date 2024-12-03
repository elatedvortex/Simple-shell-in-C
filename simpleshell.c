#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *input = NULL;
    size_t size = 0;

    while (1) {
        printf(":$ "); 

        if (getline(&input, &size, stdin) == -1) {
            perror("Error reading input");
            free(input);
            return 1;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell.\n");
            break;
        }
        char *args[100];
        char *token = strtok(input, " ");
        int i = 0;

        while (token != NULL && i < 99) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid_t pid = fork();
        if (pid == -1) {
            perror("Error creating process");
        } else if (pid == 0) {
            char path[200];

            snprintf(path, sizeof(path), "./%s", args[0]);

            if (execvp(path, args) == -1) {
                perror("Error executing command");
            }
            exit(1); 
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    free(input);
    return 0;
}

