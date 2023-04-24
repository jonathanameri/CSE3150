#include <iostream>
using namespace std;
#include "Window1.cpp"

int main()
{
  Window w(0, 0, 10, 10);
  double a = w.GetDisplayArea();
  cout << "Window area: " << a << endl;
}
