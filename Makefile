# Makefile for compiling the text-based adventure game

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=c99

# Source files
SRC = MyGame.c

# Output file
OUT = MyGame

# Default target
all: $(OUT)

# Link the object files and create the executable
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean up the compiled files
clean:
	rm -f $(OUT)
