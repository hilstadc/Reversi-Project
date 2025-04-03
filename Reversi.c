#include <stdio.h>
#include "input.h"
//unfinished

//gcc -o a Reversi.c board.c input.c[...]


int main(){
	printf ("Reversi: \n");
	int board[8][8] = { {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,2,1,0,0,0}, {0,0,0,1,2,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} }; // starting board

  int player = 1;
  int skip1 = 0;
  int skip2 = 0;
  int run = 1;
  int end;
  int end_loop = 1;
  int i;
  int j;
  int b_full = 1;
  
  while (run == 1){  //while game not won
  
    b_full = 1; // checking to see if board is full
    for (i=0; i<8; i++){ // runs through each row
      for (j=0; j<8; j++){ // runs through each column of the row
        if (board[i][j] == 0){
          b_full = 0; // board is not full
          break;
        }
      }
    }
    if (b_full == 1){ // if board is full, end game
      printf ("Board is full, Ending game \n\n");
      run = 0;
      break;
    }  
  
    //player 1 turn
    player = 1; // white: o
    skip1 = turn(board, player); // turn returns: 1 for played, 2 for skipped
    
    b_full = 1; // checking to see if board is full
    for (i=0; i<8; i++){ // runs through each row
      for (j=0; j<8; j++){ // runs through each column of the row
        if (board[i][j] == 0){
          b_full = 0; // board is not full
          break;
        }
      }
    }
    if (b_full == 1){ // if board is full, end game
      printf ("Board is full, Ending game \n\n");
      run == 0;
      break;
    }
    
    //player 2 turn
    player = 2; // black: *
    skip2 = turn(board, player);
    
    if (skip1==2 && skip2==2){ // both players skipped, asks to end game
      while (end_loop == 1){
        printf("Would you like to end the game (1)yes (2)no \n");
        scanf("%d", &end);
        switch (end){
        case 1: // end game
          printf ("Ending game \n\n");
          end_loop = 0;
          run = 0;
          break;
        case 2: // continue game
          break;
        default: // incorrect input check
          printf ("Please enter a 1 or 2 \n");
        }
      }
    }
  }

  // getting scores
  int score_1 = 0;
  int score_2 = 0;
  
  for (i=0; i<8; i++){ // runs through each row
    for (j=0; j<8; j++){ // runs through each column of the row
      if (board[i][j] == 1){
        score_1++; // point to player 1
      }
      else if (board[i][j] == 2){
        score_2++; // point to player 2
      }
    }
  }
  
  printf ("Player 1's score is: %d \n", score_1); // printing scores of each player
  printf ("Player 2's score is: %d \n", score_2);
  
  (score_1>score_2) ? printf ("Player 1 wins! \n") // prints which player won
                    : printf ("Player 2 wins! \n");

return 0;
}



