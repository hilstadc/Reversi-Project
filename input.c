#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "check.h"
#include "board.h"
#include "input.h"

// Finished


int turn (int board[8][8], int player){ // player turn, takes input and calls validate. takes board and player (1 or 2)
  char col;
  int row;
  int run = 1;
  int skip;
  int cords[2];
  int col_n;
  int valid = 0;
  int r_var = 0;
  
  print_b(board); // printing current board
  
  if (player == 1){
    printf ("White Turn: \n");
  }
  else{
    printf ("Black Turn: \n");
  }
  
  while (run == 1){ // runs until user inputs valid spot or skips
    printf ("Would you like to: \n(1)make a move \n(2) skip \n");
    scanf ("%d", &skip);
    
    switch (skip){ // player chooses to make a move or skip
    case 1: // player chose to make a move
      printf ("Enter row: ");
      scanf ("%d", &row);
      printf ("Enter column: ");
      getchar();
      scanf (" %c", &col);
      col = toupper(col); // converting letter to uppercase
      
      switch(col){ // converting letter to number
      case 'A':
        col_n = 1;
        break;
      case 'B':
        col_n = 2;
        break;
      case 'C':
        col_n = 3;
        break;
      case 'D':
        col_n = 4;
        break;
      case 'E':
        col_n = 5;
        break;
      case 'F':
        col_n = 6;
        break;
      case 'G':
        col_n = 7;
        break;
      case 'H':
        col_n = 8;
        break;
      default:
        col_n = 0; // if player did not enter a valid letter
      }
      
      if (row<1 || row>8){ // if player did not enter a valid row -> reprompts user to enter space
        printf ("Error, not a valid row \n");
      }
      else if (col_n<1 || col_n>8){ // if player did not enter a valid column -> reprompts user to enter space
        printf ("Error, not a valid column \n");
      }
      else{ // if user entered a valid space
        cords[0] = row-1; // subtracting 1 to account for starting at 0 in arrays
        cords[1] = col_n-1;
        valid = validate(board, cords, player); // calling function to check if space is a valid move           
                                                 // valid returns: 0 for invalid move, 1 for valid move
                                                 
        if (valid == 0){ // not a valid move
          printf ("[%d, %c] is not a valid move \n", row, col);
        }
        else{ // valid move
          r_var = 1; // return-1 player made a move;
          run = 0;
          return(r_var);
        }
      }
      
      break;
    case 2: // player skipped
      r_var = 2; // return-2 player skipped turn
      run = 0;
      return(r_var);
      break;
    default: // did not enter 1 or 2
      printf ("Please enter a 1 or 2 \n");
    }
  }
}
