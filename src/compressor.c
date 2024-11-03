#include "../include/huffman.h"
#include "../include/file_utils.h"

void compress(const char *inputFile, const char *outputFile) {
    HuffmanTree huffmanTree;
    buildHuffmanTree(&huffmanTree, inputFile);
    
    // Read input file data (as a string)
    long inputSize;
    char *inputData = readFile(inputFile, &inputSize);
    
    // Allocate a buffer for the compressed data (size should be dynamic based on Huffman coding)
    char *compressedData = (char *)malloc(1024); // Placeholder for actual size
    // Perform compression logic to fill in compressedData (to be implemented)
    
    // Instead of keeping compressedSize unused, you might want to replace it
    // with logic to calculate the actual size of compressedData.
    
    snprintf(compressedData, 1024, "Compressed representation of: %s", inputData);
    
    // Write the compressed data to file
    writeCompressedFile(outputFile, compressedData);

    // Free allocated memory
    free(inputData);
    free(compressedData);
    freeTree(huffmanTree.root);
    free(huffmanTree.codes);
}