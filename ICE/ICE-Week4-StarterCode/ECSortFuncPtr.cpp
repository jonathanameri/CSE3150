#include <iostream>
using namespace std;

// complete the definition of the sorting function ...
void ECSortFP(int *listNumbers, int size, ...)
{
  // your code here
}

int main()
{
  int arr[] = {1,3,2,4};
  ECSortFP(arr, 4, ???);

  // print it out
  for(int i=0; i<4; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

