#ifndef _EC_HUMAN_H
#define _EC_HUMAN_H

#include "ECLife.h"

// Human
class ECHuman : virtual public ECLife
{
public:
  ECHuman();
  ECHuman(double life);

  // work and consume energy
  void Run();

};

#endif
