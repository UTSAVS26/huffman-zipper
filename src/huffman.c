#include "../include/huffman.h"

Node* createNode(char character, int frequency) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Function to build the Huffman tree from a given file
void buildHuffmanTree(HuffmanTree *huffmanTree, const char *filename) {
    // Sample frequency array and characters, you need to implement the frequency calculation based on your input file
    char characters[] = {'a', 'b', 'c', 'd', 'e'};
    int frequencies[] = {5, 9, 12, 13, 16}; // Replace with actual frequency calculation

    int n = sizeof(frequencies) / sizeof(frequencies[0]);

    // Create nodes for each character
    Node **nodes = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(characters[i], frequencies[i]);
    }

    // TODO: Implement priority queue and build the Huffman tree

    // Assuming the tree is built and stored in huffmanTree->root
    huffmanTree->root = nodes[0]; // Placeholder
    huffmanTree->codes = (char**)malloc(n * sizeof(char*));

    char code[100]; // Adjust as necessary
    generateCodes(huffmanTree->root, code, 0, huffmanTree);

    free(nodes); // Free allocated nodes
}

// Generate Huffman codes for each character
void generateCodes(Node *root, char *code, int depth, HuffmanTree *huffmanTree) {
    if (root == NULL) return;

    // If this is a leaf node, store the code
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';  // Null-terminate the string
        huffmanTree->codes[(int)(root->character - 'a')] = strdup(code); // Assuming characters are 'a' to 'e'
        return;
    }

    // Traverse left
    code[depth] = '0';
    generateCodes(root->left, code, depth + 1, huffmanTree);

    // Traverse right
    code[depth] = '1';
    generateCodes(root->right, code, depth + 1, huffmanTree);
}

// Free memory for the Huffman tree
void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}