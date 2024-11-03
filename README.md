# Huffman Zip: A File Compression Tool using Huffman Coding

## Table of Contents
- [Overview](#overview)
- [Huffman Coding](#huffman-coding)
  - [What is Huffman Coding?](#what-is-huffman-coding)
  - [How Huffman Coding Works](#how-huffman-coding-works)
  - [Example of Huffman Coding](#example-of-huffman-coding)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Folder Structure](#folder-structure)
- [Usage](#usage)
  - [Compressing a File](#compressing-a-file)
  - [Decompressing a File](#decompressing-a-file)
- [File Descriptions](#file-descriptions)
- [License](#license)

## Overview
Huffman Zip is a simple file compression tool that utilizes Huffman coding algorithms to compress and decompress text files. This project serves as an educational example of how Huffman coding works and how it can be implemented in C.

## Huffman Coding

### What is Huffman Coding?
Huffman coding is a popular algorithm used for lossless data compression. It assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters. This results in a more efficient representation of the data, which reduces file size.

### How Huffman Coding Works
1. **Frequency Count**: Count the frequency of each character in the input data.
2. **Build a Priority Queue**: Create a priority queue (or min-heap) of nodes, where each node represents a character and its frequency.
3. **Construct the Huffman Tree**:
   - While there is more than one node in the queue:
     - Remove the two nodes with the lowest frequency.
     - Create a new internal node with these two nodes as children and a frequency equal to the sum of their frequencies.
     - Add the new node back to the priority queue.
4. **Generate Codes**: Traverse the Huffman tree to assign binary codes to each character. A left branch indicates a `0`, and a right branch indicates a `1`.
5. **Encode Data**: Replace each character in the input data with its corresponding Huffman code to create the compressed data.
6. **Store the Huffman Tree**: To decompress the data later, the Huffman tree must be stored or transmitted alongside the compressed data.

### Example of Huffman Coding
Let's take a simple example using the string `ABRACADABRA`.

1. **Frequency Count**:
   - `A: 5`
   - `B: 2`
   - `R: 2`
   - `C: 1`
   - `D: 1`

2. **Build the Priority Queue**: 
   - Initially, we have the nodes: `A(5), B(2), R(2), C(1), D(1)`.

3. **Construct the Huffman Tree**:
   - Combine `C(1)` and `D(1)` → Create node `CD(2)`.
   - Combine `B(2)` and `R(2)` → Create node `BR(4)`.
   - Combine `CD(2)` and `B(2)` → Create node `CDBR(6)`.
   - Finally, combine `A(5)` and `CDBR(6)` → Create the root node `A CDBR(11)`.

4. **Generate Codes**:
   - Assign codes as follows:
     - `A: 0`
     - `B: 101`
     - `R: 100`
     - `C: 1110`
     - `D: 1111`

5. **Encode Data**:
   - `ABRACADABRA` becomes `0101101001110110010110100`.

6. **Store the Tree**:
   - The tree structure or a way to recreate it needs to be saved alongside the compressed data for decompression.

## Features
- Compress text files using Huffman coding.
- Decompress previously compressed files back to their original format.
- Demonstrates the creation and traversal of a Huffman tree.

## Getting Started

### Prerequisites
- A C compiler (e.g., GCC)
- Make utility for building the project
- Basic understanding of command-line operations

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/UTSAVS26/huffman-zipper.git
   cd huffman-zipper
   ```

2. Compile the project using the `make` command:
   ```bash
   make
   ```

### Folder Structure
The project folder contains the following structure:
```
huffman-zipper/
│
├── include/               # Header files
│   ├── file_utils.h       # Utility functions for file handling
│   └── huffman.h          # Huffman coding structures and function prototypes
│
├── src/                   # Source files
│   ├── compressor.c       # File compression logic
│   ├── decompressor.c     # File decompression logic
│   ├── file_utils.c       # Implementation of file utility functions
│   ├── huffman.c          # Implementation of Huffman coding logic
│   └── main.c             # Entry point for the program
│
├── Makefile               # Build script
└── README.md              # Project documentation
```

## Usage

### Compressing a File
To compress a text file, use the following command:
```bash
./huffman_zip compress <input_file> <output_file>
```
For example:
```bash
./huffman_zip compress input.txt compressed.bin
```

### Decompressing a File
To decompress a previously compressed file, use the following command:
```bash
./huffman_zip decompress <input_file> <output_file>
```
For example:
```bash
./huffman_zip decompress compressed.bin decompressed.txt
```

## File Descriptions
- `huffman.h`: Contains definitions for the data structures used in Huffman coding, including the node structure and function prototypes.
- `file_utils.h`: Header for utility functions that handle file reading and writing.
- `compressor.c`: Implements the file compression logic using Huffman coding.
- `decompressor.c`: Implements the file decompression logic.
- `file_utils.c`: Implements functions for file I/O operations.
- `huffman.c`: Contains functions for building the Huffman tree and generating Huffman codes.
- `main.c`: The entry point of the application, handling user input and invoking compression/decompression functions.

## License
This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details.