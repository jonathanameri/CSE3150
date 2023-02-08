#include <iostream>
using namespace std;
int ECSumArray(const int *listNums, int size)
{
  int res = 0;
  const int *ptr = listNums;
  for(int i = 0; i < size; i++){
    res += *ptr;
    ptr++;
  }
  return res;
  // You need to loop through the array using pointer. How to define this pointer? 
}

int main()
{
  int array[] = {1,2,3,5};
  int res = ECSumArray(array, 4);
  cout << res << endl;
  return 0;
}
