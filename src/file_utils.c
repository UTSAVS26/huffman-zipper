#include "../include/file_utils.h"

void writeCompressedFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);
}

char* readFile(const char *filename, long *fileSize) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    *fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char*)malloc(*fileSize + 1);
    fread(buffer, sizeof(char), *fileSize, file);
    buffer[*fileSize] = '\0'; // Null-terminate the string

    fclose(file);
    return buffer;
}