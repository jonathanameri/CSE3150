#include <math.h>
#include <iostream>

int findPower(int x, int y) {
  int result = 1;
  
  for(int i = 0; i < y; i++) {
    result *= x;
  }

  return result;
}

int ECFindRoot(int *listCoeffs, int degree, int xmax)
{
  // listCoeffs: pointer to the array of integers as the coefficients of a polynomial; listCoeffs[0] is the constant term and so on
  // degree: highest degree term. That is, the number of coefficients in the array = degree+1
  // xmax: the largest value of root to search
  // your code here
  for (int i = 0; i <= xmax; i++) {
    int sum = 0;

    for (int j = 0; j <= degree; j++) {
      int power = 0;

      if (j == 0) {
        power = 1;
      } else {
        power = findPower(i, j);
      }

      sum += listCoeffs[j] * power;
    }

    if (sum == 0) {
      return i;
    }
  }

  return -1;
}

