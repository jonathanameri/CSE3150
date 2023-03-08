#ifndef _EC_LIFE_H
#define _EC_LIFE_H

#include <string>

// Life 
class ECLife
{
public:
  ECLife(double life) : lifeRemain(life) {}
  double GetLifeRemain() const { return lifeRemain; }

private:
  double lifeRemain;
};

#endif
