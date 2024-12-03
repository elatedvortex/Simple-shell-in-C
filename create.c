#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char *fileName = argv[1];
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error creating file");
        return 1;
    }
    printf("File '%s' created successfully.\n", fileName);
    fclose(file);
    return 0;
}

