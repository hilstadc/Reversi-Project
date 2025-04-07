/*
    * Name: Cameron Hilstad
*/
#include <stdio.h>
#include "move.h"

void changeTile(int board[8][8], int tile[2]) {
    // if black, make white; if white, make black
    if (board[tile[0]][tile[1]] == 1) {
        board[tile[0]][tile[1]] = 2;
        printf("changed tile %d,%d from white to black\n",tile[0],tile[1]);
    } else if (board[tile[0]][tile[1]] == 2) {
        board[tile[0]][tile[1]] = 1;
        printf("changed tile %d,%d from black to white\n",tile[0],tile[1]);
    } else {
        printf("ERROR! Attempting to change blank space!\n");
    }
}

void move(int board[8][8], int head[2], int tail[2]) {
    /*
    DONT DO THIS IT BREAKS AFTER THE FIRST DIRECTION
    if (board[head[0]][head[1]]) {
        printf("ERROR: Head already occupied!\n");
    }
    */

    // check to make sure tail (existing tile) is set to something
    if (!board[tail[0]][tail[1]]) {
        printf("ERROR: Tail not occupied!\n");
    } else {
        // set head to the same color as the tail
        board[head[0]][head[1]] = board[tail[0]][tail[1]];

        //loop variables
        int i, j;
        int tile_to_change[2];
        if (head[1] == tail[1]) {
            // up or down
            j = head[1];
            if (head[0] > tail[0]) {
                //up
                //decrease row by 1 each loop starting from the tile above and ending before the tail 
                for (i = head[0]-1; i > tail[0]; i--) {
                    tile_to_change[0] = i;
                    tile_to_change[1] = j;
                    changeTile(board, tile_to_change);
                }
            } else if (head[0] < tail[0]) {
                //down
                //increase row by 1 each loop starting from the tile above and ending before the tail 
                for (i = head[0]+1; i < tail[0]; i++) {
                    tile_to_change[0] = i;
                    tile_to_change[1] = j;
                    changeTile(board, tile_to_change);
                }
            } else {
                printf("ERROR: Tile is in same column but not\n");
            }
        } else if (head[1] > tail[1]) {
            //left-something
            if (head[0] > tail[0]) {
                //up-left
                // decrease row and column each loop
                i = head[0]-1;
                for (j = head[1]-1; j > tail[1]; j--) {
                    tile_to_change[0] = i;
                    tile_to_change[1] = j;
                    changeTile(board, tile_to_change);
                    i--;
                }
            } else if (head[0] < tail[0]) {
                //down-left
                //increase row, decrease column
                i = head[0]+1;
                for (j = head[1]-1; j > tail[1]; j--) {
                    tile_to_change[0] = i;
                    tile_to_change[1] = j;
                    changeTile(board, tile_to_change);
                    i++;
                }
            } else if (head[0] == tail[0]) {
                //left
                //keep row, dcrease column
                i = head[0];
                for (j = head[1]-1; j > tail[1]; j--) {
                    tile_to_change[0] = i;
                    tile_to_change[1] = j;
                    changeTile(board, tile_to_change);
                }
            } else {
                printf("ERROR: Tile is left but not left?\n");
            }
        } else if (head[1] < tail[1]) {
            //right-something
            if (head[0] > tail[0]) {
                //up-right
                //decrease row, increase column
                i = head[0]-1;
                for (j = head[1]+1; j < tail[1]; j++) {
                    tile_to_change[0] = i;
                    tile_to_change[1] = j;
                    changeTile(board, tile_to_change);
                    i--;
                }
            } else if (head[0] < tail[0]) {
                //down-right
                //increase row, increase column
                i = head[0]+1;
                for (j = head[1]+1; j < tail[1]; j++) {
                    tile_to_change[0] = i;
                    tile_to_change[1] = j;
                    changeTile(board, tile_to_change);
                    i++;
                }
            } else if (head[0] == tail[0]) {
                //right
                //keep row, increase column
                i = head[0];
                for (j = head[1]+1; j < tail[1]; j++) {
                    tile_to_change[0] = i;
                    tile_to_change[1] = j;
                    changeTile(board, tile_to_change);
                }
            } else {
                printf("ERROR: Tile is right but not right?\n");
            }
        } else {
            //not up, down, left, or right
            printf("ERROR: tail not in any direction (same tile?)\n");
        }
    }
}

/*
// test code
int main () {
    int testArr[8][8] = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,2,0,0,0,0,0},
        {0,0,0,1,2,0,0,0},
        {0,0,0,1,1,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}};
    int testHead[2] = {5,5};
    int testTail[2] = {2,2};
    move(testArr,testHead,testTail);
    int i,j;
    printf("-----------------\n");
    for(i=0;i<8;i++) {
        printf("|");
        for (j=0;j<8;j++) {
            printf("%d|",testArr[i][j]);
        }
        printf("\n");
        printf("-----------------\n");
    }
    while(1) {}
}
*/
