//
//  ECSimOrganization.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#ifndef ECSimOrganization_h
#define ECSimOrganization_h

#include "ECCampusSimulator.h"

class ECSimEmployee;
class ECSimStudent;


//  Place simulation organization related code here...
//  Consider adding base class here...

// ***********************************************************
// University bursar office: handling enrollment related matters

class Organization : public ECSimEntity
{
public:
    Organization(int id);
    // each organization has an unique ID
    virtual ~Organization();

    // virtual void Paid(int amt);
    // virtual void Charged(int amt);

    void SetBudgetForDay(int budget);
    int GetBudgetForDay() const;



    // //Serve will be generic
    // virtual void Request(ECSimEntity *receiver);

    // //Request will be overloaded for each type of entity
    // virtual void ServeStudent(ECSimStudent *sender);
    // virtual void ServeEmployee(ECSimEmployee *sender);
    // virtual void ServeBursar(ECSimBursar *sender);
    // virtual void ServeHR(ECSimHR *sender);
    // virtual void ServeLibrary(ECSimLibrary *sender);
    // virtual void ServeRecCenter(ECSimRecCenter *sender);
    // virtual void ServeDiningHall(ECSimDiningHall *sender);

private:
    int _budgetForDay;
};


class ECSimBursar : public Organization
{
public:
    // each organization has an unique ID
    ECSimBursar(int bid);
    
    // set tuition rate; same tuition for everyone; tuition is form the entire simulation period (say semester)
    void SetTuition(int tuitionIn);
    int GetTuition() const;



    //Serve will be generic
    void Request(ECSimEntity *receiver);

    //Request will be overloaded for each type of entity
    void ServeStudent(ECSimStudent *sender);
    void ServeEmployee(ECSimEmployee *sender);
    void ServeBursar(ECSimBursar *sender);
    void ServeHR(ECSimHR *sender);
    void ServeLibrary(ECSimLibrary *sender);
    void ServeRecCenter(ECSimRecCenter *sender);
    void ServeDiningHall(ECSimDiningHall *sender);

private:
    int _tuition;


};

// ***********************************************************
// Human resource (HR)

class ECSimHR : public Organization
{
public:
    // each organization has an unique ID
    ECSimHR( int tid );



    //Serve will be generic
    virtual void Request(ECSimEntity *receiver);

    //Request will be overloaded for each type of entity
    virtual void ServeStudent(ECSimStudent *sender);
    virtual void ServeEmployee(ECSimEmployee *sender);
    // virtual void ServeBursar(ECSimBursar *sender);
    // virtual void ServeHR(ECSimHR *sender);
    virtual void ServeLibrary(ECSimLibrary *sender);
    // virtual void ServeRecCenter(ECSimRecCenter *sender);
    // virtual void ServeDiningHall(ECSimDiningHall *sender);
    
};

// ***********************************************************
// Dining hall

class ECSimDiningHall : public Organization
{
public:
    // each organization has an unique ID
    ECSimDiningHall( int tid );

    

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

// ***********************************************************
// Rec center

class ECSimRecCenter : public Organization
{
public:
    // each organization has an unique ID
    ECSimRecCenter( int tid );

    
    
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

// ***********************************************************
// Library

class ECSimLibrary : public Organization
{
public:
    // each organization has an unique ID
    ECSimLibrary(int bid);

    
    
    //Serve will be generic
    virtual void Request(ECSimEntity *receiver);

    //Request will be overloaded for each type of entity
    virtual void ServeStudent(ECSimStudent *sender);
    virtual void ServeEmployee(ECSimEmployee *sender);
    virtual void ServeBursar(ECSimBursar *sender);
    virtual void ServeHR(ECSimHR *sender);
    virtual void ServeLibrary(ECSimLibrary *sender);
    virtual void ServeRecCenter(ECSimRecCenter *sender);
    virtual void ServeDiningHall(ECSimDiningHall *sender);
};

#endif /* ECSimOrganization_h */
