#include <iostream>
using namespace std;

// base class
class ECLife
{
public:
  virtual ~ECLife() {}
  void Die() {}
};

// derived class
class ECCat : public ECLife
{
public:
  void Mew() { }
};

// derived class 2
class ECDog : public ECLife
{
public:
  void Bark() { }
};

// test code
int main()
{
  ECLife *pl1 = new ECCat;
  ECLife *pl2 = new ECDog;
  ECLife *pl3 = new ECCat;

  // How to tell what kind of life it is?
  // How to tell if say pl1 and pl2 point to the same kind of life?

  ECCat *pc = dynamic_cast<ECCat *>(pl1);
  if(pc != NULL)
  {
    pc->Mew();
  }

  const type_info &x1 = typeid(*pl1);
  cout << "x1: " << x1.name() << endl;

  if ( typeid(*pl1) != typeid(*pl2))
  {
    cout << "DIFFERENT!" << endl;
  }

  delete pl1;
  delete pl2;
  delete pl3; 
}

