#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <old_name> <new_name>\n", argv[0]);
        return 1;
    }
    char *oldName = argv[1];
    char *newName = argv[2];
    if (rename(oldName, newName) == 0) {
        printf("File renamed successfully from '%s' to '%s'.\n", oldName, newName);
    } else {
        perror("Error renaming file");
        return 1;
    }
    return 0;
}

