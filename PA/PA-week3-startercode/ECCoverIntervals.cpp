// Given a sorted list, find the smallest number of covering intervals
// For example, if A={1,2,3,5,6,9}, there are three covering intervals [1,3], [5,6] and [9]
#include <iostream>
using namespace std;
int ECSmallestCoverIntervals(const int arrInts[], int szArr)
{
  if (szArr == 0 || szArr == 1){
    return szArr;
  }
  int numIntervals = 1;
  // int firstNum = arrInts[0];
  for(int i = 1; i < szArr; i++){
    int curNum = arrInts[i];
    if (curNum - arrInts[i-1] != 1) numIntervals++;
  }
  // if(arrInts[szArr-1] - arrInts[szArr-2] != 1) numIntervals++;
  return numIntervals;
  
  // arrInts: sorted array of integers; szArr: number of integers in the array
  // Your code here  

}

// int main(){
//   int arr[] = {0,1,2,4,5,7};
//   cout << ECSmallestCoverIntervals(arr, 6) << endl;
//   int arr2[] = {0,2,3,4,6,8,9};
//   cout << ECSmallestCoverIntervals(arr2, 7) << endl;
//   int arr3[] = {0,1,3,5};
//   cout << ECSmallestCoverIntervals(arr3, 4) << endl;
//   return 0;
// }

