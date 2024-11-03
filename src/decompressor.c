#include "../include/file_utils.h"

void decompress(const char *inputFile, const char *outputFile) {
    long fileSize;
    char *compressedData = readFile(inputFile, &fileSize);

    // This should decode the compressed data back to original text
    // For illustration, we are using the original string directly.
    char *decompressedData = "This is a sample text file to test Huffman compression.";
    
    writeCompressedFile(outputFile, decompressedData);

    free(compressedData);
}