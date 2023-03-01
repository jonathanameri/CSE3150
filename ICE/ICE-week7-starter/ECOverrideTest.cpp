#include <iostream>
using namespace std;

// Class A
class A 
{
public:
  void foo() 
  {
    cout << "A\n";
  }
};

// Class B: subclass of A
class B : public A
{
public:
  void foo() 
  {
    cout << "B\n";
  }
};

void Test(A &a)
{
  a.foo();
}

int main()
{
  B b;
  Test(b);
//  A *pa = new B;
//  Test(*pa);
//  delete pa;
}
