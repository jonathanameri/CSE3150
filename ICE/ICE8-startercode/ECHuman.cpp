#include "ECHuman.h"
#include <iostream>
using namespace std;

// Human 
ECHuman :: ECHuman() : ECLife(70) 
{
}

ECHuman :: ECHuman(double life) : ECLife(life) 
{
}

void ECHuman :: Run()
{
    // say I am working
    cout << "Run" << endl;
}

