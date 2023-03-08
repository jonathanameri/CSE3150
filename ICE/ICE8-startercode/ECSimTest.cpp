#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "ECSpider.h"
#include "ECHuman.h"
#include "ECSpiderMan.h"
using namespace std;

int main()
{
  // 
  ECSpider spider(1);
  ECHuman hum(100);
  ECSpiderMan sm(1000);

  // do something
  spider.Weave();
  hum.Run();
  sm.Work();

  // now do something more interesting
  vector<ECLife *> listEntities;
  listEntities.push_back(&spider);
  listEntities.push_back(&hum);
  listEntities.push_back(&sm);
  cout << "** List of life\n";
  for(auto x : listEntities)
  {
    cout << x->GetLifeRemain() << endl;
  }
}

