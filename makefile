# Compiler settings for Linux
CC = gcc
CFLAGS = -Wall -g
TARGET = Reversi
OBJ = Reversi.o board.o check.o input.o move.o highscore.o
RM = rm -f

# Build target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compilation rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	$(RM) $(OBJ) $(TARGET)

.PHONY: all clean