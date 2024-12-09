#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *input = NULL;
    size_t size = 0;
    char *username = getenv("USER");

    while (1) {
        if (username) {
            printf("%s:$ ", username);
        } else {
            printf(":$ ");
        }

        if (getline(&input, &size, stdin) == -1) {
            perror("Error reading input");
            free(input);
            return 1;
        }

        input[strcspn(input, "\n")] = '\0'; 
        if (input[0] == '~') {
            char *home = getenv("HOME");
            if (home) {
                char *new_input = malloc(strlen(home) + strlen(input));
                if (new_input) {
                    strcpy(new_input, home);
                    strcat(new_input, input + 1); 
                    free(input);
                    input = new_input;
                }
            }
        }

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

            snprintf(path, sizeof(path), "./bin/%s", args[0]);

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

