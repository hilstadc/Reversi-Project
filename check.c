#include <stdio.h>
#include <stdbool.h>
//FINISHED

//This function takes and input and the board state, then confrims if the input by the player is a valid move. IF valid, return a 1 and send the inpu to the move function to update board pointer.If invalid, return a 0 and update nothing

//board[8][8]
//side , down



bool nullcheck (int cord[2], int row, int col){
  if (cord[0]==0 && row==-1){ //top side of board
    return false; }
  else if (cord[0]==7 && row==1){ //bottom side of board
    return false; }
  else if (cord[1]==0 && col==-1){ //left side of 
    return false; }
  else if (cord[1]==7 && col==1){ //right side of the board
    return false; }
  else{
    return true;
    }
}


int validate (int board[8][8], int cord [2], int color){ //Main function for here
  int row, col, f, e; //cord[0] = r, cord[1] = c
  bool cool;
  int tail[2]; //where 'move' will end there program;
  cool=false;
  f=1;
  e=2;
  if (color==2){// if black's turn instead of white
    f=2;
    e=1;
  }  
  
  if (board[cord[0]][cord[1]] != 0){
    printf("Cannot place piece on taken spot!\n");
    return 0;
  }
  
  for (row=-1; row<=1; row++){
    for (col=-1; col<=1; col++){
      if (row==0 && col==0){ //skip (+0,+0)
        continue; }
      if (nullcheck(cord, row, col) == false){ //nullcheck
        continue; }
    
      if (board[cord[0]+row][cord[1]+col] == e){
        //                                  Start loop to validate move
        tail[0]=cord[0];
        tail[1]=cord[1];
        while (cool==false){
          tail[0]=tail[0]+row; //move to next piece
          tail[1]=tail[1]+col;
          if (nullcheck(tail, row, col) == false){
            break; //hits wall
          }
          else if (board[tail[0]+row][tail[1]+col] == 0){
            break; //hits empty
          }
          else if (board[tail[0]+row][tail[1]+col] == f){
            cool=true; //hits end, confrims valid move
            tail[0]=tail[0]+row;
            tail[1]=tail[1]+col;
            //move(board, cord, tail);                            //send input to move function to update board pointer
          }
          else {
            cool=false;//hits enemy piece, keeps going
            continue;
          }
        }//while loop
        
      }
      // else 'f' or '0'
          
    }//col for end
  }//row for end
  
  if (cool==false){    // INVALID
    return 0; //return sends to player
  }
  else{                // VALID
    //move(board, cord, tail)\\
    return 1;   
  }
  return 1; //weird glitch if return is not in here
  
// failiure == 0              NULL
// Success == 1               int[8][8]
} // give change board state the pointer of the array[][] and both coordinates