CC = gcc
CFLAGS = -Wall -I include
OBJ_DIR = obj
SRC_DIR = src
OBJ = $(OBJ_DIR)/huffman.o $(OBJ_DIR)/file_utils.o $(OBJ_DIR)/compressor.o $(OBJ_DIR)/decompressor.o $(OBJ_DIR)/main.o

# Create the target executable
huffman_zip: $(OBJ)
	$(CC) $(CFLAGS) -o huffman_zip $(OBJ)

# Rule to create object files in the obj directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  # Ensure the object directory exists
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ_DIR)/*.o huffman_zip