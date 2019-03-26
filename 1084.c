/*
* Student ID: 201220175
* Student Name: Matt Harding
* Email: sgmhardi@liverpool.ac.uk *
* User: sgmhardi *
* Problem ID: 1084
* RunID: 40625
* Result:  ACCEPTED*/

#include <stdio.h>
#include <stdlib.h>
//initialise variables
int lanes, laneLength, time, inputCounter, tempArrival, tempRowIndex, currentTimestep= 0;
char** roads;

//create a structure to act as tupled ints
typedef struct {
  int arrivalTime;
  int rowIndex;

} tuple;

//create array of type tuple
tuple* arrayOfTuples;

//get game size and timesteps and set up car input tuples
int initialiseGame(void){
  scanf("%d%d%d", &lanes, &laneLength, &time);

  //create an array of pointers that point to 1d arrays to simulate a dynamic 2d array
  roads = (char**) malloc(lanes * sizeof(char*));
  for(int i=0; i < lanes; i++){
    roads[i] = (char*) malloc(laneLength * sizeof(char));
    for(int j=0; j < laneLength; j++){
      roads[i][j] = '.';
    }
  }

  //take in arrival times and row indexes and store in array of tuple struct
  arrayOfTuples = (tuple*)malloc(sizeof(tuple*));
  while(scanf("%d %d", &tempArrival, &tempRowIndex) != EOF){
    arrayOfTuples[inputCounter].arrivalTime = tempArrival;
    arrayOfTuples[inputCounter].rowIndex = tempRowIndex;
    inputCounter ++;
  }
  return 0;
}

//move any vehicles along the road one space until reaches the end
int movePhase(){
  for(int i = 0; i < lanes; i++){
    for(int j = laneLength-1 ; j > (-1) ; j--){
      if(roads[i][j] == '1' && j < (laneLength - 1)){
        roads[i][j] = '.';
        roads[i][j+1] = '1';
      } else if (roads[i][j] == '1' && j == laneLength - 1){
        roads[i][j] = '.';
      }
    }
  }
  return 0;
}

//Deal with arrvials
int arrivalPhase(){
  for(int i = 0 ; i < inputCounter; i++){
    if(arrayOfTuples[i].arrivalTime == (currentTimestep-1)){
      *roads[arrayOfTuples[i].rowIndex] = '1';
    }
  }
  //increment timestep
  currentTimestep ++;

  return 0;
}

//performs move phase, arrivalPhase and then prints the board
int timeStep(){

  movePhase();
  arrivalPhase();
  return 0;
}

int main(void){
  initialiseGame();
  //perform time step
  for(int i=0; i <= time; i++){
    timeStep();
  }
  //print 2d array.
  for(int i=0; i <lanes; i++){
    for(int j=0; j < laneLength; j++){
      printf("%c", roads[i][j]);
    }
    printf("\n");
  }

  //free memory
   free(roads);
  // free(arrayOfTuples);
  return 0;
}
