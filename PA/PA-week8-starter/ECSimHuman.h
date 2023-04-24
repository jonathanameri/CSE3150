//
//  ECSimHuman.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//  Human related definitions in campus simulation


#ifndef ECSimHuman_h
#define ECSimHuman_h
#include "ECCampusSimulator.h"
#include <string>

class ECSimHR;
class ECSimDiningHall;
class ECSimRecCenter;
class ECSimLibrary;
class ECSimBursar;


//  Place all human related definitions here: ECSimStudent, ECSimEmployee, etc


class ECSimHuman : public ECSimEntity
{
public:
    ECSimHuman(int id);
    virtual ~ECSimHuman();

    // virtual void Paid(int amt);
    // virtual void Charged(int amt);

    // //Serve will be generic
    // virtual void Request(ECSimEntity *receiver);

    //Request will be overloaded for each type of entity
    // virtual void ServeStudent(ECSimStudent *sender);
    // virtual void ServeEmployee(ECSimEmployee *sender);
    // virtual void ServeBursar(ECSimBursar *sender);
    // virtual void ServeHR(ECSimHR *sender);
    // virtual void ServeLibrary(ECSimLibrary *sender);
    // virtual void ServeRecCenter(ECSimRecCenter *sender);
    // virtual void ServeDiningHall(ECSimDiningHall *sender);
};


//EMPLOYEE
class ECSimEmployee : public ECSimHuman
{
public:
    ECSimEmployee(int idEmployee);

    ~ECSimEmployee();
    
    // payrate: amount paid per day. If not set, not getting paid
    void SetPayrate(int rate);  
    int GetPayrate() const;

    //Serve will be generic
    virtual void Request(ECSimEntity *receiver);

    //Request will be overloaded for each type of entity
    virtual void ServeStudent(ECSimStudent *sender);
    virtual void ServeEmployee(ECSimEmployee *sender);
    // virtual void ServeBursar(ECSimBursar *sender);
    virtual void ServeHR(ECSimHR *sender);
    virtual void ServeLibrary(ECSimLibrary *sender);
    // virtual void ServeRecCenter(ECSimRecCenter *sender);
    // virtual void ServeDiningHall(ECSimDiningHall *sender);

    
private:
    int _payrate;
    
};




//STUDENT
class ECSimStudent : public ECSimHuman
{
public:
    // each student must have a distinct id
    ECSimStudent(int idStudent);

    //Serve will be generic
    virtual void Request(ECSimEntity *receiver);

    //Request will be overloaded for each type of entity
    virtual void ServeStudent(ECSimStudent *sender);
    virtual void ServeEmployee(ECSimEmployee *sender);
    virtual void ServeBursar(ECSimBursar *sender);
    // virtual void ServeHR(ECSimHR *sender);
    virtual void ServeLibrary(ECSimLibrary *sender);
    // virtual void ServeRecCenter(ECSimRecCenter *sender);
    // virtual void ServeDiningHall(ECSimDiningHall *sender);

 
};

#endif /* ECSimHuman_h */



/*

//Serve will be generic
    virtual void Request(ECSimEntity *receiver);

    //Request will be overloaded for each type of entity
    virtual void ServeStudent(ECSimEntity *sender);
    virtual void ServeEmployee(ECSimEntity *sender);
    virtual void ServeBursar(ECSimEntity *sender);
    virtual void ServeHR(ECSimEntity *sender);
    virtual void ServeLibrary(ECSimEntity *sender);
    virtual void ServeRecCenter(ECSimEntity *sender);
    virtual void ServeDiningHall(ECSimEntity *sender);

*/