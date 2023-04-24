#ifndef _EC_MOTOR_VEHICLE_H
#define _EC_MOTOR_VEHICLE_H

#include <vector>
#include "ECVehicleParts.h"

// Generic vehicle
class ECMotorVehicle
{
public:
  ECMotorVehicle();
  virtual ~ECMotorVehicle();
  double GetPrice() const;

protected:
  void SetEngine(ECEngine *pe);
  void AddWheel(ECWheel *pw);
  void AddLight(ECLight *pl);
  virtual double GetDiscount() const = 0;
  virtual double GetTaxRate() const = 0;

private:
  // note: prefer defining as a pointer (so you can change say from 4 cylinders to 6 cyl)
  ECEngine *pEngine;
  std::vector<ECWheel *> listWheels;
  std::vector<ECLight *> listLights;
};

// Car
class ECCar : public ECMotorVehicle
{
public:
  ECCar(EC_ENGINE_TYPE t, int szWheel);

protected:
  virtual double GetDiscount() const;
  virtual double GetTaxRate() const;
};

// Truck 
class ECTruck : public ECMotorVehicle
{
public:
  ECTruck(int numWheels, int szWheel);

protected:
  virtual double GetDiscount() const;
  virtual double GetTaxRate() const;
};

// Motocycle
class ECMotocycle : public ECMotorVehicle
{
public:
  ECMotocycle();

protected:
  virtual double GetDiscount() const;
  virtual double GetTaxRate() const;
};

#endif