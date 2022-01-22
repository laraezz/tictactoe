/************************ezzeddineLaraA2.c**************
Student Name: Lara Ezzeeddine Email Id: lezzeddi
Due Date: November 11th Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material that I have used, whether directly quoted or paraphrased. Furthermore, I certify that this assignment was prepared by me specifically for this course.


Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc givenA2.c tictactoeLara.c  -std=c99 -Wall
Running the Program Running: ./a.out


*/

#include "givenA2.h"

void createInitialBoard (char board[N][N]) {
  
  //*making sure that every spot in a 3x3 board (index 0,1,2 by 0,1,2) is filled with '?'
  board[0][0] = '?';
  board[0][1] = '?';
  board[0][2] = '?';
  board[1][0] = '?';
  board[1][1] = '?';
  board[1][2] = '?';
  board[2][0] = '?';
  board[2][1] = '?';
  board[2][2] = '?';
  //printing the board
  printf (" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf ("-----------\n");
  printf (" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf ("-----------\n");
  printf (" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
  printf ("\n");
}


void printCurrentBoard (char board[N][N]) {

  //taking the 3x3 board with appropriate values and printing it again
  printf ("\n");
  printf ("Current board now is:");
  printf ("\n");
  printf (" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf ("-----------\n");
  printf (" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf ("-----------\n");
  printf (" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
  printf ("\n");

}


int memberOf (int aNum, int someArray[N]) {

  //check the indexes of the someArray, if the someArray[i] == what we are looking for, return 1
  //someArray is not given, but will be tested with .h file

  //what the code does: takes an array with the length of N, and checks every 
  //single index of array using incrementing i to see if aNum is part of the array
  for (int i = 0; i < N; ++i)
    {
      if (someArray[i] == aNum)
  {
    return 1;
  }
    }
  return 0;

}

int isBoardFull (char board[N][N])
{

  //goes through every single spot and check if the spot is a '?'
  //if found '?', returns 0. if not found, returns 1
  if (board[0][0] == '?')
    {
      return 0;
    }
  else if (board[0][1] == '?')
    {
      return 0;
    }
  else if (board[0][2] == '?')
    {
      return 0;
    }
  else if (board[1][0] == '?')
    {
      return 0;
    }
  else if (board[1][1] == '?')
    {
      return 0;
    }
  else if (board[1][2] == '?')
    {
      return 0;
    }
  else if (board[2][0] == '?')
    {
      return 0;
    }
  else if (board[2][1] == '?')
    {
      return 0;
    }
  else if (board[2][2] == '?')
    {
      return 0;
    }
  else
    return 1;

}

int gameWon (char board[N][N], char symbol) {

  //checks if the AND combo or symbols is the same in:
  //checking rows
  if (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol)
    {
      return 1;
    }
  else if (board[1][0] == symbol && board[1][1] == symbol
     && board[1][2] == symbol)
    {
      return 1;
    }
  else if (board[2][0] == symbol && board[2][1] == symbol
     && board[2][2] == symbol)
    {
      return 1;
    }
  //checking columns
  if (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol)
    {
      return 1;
    }
  else if (board[0][1] == symbol && board[1][1] == symbol
     && board[2][1] == symbol)
    {
      return 1;
    }
  else if (board[0][2] == symbol && board[1][2] == symbol
     && board[2][2] == symbol)
    {
      return 1;
    }
  //checking diagonals
  if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
      return 1;
    }
  else if (board[0][2] == symbol && board[1][1] == symbol
     && board[2][0] == symbol)
    {
      return 1;
    }
  return 0;

}


int isInputValid (int entered, int minimum, int maximum) {

  //checks if the input is between the minimum and the maxim value
  //as taken from main, check is the userinput is between 1 and N(3)
  if (entered >= minimum && entered <= maximum)
    {
      return 1;
    }
  return 0;

}


void computerPlaysRandom (int *computerRow, int *computerCol) {

  //read up on rand() function and find how to make range

  //takes absolutely random number and divides it by 3. 
  //takes the reaminder of it(which will always be 0, 1 or 2) and assigns it to computerRow and computerColumn
  *computerRow = rand () % 3;
  *computerCol = rand () % 3;

}


void readUserMove (int *userRow, int *userCol, int *stepsWon) {

  char tempRow[10], tempCol[10];
  *stepsWon = *stepsWon + 1;

  printf ("Your move - enter numbers between 1 and 3\n");

  printf ("\nEnter row number: ");
  scanf ("%s", tempRow);

  printf ("Enter column number: ");

  scanf ("%s", tempCol);

  printf ("\n");

  *userRow = atoi (tempRow);

  *userCol = atoi (tempCol);

}


void all_sums (char board[N][N], int sumR[N], int sumC[N], int *sumLD, int *sumRD) {

  //loop in charge of running sums for the rows
  for (int i = 0; i < N; i++)
    {

      if (board[i][0] == 'O')
  {
    sumR[i] = sumR[i] + 4;
  }
      else if (board[i][0] == 'X')
  {
    sumR[i] = sumR[i] + 1;
  }

      if (board[i][1] == 'O')
  {
    sumR[i] = sumR[i] + 4;
  }
      else if (board[i][1] == 'X')
  {
    sumR[i] = sumR[i] + 1;
  }

      if (board[i][2] == 'O')
  {
    sumR[i] = sumR[i] + 4;
  }
      else if (board[i][2] == 'X')
  {
    sumR[i] = sumR[i] + 1;
  }
    }

  //loop in charge of running sums for the columns
  for (int i = 0; i < N; i++)
    {

      if (board[0][i] == 'O')
  {
    sumC[i] = sumC[i] + 4;
  }
      else if (board[0][i] == 'X')
  {
    sumC[i] = sumC[i] + 1;
  }

      if (board[1][i] == 'O')
  {
    sumC[i] = sumC[i] + 4;
  }
      else if (board[1][i] == 'X')
  {
    sumC[i] = sumC[i] + 1;
  }

      if (board[2][i] == 'O')
  {
    sumC[i] = sumC[i] + 4;
  }
      else if (board[2][i] == 'X')
  {
    sumC[i] = sumC[i] + 1;
  }
    }
  //loop in charge of running sums for the Left diagonal
  if (board[0][0] == 'O')
    {
      *sumLD = *sumLD + 4;
    }
  else if (board[0][0] == 'X')
    {
      *sumLD = *sumLD + 1;
    }

  if (board[1][1] == 'O')
    {
      *sumLD = *sumLD + 4;
    }
  else if (board[1][1] == 'X')
    {
      *sumLD = *sumLD + 1;
    }

  if (board[2][2] == 'O')
    {
      *sumLD = *sumLD + 4;
    }
  else if (board[2][2] == 'X')
    {
      *sumLD = *sumLD + 1;
    }


  //loop in charge of running sums for the Right diagonal
  if (board[0][2] == 'O')
    {
      *sumLD = *sumLD + 4;
    }
  else if (board[0][2] == 'X')
    {
      *sumLD = *sumLD + 1;
    }

  if (board[1][1] == 'O')
    {
      *sumLD = *sumLD + 4;
    }
  else if (board[1][1] == 'X')
    {
      *sumLD = *sumLD + 1;
    }

  if (board[2][0] == 'O')
    {
      *sumLD = *sumLD + 4;
    }
  else if (board[2][0] == 'X')
    {
      *sumLD = *sumLD + 1;
    }
  

}

int computerPlaysToWin (char board[N][N], int *computerRow, int *computerCol) {

  int sumR[N] = { 0, 0, 0 };
  int sumC[N] = { 0, 0, 0 };
  int sumLD = 0;
  int sumRD = 0;
  all_sums (board, sumR, sumC, &sumLD, &sumRD);

  //working with sumR[0]
  if (sumR[0] == 8)
    {
      if (board[0][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 0;
    return 1;
  }
      else if (board[0][1] == '?')
  {
    *computerRow = 0;
    *computerCol = 1;
    return 1;
  }
      else if (board[0][2] == '?')
  {
    *computerRow = 0;
    *computerCol = 2;
    return 1;
  }
    }
  //working with sumR[1]
  else if (sumR[1] == 8)
    {
      if (board[1][0] == '?')
  {
    *computerRow = 1;
    *computerCol = 0;
    return 1;
  }
      else if (board[1][1] == '?')
  {
    *computerRow = 1;
    *computerCol = 1;
    return 1;
  }
      else if (board[1][2] == '?')
  {
    *computerRow = 1;
    *computerCol = 2;
    return 1;
  }
    }
  //working with sumR[2]
  else if (sumR[2] == 8)
    {
      if (board[2][0] == '?')
  {
    *computerRow = 2;
    *computerCol = 0;
    return 1;
  }
      else if (board[2][1] == '?')
  {
    *computerRow = 2;
    *computerCol = 1;
    return 1;
  }
      else if (board[2][2] == '?')
  {
    *computerRow = 2;
    *computerCol = 2;
    return 1;
  }
    }
  //working with columns
  if (sumC[0] == 8)
    {
      if (board[0][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 0;
    return 1;
  }
      else if (board[1][0] == '?')
  {
    *computerRow = 1;
    *computerCol = 0;
    return 1;
  }
      else if (board[2][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 2;
    return 1;
  }
    }
  //working with sumC[1]
  else if (sumC[1] == 8)
    {
      if (board[0][1] == '?')
  {
    *computerRow = 0;
    *computerCol = 1;
    return 1;
  }
      else if (board[1][1] == '?')
  {
    *computerRow = 1;
    *computerCol = 1;
    return 1;
  }
      else if (board[2][1] == '?')
  {
    *computerRow = 2;
    *computerCol = 1;
    return 1;
  }
    }
  //working with sumC[2]
  else if (sumC[2] == 8)
    {
      if (board[0][2] == '?')
  {
    *computerRow = 0;
    *computerCol = 2;
    return 1;
  }
      else if (board[1][2] == '?')
  {
    *computerRow = 1;
    *computerCol = 2;
    return 1;
  }
      else if (board[2][2] == '?')
  {
    *computerRow = 2;
    *computerCol = 2;
    return 1;
  }
    }
  //working with diagonals
  if (sumLD == 8)
    {
      if (board[0][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 0;
    return 1;
  }
      else if (board[1][1] == '?')
  {
    *computerRow = 1;
    *computerCol = 1;
    return 1;
  }
      else if (board[2][2] == '?')
  {
    *computerRow = 2;
    *computerCol = 2;
    return 1;
  }
    }
  if (sumRD == 8)
    {
      if (board[0][2] == '?')
  {
    *computerRow = 0;
    *computerCol = 2;
    return 1;
  }
      else if (board[1][1] == '?')
  {
    *computerRow = 1;
    *computerCol = 1;
    return 1;
  }
      else if (board[0][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 0;
    return 1;
  }
    }
  return 0;

}

int computerPlaysToBlock (char board[N][N], int *computerRow, int *computerCol) {

  int sumR[N] = { 0, 0, 0 };
  int sumC[N] = { 0, 0, 0 };
  int sumLD = 0;
  int sumRD = 0;
  all_sums (board, sumR, sumC, &sumLD, &sumRD);

  //working with sumR[0]
  if (sumR[0] == 2)
    {
      if (board[0][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 0;
    return 1;
  }
      else if (board[0][1] == '?')
  {
    *computerRow = 0;
    *computerCol = 1;
    return 1;
  }
      else if (board[0][2] == '?')
  {
    *computerRow = 0;
    *computerCol = 2;
    return 1;
  }
    }
  //working with sumR[1]
  else if (sumR[1] == 2)
    {
      if (board[1][0] == '?')
  {
    *computerRow = 1;
    *computerCol = 0;
    return 1;
  }
      else if (board[1][1] == '?')
  {
    *computerRow = 1;
    *computerCol = 1;
    return 1;
  }
      else if (board[1][2] == '?')
  {
    *computerRow = 1;
    *computerCol = 2;
    return 1;
  }
    }
  //working with sumR[2]
  else if (sumR[2] == 2)
    {
      if (board[2][0] == '?')
  {
    *computerRow = 2;
    *computerCol = 0;
    return 1;
  }
      else if (board[2][1] == '?')
  {
    *computerRow = 2;
    *computerCol = 1;
    return 1;
  }
      else if (board[2][2] == '?')
  {
    *computerRow = 2;
    *computerCol = 2;
    return 1;
  }
    }
  //working with columns
  if (sumC[0] == 2)
    {
      if (board[0][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 0;
    return 1;
  }
      else if (board[1][0] == '?')
  {
    *computerRow = 1;
    *computerCol = 0;
    return 1;
  }
      else if (board[2][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 2;
    return 1;
  }
    }
  //working with sumC[1]
  else if (sumC[1] == 2)
    {
      if (board[0][1] == '?')
  {
    *computerRow = 0;
    *computerCol = 1;
    return 1;
  }
      else if (board[1][1] == '?')
  {
    *computerRow = 1;
    *computerCol = 1;
    return 1;
  }
      else if (board[2][1] == '?')
  {
    *computerRow = 2;
    *computerCol = 1;
    return 1;
  }
    }
  //working with sumC[2]
  else if (sumC[2] == 2)
    {
      if (board[0][2] == '?')
  {
    *computerRow = 0;
    *computerCol = 2;
    return 1;
  }
      else if (board[1][2] == '?')
  {
    *computerRow = 1;
    *computerCol = 2;
    return 1;
  }
      else if (board[2][2] == '?')
  {
    *computerRow = 2;
    *computerCol = 2;
    return 1;
  }
    }
  //working with diagonals
  if (sumLD == 2)
    {
      if (board[0][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 0;
    return 1;
  }
      else if (board[1][1] == '?')
  {
    *computerRow = 1;
    *computerCol = 1;
    return 1;
  }
      else if (board[2][2] == '?')
  {
    *computerRow = 2;
    *computerCol = 2;
    return 1;
  }
    }

  if (sumRD == 2)
    {
      if (board[0][2] == '?')
  {
    *computerRow = 0;
    *computerCol = 2;
    return 1;
  }
      else if (board[1][1] == '?')
  {
    *computerRow = 1;
    *computerCol = 1;
    return 1;
  }
      else if (board[0][0] == '?')
  {
    *computerRow = 0;
    *computerCol = 0;
    return 1;
  }
    }

  return 0;

}
