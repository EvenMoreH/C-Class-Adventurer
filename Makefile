# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Wextra -pedantic
# Source files
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
# Object files
OBJ_DIR = build
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# Executable
EXEC = $(OBJ_DIR)/alpha_C_Class
# Default target
all: $(EXEC)
# Link the object files to create the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^
# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
# Clean target to remove generated files
clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC)
# Phony targets
.PHONY: all clean