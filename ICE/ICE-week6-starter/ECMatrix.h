#ifndef _EC_MATRIX_H
#define _EC_MATRIX_H

#include <vector>

// Matrix: two dimensional

class ECMatrix
{
public:
  // default constructor
  ECMatrix();

  // create a matrix of nr rows and nc columns
  ECMatrix(int nr, int nc);

  // Copy constructor
  ECMatrix(const ECMatrix &rhs);

  // Assignment operator 
  ECMatrix operator=(const ECMatrix &rhs);

  // Move constructor
  ECMatrix(ECMatrix &&rhs);

  // Get num of rows/columns
  int GetNumRows() const;
  int GetNumCols() const;

  // Get/set an element in the matrix
  double GetVal(int r, int c) const;
  void SetVal(int r, int c, double val);

  // Scale by a factor
  ECMatrix Scale(double factor) const;

private:
  std::vector<std::vector<double> > listElements;

};

#endif
