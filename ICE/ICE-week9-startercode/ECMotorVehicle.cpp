#include <cstdio>
#include "ECMotorVehicle.h"

// Generic vehicle
ECMotorVehicle ::ECMotorVehicle() : pEngine(NULL)
{
}
ECMotorVehicle ::~ECMotorVehicle()
{
    // delete all parts
    delete pEngine;
    for (auto x : listWheels)
    {
        delete x;
    }
    for (auto x : listLights)
    {
        delete x;
    }
}

double ECMotorVehicle ::GetPrice() const
{
    // get the total cost of parts first
    double tot = 0.0;
    if (pEngine != NULL)
    {
        tot += pEngine->GetCost();
    }
    for (auto x : listWheels)
    {
        tot += x->GetCost();
    }
    for (auto x : listLights)
    {
        tot += x->GetCost();
    }
    // multiply by 1.5
    tot *= 1.5;
    // subtract discounts
    tot -= GetDiscount();
    // add tax
    tot *= 1.0 + GetTaxRate();
    return tot;
}

void ECMotorVehicle ::SetEngine(ECEngine *pe)
{
    // ingore the old engine for now
    pEngine = pe;
}

void ECMotorVehicle ::AddWheel(ECWheel *pw)
{
    listWheels.push_back(pw);
}

void ECMotorVehicle ::AddLight(ECLight *pl)
{
    listLights.push_back(pl);
}

// Car
ECCar ::ECCar(EC_ENGINE_TYPE t, int szWheel)
{
    ECEngine *pe = new ECEngine(t);
    SetEngine(pe);
    for (int i = 0; i < 4; ++i)
    {
        ECWheel *pw = new ECWheel(szWheel);
        AddWheel(pw);
    }
    for (int i = 0; i < 4; ++i)
    {
        ECLight *pl = new ECLight;
        AddLight(pl);
    }
}

double ECCar ::GetDiscount() const
{
    return 0.0;
}

double ECCar ::GetTaxRate() const
{
    return 0.1;
}

// Truck 
ECTruck ::ECTruck(int numWheels, int szWheel)
{
    ECEngine *pe = new ECEngine(EC_ENGINE_6CYL);
    SetEngine(pe);
    for (int i = 0; i < numWheels; ++i)
    {
        ECWheel *pw = new ECWheel(szWheel);
        AddWheel(pw);
    }
    for (int i = 0; i < 8; ++i)
    {
        ECLight *pl = new ECLight;
        AddLight(pl);
    }
}

double ECTruck ::GetDiscount() const
{
    return 1000.0;
}
double ECTruck ::GetTaxRate() const
{
    return 0.08;
}

// Motocycle
ECMotocycle ::ECMotocycle()
{
    ECEngine *pe = new ECEngine(EC_ENGINE_4CYL);
    SetEngine(pe);
    for (int i = 0; i < 2; ++i)
    {
        ECWheel *pw = new ECWheel(17);
        AddWheel(pw);
    }
    for (int i = 0; i < 2; ++i)
    {
        ECLight *pl = new ECLight;
        AddLight(pl);
    }
}

double ECMotocycle ::GetDiscount() const
{
    return 100;
}

double ECMotocycle ::GetTaxRate() const
{
    return 0.15;
}