/*
* Student ID: 201220275 *
* Student Name: Matthew Harding  *
* Email: sgmhardi@liverpool.ac.uk *
* User: sgmhardi *
* Problem ID: 1013
* RunID:
* Result:  */


#include <stdio.h>

int main(void){
  /*Declare and initialise functions and variables*/

  int num;
  int scoreHigh = 0;
  int scoreMedium = 0;
  int scoreLow = 0;

  /*print function for final results*/
  void printResults(){
    printf(">=85 : %d \n", scoreHigh);
    printf("60-84 : %d \n", scoreMedium);
    printf("60 : %d \n", scoreLow);
    return 0;
  }

  /*Calculate the sum of each result type based on boundaries*/
  void sumResults(int num){
    switch(num){
      case num >= 85:
        scoreHigh += 1;
      case num >59 && num <85:
        scoreMedium +=1;
      case num <60:
        scoreLow += 1;
      }
    return 0;
  }

  getMarks(){
    while(num != 0){
      scanf("%d", &num);
      sumResults(num);
      }
    printResults();
    return 0;
    }

  /*run program*/
  getMarks();

}
