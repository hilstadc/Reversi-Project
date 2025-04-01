/*
    * Name: Cameron Hilstad
*/
#include <stdio.h>

void changeTile(int board[8][8], int tile[2]) {
    if (board[tile[0]][tile[1]] == 1) {
        board[tile[0]][tile[1]] = 2;
        printf("changed tile %d,%d from white to black",tile[0],tile[1]);
    } else if (board[tile[0]][tile[1]] == 2) {
        board[tile[0]][tile[1]] = 1;
        printf("changed tile %d,%d from black to white",tile[0],tile[1]);
    } else {
        printf("ERROR! Attempting to change blank space!");
    }
}

void move(int board[8][8], int head[2], int tail[2]) {
    int i, j;
    if (head[1] == tail[1]) {
        // up or down
        if (head[0] > tail[0]) {
            //up
            for (i = head[0]-1; i > tail[0]; i--) {
                changeTile(i,head[1]);
            }
        } else {
            //down
            for (i = head[0]+1; i < tail[0]; i++) {
                changeTile(i,head[1]);
            }
        }
    } else if (head[1] > tail[1]) {
        //left-something
        if (head[0] > tail[0]) {
            //up-left
            i = head[0]-1;
            for (j = head[1]-1; j > tail[1]; j--) {
                changeTile(i,j);
                i--;
            }
        } else if (head[0] < tail[0]) {
            //down-left
            i = head[0]+1;
            for (j = head[1]-1; j > tail[1]; j--) {
                changeTile(i,j);
                i++;
            }
        } else if (head[0] == tail[0]) {
            //left
            i = head[0];
            for (j = head[1]-1; j > tail[1]; j--) {
                changeTile(i,j);
            }
        } else {
            printf("ERROR: Tile is left but not left?");
        }
    } else if (head[0] > tail[0]) {
        //right-something
        if (head[0] > tail[0]) {
            //up-right
            i = head[0]-1;
            for (j = head[1]+1; j < tail[1]; j++) {
                changeTile(i,j);
                i--;
            }
        } else if (head[0] < tail[0]) {
            //down-right
            i = head[0]+1;
            for (j = head[1]+1; j < tail[1]; j++) {
                changeTile(i,j);
                i++;
            }
        } else if (head[0] == tail[0]) {
            //right
            i = head[0];
            for (j = head[1]+1; j < tail[1]; j++) {
                changeTile(i,j);
            }
        } else {
            printf("ERROR: Tile is right but not right?");
        }
    } else {
        printf("ERROR: tail not in any direction (same tile?)");
    }
}