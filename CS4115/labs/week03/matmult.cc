#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ofstream;
using namespace std; 

#include <math.h>
#include <stdlib.h>

void readArr(int, int, double **);
void multArrs(int, double **, int, double **, int, double **);

int main(int argc, char *argv[])
{
  int ar = atoi(argv[1]);
  int ac = atoi(argv[2]);
  int br = atoi(argv[3]);
  int bc = atoi(argv[4]);

  if (ac != br)
  {
    cerr<< "Matrix dimensions mismatch; exiting.\n";
    exit(-1);
  }

  // reserve space for the three arrays
  double **A = new double*[ar];	// each el. of this points to a row of A
  for (int i = 0; i < ar; i++)
    A[i] = new double[ac];	// a row of 'ac' floats

  double **B = new double*[br];
  for (int i = 0; i < br; i++)
    B[i] = new double[bc];	// a row of 'bc' floats

  double **C = new double*[ar];	// each el. of this points to a row of C
  //fill in code here to allocate C
  for (int i =0; i < ar; i++)
  C[i] = new double[bc]; //pretty easy to do code pretty much giving in text form
  // C has 'ar' rows and 'bc' columns
  //second line to fill in	
  // a row of 'bc' floats

  // now that sufficient storage is allocated, start reading from kbd

  readArr(ar, ac, A);
  readArr(br, bc, B);

  multArrs(ar, A, bc, B, ac, C);

  // now print out answer, nice and plainly
for (int rows = 0; rows < ar; rows++) { //iterates through the rows of the new output matrix C
	for (int columns = 0; columns < bc; columns++)  //iterates through the columns of the new output matrix C
	cout<<C[rows][columns]<<" "; 
	cout<<"\n"; // at every iteration in the loop, cout prints the figure, followed by a space and after a row is complete, the \n is used to go to the next row 
	
	}
 

}

// read from kbd into this array, row by row
//  for a total of r x c entries;
//  WARNING: space for array must have been reserved beforehand
void readArr(int r, int c, double **arr)
{
  // code for reading in r rows of c elements each goes her
  for (int rows =0; rows < r; rows++) { // 
  for (int columns = 0; columns < c; columns++) {
  cin>> arr[rows][columns]; //pretty much reads the rows and columns of each element based of a text file of the matrices which are used to test and stores it as an array called arr
  
  }
  }
  
  
}

void multArrs(int ar, double **A, int bc, double **B, int br, double **C)
{
   // multiplication here
  
  
  for (int rows = 0; rows < ar; rows++) { //gets contents by rows matrix A
     for (int columns = 0; columns < bc; columns++){ //gets content by columns of matrix B
      C[rows][columns] = 0; //output matrix initalized
	for (int multi = 0; multi < br; multi++) //allows multiplication to actually take place
           C[rows][columns] += A[rows][multi] * B[multi][columns]; //values stored in the new matrix C
	}
}
}
/* HOW I RAN:::
- Used my test file I made.
- Opened my directory in linux terminal (I use fedora)
- Used the command in lab sheet "g++ matmult.cc -o matmult"
- Then used "./matmult 4 5 5 6 < test" which runs the program (first 2 digits represents rows and columns of matrix A in that order, same for last two digits)
- Compared output to test.output file
- did it with m0 and m1 (was using wrong matrix size for awhile quite silly wondering why wrong)
- Also did same with m2.in which someone in our class (I think) made
- then i ran the diff commands (eg ./matmult 4 5 5 6 < m0.in > m0.out ) to make sure the output files wouldnt change and were correct.
 */
