#include <iostream>
using namespace std;
#include "Window2.cpp"

int main()
{
  Window w1(0, 0, 10, 10);
  double a = w1.GetDisplayArea();
  cout << "Window area: " << a << endl;
  Window w2(0, 0, 10);
  double a2 = w2.GetDisplayArea();
  cout << "Window (round) area: " << a2 << endl;
}
