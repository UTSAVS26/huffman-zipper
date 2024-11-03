#include "../include/huffman.h"
#include "../include/file_utils.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <compress|decompress> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0) {
        compress(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress(argv[2], argv[3]);
    } else {
        printf("Invalid action. Use 'compress' or 'decompress'.\n");
        return 1;
    }

    return 0;
}