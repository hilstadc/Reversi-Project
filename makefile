CC = cl
CFLAGS = /W4 /EHsc
TARGET = Reversi.exe
SRC = Reversi.c board.c check.c input.c move.c highscore.c
OBJ = Reversi.obj board.obj check.obj input.obj move.obj highscore.obj

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) /Fe$(TARGET)

# Compile each .c file into a .obj file
.c.obj:
	$(CC) $(CFLAGS) /c $<

clean:
	del /Q $(OBJ) $(TARGET)
