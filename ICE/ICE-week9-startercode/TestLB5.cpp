#include <iostream>
using namespace std;

#include "Lightbulb5.cpp"

template<class T>
void ASSERT_EQ(T x, T y)
{
  if( x == y )
  {
    cout << "Test passed: equal: " << x << "  " << y << endl;
  }
  else
  {
    cout << "Test FAILED: equal: " << x << "  " << y << endl;
  }
}

void Test1()
{
LightBulb bulb;
LightBulbButtonServer lbbs(bulb);
Button bt(&lbbs);
bt.Push();
ASSERT_EQ(bulb.IsOn(),true);
bt.Push();
ASSERT_EQ(bulb.IsOn(),false);
}

void Test2()
{
	LightBulb bulb;
	LightBulbButtonServer lbbs(bulb);
	Button bt(&lbbs);
	bt.Push();
	ASSERT_EQ(bulb.IsOn(),true);

	// test pump
	Pump pump;
	PumpButtonServer pbs(pump);
	bt.SetServer(&pbs);
	bt.Push();
	ASSERT_EQ(pump.IsOn(),true);
	// ensure the bulb is not affected
	ASSERT_EQ(bulb.IsOn(),true);
	bt.Push();
	ASSERT_EQ(pump.IsOn(),false);
}

void Test3()
{
	LightBulb bulb;
	LightBulbButtonServer lbbs(bulb);
	Button bt(&lbbs);
	bt.Push();
	ASSERT_EQ(bulb.IsOn(),true);

	// ensure button allows no object under control
	bt.SetServer(NULL);
	bt.Push();
	// bulb shouldn't be affected
	ASSERT_EQ(bulb.IsOn(),true);
}

int main()
{
  Test1();
  Test2();
  Test3();
}


