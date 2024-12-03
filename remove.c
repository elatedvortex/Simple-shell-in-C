#include <stdio.h>

int main(int argc, char *argv[]) {
    // Check if the file name argument is provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Get the file name from the command-line argument
    char *fileName = argv[1];

    // Attempt to remove the file
    if (remove(fileName) == 0) {
        printf("File '%s' removed successfully.\n", fileName);
    } else {
        perror("Error removing file");
        return 1;
    }

    return 0;
}

