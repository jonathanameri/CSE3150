#include "ECMotorVehicle.h"
#include <iostream>
using namespace std;

int main()
{
  ECCar car(EC_ENGINE_4CYL, 17);
  double p1 = car.GetPrice();
  // 2640
  cout << "Car 1: " << p1 << endl;
  ECCar car2(EC_ENGINE_ELECTRIC, 19);
  double p2 = car2.GetPrice();
  // 6270
  cout << "Car 2: " << p2 << endl;
  ECTruck tru(18, 19);
  double p3 = tru.GetPrice();
  // 6372
  cout << "Truck: " << p3 << endl;
  ECMotocycle mot1;
  double p4 = mot1.GetPrice();
  // 2127.5
  cout << "Motocycle: " << p4 << endl;
}

