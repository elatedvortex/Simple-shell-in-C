#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the directory name is provided
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Create a command to change the directory in the shell
    char command[1024];
    snprintf(command, sizeof(command), "cd %s && exec $SHELL", argv[1]);

    // Execute the command using system()
    if (system(command) == -1) {
        perror("Error executing command");
        return 1;
    }

    return 0;
}

