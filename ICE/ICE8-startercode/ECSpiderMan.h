#ifndef _EC_SPIDERMAN_H
#define _EC_SPIDERMAN_H

#include "ECSpider.h"
#include "ECHuman.h"

// Spiderman 
class ECSpiderMan : public ECSpider, public ECHuman
{
public:
  ECSpiderMan(double life);

  // spiderman work to catch bad guys
  void Work();
};

#endif
