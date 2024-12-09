#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
    const char *source_file = argv[1];
    const char *dest_file = argv[2];  
    FILE *source = fopen(source_file, "rb"); 
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }
    FILE *dest = fopen(dest_file, "wb");  
    if (dest == NULL) { 
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }
    char buffer[1024];
    size_t bytes;    
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, dest);  
    }
    printf("File copied successfully from '%s' to '%s'.\n", source_file, dest_file);

    fclose(source);
    fclose(dest);
    return 0;
}

