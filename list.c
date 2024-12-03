#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void list_files(const char *dir_name, int show_all) {
    struct dirent *entry;
    DIR *dp = opendir(dir_name);

    if (dp == NULL) {
        perror("Unable to read directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        // Show hidden files if -all is specified
        if (!show_all && entry->d_name[0] == '.') {
            continue;
        }

        // Print the filename
        printf("%s\n", entry->d_name);
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    int show_all = 0;  // Show hidden files (-all)

    if (argc == 1) {
        // Default to current directory if no arguments
        list_files(".", show_all);
    } else {
        // Parse the arguments
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-all") == 0) {
                show_all = 1;
            } else {
                // Handle directory argument
                list_files(argv[i], show_all);
            }
        }
    }

    return 0;
}

