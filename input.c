#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Finished


void turn (int board[8][8], int player){ // player turn, takes input and calls validate. takes board and player (1 or 2)
  char col;
  int row;
  int run = 1;
  int skip;
  int coords[2];
  int col_n;
  int valid = 0;
  
  print_b(board);
  
  printf ("Player %d's Turn: \n", player);
  
  while (run == 1){ // runs until user inputs valid spot or skips
    printf ("Would you like to: \n(1)make a move \n(2) skip");
    scanf ("%d", &skip);
    
    switch (skip){
    case 1: // player chose to make a move
      getchar();
      printf ("Enter column: ");
      scanf ("%c", col);
      printf ("Enter row: ");
      scanf ("%d", &row);
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
        col_n = 0;
      }
      
      if (row<1 || row>8){
        printf ("Error, not a valid row \n");
      }
      else if (col_n<1 || col_n>8){
        printf ("Error, not a valid column \n");
      }
      else{
        coords[1] = row-1;
        coords[2] = col_n-1;
        valid = validate(board, coords, player);
        
        if (valid == 0){
          printf ("[%d, %c] is not a valid move \n");
        }
        else{
          run = 0;
          return;
        }
      }
      
      break;
    case 2: // player skipped
      return;
      break;
    default: // did not enter 1 or 2
      printf ("Please enter a 1 or 2 \n");
    }
  }
}
