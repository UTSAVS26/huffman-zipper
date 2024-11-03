#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *root;
    char **codes; // Array of codes for characters
    int size; // Size of the codes array
} HuffmanTree;

// Function prototypes
Node* createNode(char character, int frequency);
void buildHuffmanTree(HuffmanTree *huffmanTree, const char *filename);
void generateCodes(Node *root, char *code, int depth, HuffmanTree *huffmanTree);
void freeTree(Node *root);
void compress(const char *inputFile, const char *outputFile);
void decompress(const char *inputFile, const char *outputFile);

#endif // HUFFMAN_H