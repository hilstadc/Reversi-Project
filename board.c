#include <stdio.h>
#include "board.h"

#define default "\x1b[0m" //defining colors
#define yellow "\x1b[33m"
#define black "\x1b[30m"
#define white "\x1b[37m"
#define backGreen "\x1b[42m"
#define backBlack "\x1b[40m"

// Finished
/*
      	 A B C D E F G H               
      	-----------------
       1| | | | | | | | |
      	-----------------
       2| | | | | | | | |
        -----------------
       3| | | | | | | | |
        -----------------
       4| | | |o|*| | | |
        -----------------
       5| | | |*|o| | | |
        -----------------
       6| | | | | | | | |
        -----------------
       7| | | | | | | | |
        -----------------
       8| | | | | | | | |
      	-----------------
*/


//struct bro{
//	int board[8][8];
//}white, black;


void print_b(int test[8][8]) {
	printf(yellow "\n  A B C D E F G H \n" default);
	//0=blank   1=white   2=black
 	//[side number][top number]
	int col, row, val;
	for (row=0; row<=7; row++){
		printf (" "backGreen black "-----------------" backBlack yellow " \n%d" backGreen black "|", row+1 ); //new collum
		for (col=0;col<=7;col++){ // need to make "%|"
		     
		      val=test[row][col]; 

		      if (val==0){ // empty space
		        printf(" |");
		      }

		      else if (val==1){ //white space
		        printf( white "o" black "|");
		      }

		      else if (val==2){ //black space
		        printf( black "o|");
		      }

		      else{ //error
		      	printf( default "?" backGreen black"|");
		      }
		}
     printf(backBlack "\n");
	}
  printf(" " backGreen black "-----------------" default " \n");
}
