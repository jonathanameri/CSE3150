// Note: you need to add compiler flag -fno-elide-constructors to
// disable copy elision (return value optimization) in order to see 
// move constructor work as what you expect
#include "ECMatrix.h" 
#include <iostream>

// default constructor
ECMatrix :: ECMatrix()
{
}

// create a matrix of nr rows and nc columns
ECMatrix::ECMatrix(int nr, int nc)
{
   // your code
}

// Copy constructor
ECMatrix::ECMatrix(const ECMatrix &rhs)  
{
  // your code
}

// 
ECMatrix ECMatrix::operator=(const ECMatrix &rhs) 
{
  // your code
}

// Move constructor
ECMatrix::ECMatrix(ECMatrix &&rhs)
{
  // your code
}

// Get num of rows/columns
int ECMatrix:: GetNumRows() const
{
  // your code
}

int ECMatrix :: GetNumCols() const
{
  // your code
}

// Get/set an element in the matrix
double ECMatrix::GetVal(int r, int c) const
{
  // your code
}
void ECMatrix::SetVal(int r, int c, double val)
{
  // your code
}

// Scale by a factor
ECMatrix ECMatrix:: Scale(double factor) const
{
  // your code
}

