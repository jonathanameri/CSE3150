//
#include <iostream>
using namespace std;

int main()
{
  // allocate an array of char in heap 
  char *px = new char[10];
  // set this array to 'a', 'b' and so on
  // your code here...

  // print out
  for(int i=0; i<10; ++i)
  {
    cout << *(px+i);
  }
  cout << endl;

  delete [] px;

  return 0;
}
 
