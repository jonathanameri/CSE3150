#ifndef _EC_VEHICLE_PARTS_H
#define _EC_VEHICLE_PARTS_H

class ECPart
{
public:
  ECPart() {}
  virtual ~ECPart() {}
  virtual double GetCost() const = 0;
};
// Engine type
enum EC_ENGINE_TYPE
{
  EC_ENGINE_4CYL = 0,
  EC_ENGINE_6CYL = 1,
  EC_ENGINE_ELECTRIC = 2
};

// Engine
class ECEngine : public ECPart
{
public:
  ECEngine(EC_ENGINE_TYPE type) : m_type(type) {}
  // what to put here?
  // return the price of the engine based on type
  double GetCost() const
  {
    if (m_type == EC_ENGINE_4CYL)
    {
      return 1000;
    }
    else if (m_type == EC_ENGINE_6CYL)
    {
      return 1500;
    }
    else if (m_type == EC_ENGINE_ELECTRIC)
    {
      return 3000;
    }
    throw "Invalid engine type";
    return 0;
  }

private:
  EC_ENGINE_TYPE m_type;
};

// Wheel
class ECWheel : public ECPart
{
public:
  ECWheel(int size) : m_size(size) {}

  double GetCost() const
  {
    if (m_size == 17)
    {
      return 100;
    }
    else if (m_size == 19)
    {
      return 150;
    }
    throw "Invalid wheel size";
    return 0;
  }

private:
  int m_size;
};

// light
class ECLight : public ECPart
{
public:
  ECLight() {}

  double GetCost() const
  {
    return 50;
  }
};

#endif
