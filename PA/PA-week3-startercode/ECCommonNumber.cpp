// Given two arrays of integers, return true (and also store the smallest integer that is in both arrays). Return false if no such integer exists 
// For example, suppose A1={1, 5, 3, 1} and A2={3, 7, 2}. Then ECCommonNumber(A1, 4, A2, 3, val) would return true (and val would be 3 after function call returns). Here, A1 is the first array, 4 is the size of the first array, A2 is the second array and 3 is the size of the second array. 
// Note: you must implement your algorithm as efficiently as possible
// Also, you need to define the function yourself: how are you going to take
// Tip: don't reinvent the wheel; try to use C++ standard library functions

#include <cstring>
#include <algorithm>
using namespace std;



bool ECCommonNumber(const int *arr1, int sz1, const int *arr2, int sz2, int &val)
{
  if (sz1 == 0 || sz2 == 0) return false;

  int *arr1c = const_cast<int*>(arr1);
  int *arr2c = const_cast<int*>(arr2);
  sort(arr1c, arr1c + sz1);
  sort(arr2c, arr2c + sz2);

  // int num1 = arr1c[0];
  // int num2 = arr2c[0]; 

  for(int i = 0; i < sz1; i ++){
    int num = arr1c[i];
    if(binary_search(arr2c,arr2c+sz2,num)){
      val = num;
      return true;
    }
  }

  return false;
  // your code here...
}

