#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { 
        fprintf(stderr, "Usage: %s <folder_name>\n", argv[0]);
        return 1;}
    const char *folder_name = argv[1];
    int result = mkdir(folder_name, 0755);
    if (result == 0) {
        printf("Folder '%s' created successfully.\n", folder_name);
    } else {
        perror("Error creating folder");
    }
    return 0;
}

