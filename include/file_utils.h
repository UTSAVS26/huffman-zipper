#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeCompressedFile(const char *filename, const char *data);
char* readFile(const char *filename, long *fileSize);

#endif // FILE_UTILS_H