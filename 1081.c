/*
* Student ID: 201220175
* Student Name: Matt Harding
* Email: sgmhardi@liverpool.ac.uk *
* User: sgmhardi *
* Problem ID: 1081
* RunID: 40367
* Result: ACCEPTED */

#include <stdio.h>

//Initialise variables constants etc
int rows, cols, steps, numOfSpaces = 0;
char characterIn;
char** board;
char** tempBoard;
#define ALIVE 'X'
#define DEAD '.'

//get initial board values from user input
int getBoard(){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j< cols; j++){
      scanf(" %c", &board[i][j]);
    }
  }
  return 0;
}

//initialise the gameboard and a temp board, using malloc to make dynamic
int initialiseGame(void){

  scanf("%d %d %d", &rows, &cols, &steps);
  numOfSpaces = (rows * cols);

  //board setup defaulting to dead for all cells in initialisation
  //create an array of pointers that point to 1d arrays to simulate a dynamic 2d array
  board = (char**) malloc(rows * sizeof(char*));
  tempBoard = (char**) malloc(rows * sizeof(char*));
  for(int i=0; i < rows; i++){
    board[i]=(char*) malloc(cols * sizeof(char));
    tempBoard[i]=(char*) malloc(cols * sizeof(char));
      for(int j=0; j < cols; j++){
        tempBoard[i][j] = DEAD;
        board[i][j]= DEAD;
      }
    }
  return 0;
}

//take in number of neighbours and current cell state, then apply the death/birth rules
char newCell(int neighbours, char currentState){
  char newValue = DEAD;
  //under population
  if(neighbours < 2 && currentState == ALIVE){
    newValue = DEAD;
  } else if ((neighbours == 3 || neighbours == 2) && currentState == ALIVE){
  //normal population
    newValue = ALIVE;
  } else if (currentState == ALIVE && neighbours > 3){
  //Over population
    newValue = DEAD;
  } else if (currentState == DEAD && neighbours == 3){
     newValue = ALIVE;
  }
  return newValue;
}

//check if looking at boundary cell, return dead if outside boundary
char boundaryCheck(int row, int col){
  char newState;
  if(row<0 || row > rows-1 || col < 0 || col > cols-1){
    newState = DEAD;
    return newState;
  }
  if (board[row][col] == ALIVE){
    newState = ALIVE;
  } else {
    newState = DEAD;
  }
  return newState;
}

//function to return the total number of neighbours a cell has
int calcNeighbours(int rowIn, int colIn){
  int numOfNeighbours = 0;
  //Up and to the left
  if(boundaryCheck(rowIn-1,colIn-1) == ALIVE){
    numOfNeighbours++;
  }
  //direct above
  if(boundaryCheck(rowIn-1,colIn)== ALIVE){
    numOfNeighbours++;
  }
  //Up and to the right
  if(boundaryCheck(rowIn-1,colIn+1) == ALIVE){
    numOfNeighbours++;
  }
  //direct left
  if(boundaryCheck(rowIn,colIn-1)== ALIVE){
    numOfNeighbours ++;
  }
  //direct right
  if(boundaryCheck(rowIn,colIn+1)== ALIVE){
    numOfNeighbours ++;
  }
  //below and left
  if(boundaryCheck(rowIn+1,colIn-1) == ALIVE){
    numOfNeighbours++;
  }
  //direct elow
  if(boundaryCheck(rowIn+1,colIn) == ALIVE){
    numOfNeighbours++;
  }
  //below and right
  if(boundaryCheck(rowIn+1,colIn+1) == ALIVE){
    numOfNeighbours++;
  }
  return numOfNeighbours;
}

//perform a timestep
int timeStep(){
  int neighbours = 0;
  for(int i = 0; i < rows; i ++){
    for(int j = 0; j < cols; j++){
      neighbours = calcNeighbours(i,j);
      tempBoard[i][j] = newCell(neighbours, board[i][j]);
    }
  }
  //for loop to relplace game board with the updated temporary board
  for(int i = 0; i<rows; i ++){
    for(int j = 0; j < cols; j++ ){
      board[i][j] = tempBoard[i][j];
    }
  }
  return 0;
}

//main program initialises the game, gets the board,and performs X timesteps printing the result
int main(void){
  initialiseGame();
  getBoard();

  //perform timesteps
  for(int i = 0; i < steps; i ++){
      timeStep();
  }

  //print the board
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      printf("%c", board[i][j]);
    }
    printf("\n");
  }

  //free up memory
  free(board);
  free(tempBoard);

  return 0;
}
