# Compiler and flags based on the operating system
ifeq ($(OS),Windows_NT)
    # Windows setup
    CC = cl
    CFLAGS = /W4 /EHsc  # Equivalent of -Wall for Windows, /EHsc for exception handling
    TARGET = Reversi.exe  # Windows executable has .exe extension
    RM = del /Q  # Command to remove files in Windows
else
    # Linux setup
    CC = gcc
    CFLAGS = -Wall -g
    TARGET = Reversi  # Linux executable doesn't have .exe
    RM = rm -f  # Command to remove files in Linux
endif

# Source and object files
SRC = Reversi.c board.c check.c input.c move.c
OBJ = $(SRC:.c=.o)  # Convert .c files to .o files

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	$(RM) $(OBJ) $(TARGET)

# Phony targets to prevent conflicts with filenames
.PHONY: all clean