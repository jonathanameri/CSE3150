// created by Y. Wu, Feb 1, 2023
// You are implement a function called ECSwap which takes two integers x and y and swap them if x is larger than y. Note: after the function returns, the passed integers should ensure x <= y
// The following code has a bug. Fix it

#include <iostream>
using namespace std;
void ECSwap(int &x, int &y)
{
  if( x > y )
  {
    int tmp = x;
     x = y;
     y = tmp;
  }
}


// int main(){
//   int x = 5;
//   int y = 3;
//   ECSwap(x,y);
//   cout<<x << " " << y << endl;
//   return 0;
// }