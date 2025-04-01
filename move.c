/*
    * Name: Cameron Hilstad
*/
#include <stdio.h>

void changeTile(int board[8][8], int tile[2]) {
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
    // check to make sure head (new point) is empty and tail (existing tile) is set
    if (board[head[0]][head[1]]) {
        printf("ERROR: Head already occupied!\n");
    } else if (!board[tail[0]][tail[1]]) {
        printf("ERROR: Tail not occupied!\n");
    } else {
        // set head to the same color as the tail
        board[head[0]][head[1]] = board[tail[0]][tail[1]];

        //loop variables
        int i, j;
        int tileToChange[2];
        if (head[1] == tail[1]) {
            // up or down
            j = head[1];
            if (head[0] > tail[0]) {
                //up
                for (i = head[0]-1; i > tail[0]; i--) {
                    tileToChange[0] = i;
                    tileToChange[1] = j;
                    changeTile(board, tileToChange);
                }
            } else if (head[0] < tail[0]) {
                //down
                for (i = head[0]+1; i < tail[0]; i++) {
                    tileToChange[0] = i;
                    tileToChange[1] = j;
                    changeTile(board, tileToChange);
                }
            } else {
                printf("ERROR: Tile is in same column but not\n");
            }
        } else if (head[1] > tail[1]) {
            //left-something
            if (head[0] > tail[0]) {
                //up-left
                i = head[0]-1;
                for (j = head[1]-1; j > tail[1]; j--) {
                    tileToChange[0] = i;
                    tileToChange[1] = j;
                    changeTile(board, tileToChange);
                    i--;
                }
            } else if (head[0] < tail[0]) {
                //down-left
                i = head[0]+1;
                for (j = head[1]-1; j > tail[1]; j--) {
                    tileToChange[0] = i;
                    tileToChange[1] = j;
                    changeTile(board, tileToChange);
                    i++;
                }
            } else if (head[0] == tail[0]) {
                //left
                i = head[0];
                for (j = head[1]-1; j > tail[1]; j--) {
                    tileToChange[0] = i;
                    tileToChange[1] = j;
                    changeTile(board, tileToChange);
                }
            } else {
                printf("ERROR: Tile is left but not left?\n");
            }
        } else if (head[1] < tail[1]) {
            //right-something
            if (head[0] > tail[0]) {
                //up-right
                i = head[0]-1;
                for (j = head[1]+1; j < tail[1]; j++) {
                    tileToChange[0] = i;
                    tileToChange[1] = j;
                    changeTile(board, tileToChange);
                    i--;
                }
            } else if (head[0] < tail[0]) {
                //down-right
                i = head[0]+1;
                for (j = head[1]+1; j < tail[1]; j++) {
                    tileToChange[0] = i;
                    tileToChange[1] = j;
                    changeTile(board, tileToChange);
                    i++;
                }
            } else if (head[0] == tail[0]) {
                //right
                i = head[0];
                for (j = head[1]+1; j < tail[1]; j++) {
                    tileToChange[0] = i;
                    tileToChange[1] = j;
                    changeTile(board, tileToChange);
                }
            } else {
                printf("ERROR: Tile is right but not right?\n");
            }
        } else {
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
