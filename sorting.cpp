/*-------------------------------------------------------------------
PA: Performance of Sorting Algorithms
Developed by: Brandon Bautista
-------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

#define MAXSIZE 100
#define NUMFUNCTIONS 3

//----------------------------------------------------------------------------------

void bubbleSort( int x[], int size, int & numCompare, int & numMove) ;
void selectSort( int x[], int size, int & numCompare, int & numMove) ;
void insertSort( int x[], int size, int & numCompare, int & numMove) ;
bool sorted( const int x[] , int size , int direction=0) ;

typedef void (*sortFunction) (int x[], int size, int& numCompare, int& numMove);

static sortFunction fPtrs[] = { bubbleSort , selectSort , insertSort } ;  //function pointers. Use so you don't have to call each fn seperately
static string     algName[] = { "Bubble Sort" , "Selection Sort" , "Insertion Sort" } ;

int main()
{
    int size , value , i , alg ;
    int data[NUMFUNCTIONS][MAXSIZE] ;
    int nc[NUMFUNCTIONS] , nv[NUMFUNCTIONS] ;


    while( true )
    {
        cin >> size ;
        if ( size <= 0 )
            break ;

        for( i=0 ; i<size ; i++ )
        {
            cin >> value ;
            for( alg=0; alg<NUMFUNCTIONS ; alg++)
                data[alg][i] = value ;
        }

        // Now, call each algorithm, one at-a-time.
        for( int alg=0 ; alg<NUMFUNCTIONS ; alg++ )
        {
            // calling the next sorting algorithm via the pointer to that function
            fPtrs[alg] ( data[alg],  size, nc[alg], nv[alg] )  ;

            cout << algName[alg] ;
            if ( sorted( data[alg] , size ) ) //check if the sorting worked
            {
                cout << " worked! with performance metrics: "
                     << nc[alg] << " , " << nv[alg] << endl ;
            }
            else
                cout << " failed!\n" ;
        }

    }
    return 0;
}

//----------------------------------------------------------------------------------
// Sort the incoming array x[] of 'size' integers. Also, pass back the total number
// of data comparisons and data movements via the 'numCompare' and 'numMove'
// formal parameters, respectively.
// Use the improved Bubble Sort (with the bubble flag)

void bubbleSort( int x[], int size, int & numCompare, int & numMove) //No print statements in final version (comment out or delete) use for debugging
{
    numCompare = numMove = 0 ;
    cout << "\nThis is the Bubble Sort Algorithm\n" ;

    cout << "Array after sorting: " ;
    for (int i=0 ; i<size ; i++) cout << x[i] << " " ;
    cout << endl ;
}

//----------------------------------------------------------------------------------
// Sort the incoming array x[] of 'size' integers. Also, pass back the total number
// of data comparisons and data movements via the 'numCompare' and 'numMove'
// formal parameters, respectively.
// Use the Selection sort algorithm discussed in class

void selectSort( int x[], int size, int & numCompare, int & numMove)
{
    numCompare = numMove = 0 ;
    cout << "\nThis is the Selection Sort Algorithm\n" ;

    cout << "Array after sorting: " ;
    for (int i=0 ; i<size ; i++) cout << x[i] << " " ;
    cout << endl ;
}

//----------------------------------------------------------------------------------
// Sort the incoming array x[] of 'size' integers. Also, pass back the total number
// of data comparisons and data movements via the 'numCompare' and 'numMove'
// formal parameters, respectively.
// Use the Insertion sort algorithm discussed in class

void insertSort( int x[], int size, int & numCompare, int & numMove)
{
    numCompare = numMove = 0 ;
    cout << "\nThis is the Insertion Sort Algorithm\n" ;

    cout << "Array after sorting: " ;
    for (int i=0 ; i<size ; i++) cout << x[i] << " " ;
    cout << endl ;
}

//----------------------------------------------------------------------------------
// Returns 'true' iff array x[] of 'size' integers is already sorted in
// ascending order: when 'direction' is 0, which is the default
// descending order: when 'direction' is 1
bool sorted( const int x[] , int size , int direction)
{

    return true ;
}

