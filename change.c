#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (chdir(argv[1]) != 0) {
        perror("change failed");
        return EXIT_FAILURE;
    }
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd failed");
        return EXIT_FAILURE;
    }
    printf("Changed directory to: %s\n", cwd);
    return EXIT_SUCCESS;
}
