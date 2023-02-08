#include <iostream>
#include <string>
using namespace std;

extern int ECTernary2(int x);

int main()
{
  int x = 0;
  int y = ECTernary2(x);
  cout << y << endl;

  x = 1;
  y = ECTernary2(x);
  cout << y << endl;
  
  x = 2;
  y = ECTernary2(x);
  cout << y << endl;

  try
  {
    x= 4;
    y = ECTernary2(x);
    cout << y << endl;
  }
  catch(string ex)
  {
    cout << "Exception: " << ex << endl;
  }

}

