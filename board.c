#include <stdio.h>
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
	printf("\n  A B C D E F G H \n");
	//0=blank   1=white   2=black
	//int test[8][8]= { {1,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,1,2,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} };
 	//[side number][top number]
	int col, row, val;
	for (row=0; row<=7; row++){
		printf (" -----------------\n%d|", row+1 ); //new collum
		for (col=0;col<=7;col++){ // nned to make "%|"
		     
		      val=test[row][col]; //                                    change me!!!!!!!!1

		      if (val==0){ // empty space
		        printf(" |");
		      }

		      else if (val==1){ //white space
		        printf("o|");
		      }

		      else if (val==2){ //black space
		        printf("*|");
		      }

		      else{ //error
		      	printf("?|");
		      }
		}
     printf("\n");
	}
  printf(" -----------------\n");
}
