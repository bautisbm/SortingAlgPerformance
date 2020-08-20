/*-------------------------------------------------------------------
 PA: Performance of Sorting Algorithms
 Developed by: Brandon Bautista
 -------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

#define MAXSIZE 8200
//#define NUMFUNCTIONS 4
#define REPEATS 50

//----------------------------------------------------------------------------------
typedef int elemType;

void
swap (elemType x[], int first, int second);

int
partition(elemType x[], int first, int last, int & numCompare, int & numMove);

void
recQuickSort(elemType x[], int first, int last, int & numCompare, int & numMove);

void
bubbleSort (elemType x[], int size, int & numCompare,
	    int & numMove);
void
selectSort (elemType x[], int size, int & numCompare,
	    int & numMove);

void
insertSort (elemType x[], int size, int & numCompare,
	    int & numMove);
void
quickSort (elemType x[], int size, int & numCompare,
	    int & numMove);

bool
sorted (const int x[], int size, int direction = 0);


int
main ()
{

  elemType value, data1[MAXSIZE], data2[MAXSIZE], data3[MAXSIZE], data4[MAXSIZE];
  int size, j, i, temp1, temp2;
  unsigned bubbleComps, selectComps, insertComps, quickComps;
  unsigned bubbleMoves, selectMoves, insertMoves, quickMoves;


  //Seed the random Number Generator function with this seed
  srand(time(NULL));

  for (size = 2; size < MAXSIZE; size *= 2)
  {
    //Reset statistics
    bubbleComps = 0; bubbleMoves = 0;
    selectComps = 0; selectMoves = 0;
    insertComps = 0; insertMoves = 0;
    quickComps = 0; quickMoves = 0;
    //temp1 = 0; temp2 = 0;

    //Randomly generate the data and store copies in separate arrays

    for( i=0 ; i<size ; i++ )
    {
        value = rand() % 100;
        data1[i] = value;
        data2[i] = value;
        data3[i] = value;
        data4[i] = value;
    }


      //Calling the various sorting algorithms
      bubbleSort (data1, size, temp1, temp2);
      bubbleComps += temp1;
      bubbleMoves += temp2;

      selectSort (data2, size, temp1, temp2);
      selectComps += temp1;
      selectMoves += temp2;

      insertSort (data3, size, temp1, temp2);
      insertComps += temp1;
      insertMoves += temp2;

      quickSort (data4, size, temp1, temp2);
      quickComps += temp1;
      quickMoves += temp2;

    // Compute the averages

    //Display the raw statistics

    cout << setw(6) << size
	 << setw(10) << bubbleComps << setw(10) << bubbleMoves
	 << setw(10) << selectComps << setw(10) << selectMoves
	 << setw(10) << insertComps << setw(10) << insertMoves
	 << setw(10) << quickComps << setw(10) << quickMoves << endl;
  }

  return 0;
}


//----------------------------------------------------------------------------------
// Sort the incoming array x[] of 'size' integers. Also, pass back the total number
// of data comparisons and data movements via the 'numCompare' and 'numMove'
// formal parameters, respectively.
// Use the improved Bubble Sort (with the bubble flag)

void
bubbleSort (elemType x[], int size, int & numCompare,
	    int & numMove)
{
  numCompare = numMove = 0;
  bool bubble;


  for (int last = size - 1; last > 0; last--)
    {
      bubble = false;
      for (int index = 0; index < last; index++)
	{
	  numCompare++;
	  if (x[index] > x[index + 1]) //data comparison
	    {
	      elemType temp = x[index]; //data movement
	      x[index] = x[index + 1]; //data movement
	      x[index + 1] = temp; //data movement
	      numMove += 3; //3 data movements
	      bubble = true;

	    }
	}
      if (!bubble)
	break;
    }

}

//----------------------------------------------------------------------------------
// Sort the incoming array x[] of 'size' integers. Also, pass back the total number
// of data comparisons and data movements via the 'numCompare' and 'numMove'
// formal parameters, respectively.
// Use the Selection sort algorithm discussed in class

void
selectSort (int x[], int size, int & numCompare,
	    int & numMove)
{
  numCompare = numMove = 0;

  int location; // to hold the current location in the array
  int minIndex; //to hold the current minIndex
  int temp; // to hold a temporary value when swapping
  int tempLoc; //to hold a temporary location to find the minIndex

  for (location = 0; location < size; location++)
    {
      minIndex = location; //
      for (tempLoc = minIndex + 1; tempLoc <= size - 1; tempLoc++) //"minLocation" function
	{
	  numCompare++;
	  if (x[tempLoc] < x[minIndex]) //data comparison
	      minIndex = tempLoc;
	}

      //begin swapping
      if (location != minIndex)
	{
	  swap(x, location, minIndex);
	  numMove+=3;
	}
    }


}

void
swap (elemType x[], int first, int second)
{
  int temp;

  temp = x[first];
  x[first] = x[second];
  x[second] = temp;

}

//----------------------------------------------------------------------------------
// Sort the incoming array x[] of 'size' integers. Also, pass back the total number
// of data comparisons and data movements via the 'numCompare' and 'numMove'
// formal parameters, respectively.
// Use the Insertion sort algorithm discussed in class

void
insertSort (int x[], int size, int & numCompare,
	    int & numMove)
{
  numCompare = numMove = 0;

  for (int firstOut = 1; firstOut < size; firstOut++)
    {
      numCompare++;
      if (x[firstOut] < x[firstOut - 1]) //data comparison
	{
	  int temp = x[firstOut]; //data movement
	  numMove++;

	  int location = firstOut;

	  do
	    {
	      x[location] = x[location - 1]; //data movement
	      numMove++;
	      location--;
	      if (location <= 0)
		break;

	      numCompare++; //in the while condition
	    }
	  while (location > 0 && x[location - 1] > temp); //data comparison

	  x[location] = temp; //data movement
	  numMove++;
	}
    }

  /*
  cout << "Array after sorting: ";
  for (int i = 0; i < size; i++)
    cout << x[i] << " ";
  cout << endl;
  */
}

//----------------------------------------------------------------------------------
// Sort the incoming array x[] of 'size' integers. Also, pass back the total number
// of data comparisons and data movements via the 'numCompare' and 'numMove'
// formal parameters, respectively.
// Use the Quick sort algorithm discussed in class
void
quickSort (int x[], int size, int & numCompare, int & numMove)
{
  numCompare = numMove = 0; // Done by caller.

  recQuickSort(x, 0 , size - 1, numCompare, numMove);

}

int
partition(int x[], int first, int last, int & numCompare, int & numMove)
{
  int pivot;

  int index, smallIndex;

  swap(x, first, (first + last) / 2);

  pivot = x[first];
  smallIndex = first;

  for (index = first + 1; index <= last; index++)
    if (x[index] < pivot)
    {
      numCompare++;
      smallIndex++;
      swap(x, smallIndex, index);
      numMove+=3;
    }

  swap(x, first, smallIndex);
  numMove+=3;

  return smallIndex;
}


void
recQuickSort(int x[], int first, int last, int & numCompare, int & numMove)
{
  int pivotLocation;

  if (first < last) //Check if there's at least two elements
  {
    pivotLocation = partition(x, first, last, numCompare, numMove);
    recQuickSort(x, first, pivotLocation - 1, numCompare, numMove);
    recQuickSort(x, pivotLocation + 1, last, numCompare, numMove);
  }
}


//----------------------------------------------------------------------------------
// Returns 'true' if array x[] of 'size' integers is already sorted in
// ascending order: when 'direction' is 0, which is the default
// descending order: when 'direction' is 1 
bool
sorted (const int x[], int size, int direction)
{
  if (direction == 0) // check if the array is sorted in ascending order
    {
      for (int index = 0; index < size; index++)
	{
	  if (x[index] > x[index + 1])
	    return false;

	  else
	    return true;
	}
    }

  else if (direction == 1) //check if the array is sorted in descending order
    {
      for (int index = size - 1; index > 0; index--)
	{
	  if (x[index] < x[index - 1])
	    return false;

	  else
	    return true;
	}
    }

  return false; //if direction != 0 || 1 then return false
}

