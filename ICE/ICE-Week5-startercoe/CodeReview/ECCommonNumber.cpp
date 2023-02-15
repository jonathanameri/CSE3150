#include <cstring>
#include <algorithm>
using namespace std;

bool ECCommonNumber(const int *A, int sza, const int *B, int szb, int &val)
{
  int *sortedA = new int[sza];
  int *sortedB = new int[szb];

  copy(A, A + sza, sortedA);
  copy(B, B + szb, sortedB);

  sort(sortedA, sortedA + sza);
  sort(sortedB, sortedB +szb);

  for(int i=0; i<sza; i++)
  {
    if (binary_search(sortedB, sortedB + szb, sortedA[i]))
    {
      val = sortedA[i];
      return true;
    }
  }
  return false;
}

