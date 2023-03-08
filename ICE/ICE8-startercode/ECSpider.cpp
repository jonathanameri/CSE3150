#include "ECSpider.h"
#include <iostream>
using namespace std;


// Spider
ECSpider :: ECSpider() : ECLife(2) 
{
}

ECSpider :: ECSpider(double life) : ECLife(life) 
{
}

void ECSpider :: Weave()
{
    // say I am working
    cout << "Weave" << endl;
}

