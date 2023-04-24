//
//  ECCampusSimulator.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#ifndef ECCampusSimulator_h
#define ECCampusSimulator_h

#include <vector>
#include <set>
#include <string>
#include <iostream>


class ECSimHR;
class ECSimDiningHall;
class ECSimRecCenter;
class ECSimLibrary;
class ECSimBursar;
class ECSimEmployee;
class ECSimStudent;
class Organization;


// ***********************************************************
// Simulation script: a sequence of events to simulate

class ECSimEntity{
public:
    ECSimEntity(int id);
    virtual ~ECSimEntity();

    virtual void Paid(int amt);
    virtual void Charged(int amt);

    int GetBalance() const;
    int GetID() const;


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

    //Serve will be generic
    virtual void Request(ECSimEntity *receiver){
        throw std::string("BAD REQUEST");
    }

    //Request will be overloaded for each type of entity
    virtual void ServeStudent(ECSimStudent *sender){
        throw std::string("BAD REQUEST");
    }
    virtual void ServeEmployee(ECSimEmployee *sender){
        throw std::string("BAD REQUEST");
    }
    virtual void ServeBursar(ECSimBursar *sender){
        throw std::string("BAD REQUEST");
    }
    virtual void ServeHR(ECSimHR *sender){
        throw std::string("BAD REQUEST");
    }
    virtual void ServeLibrary(ECSimLibrary *sender){
        throw std::string("BAD REQUEST");
    }
    virtual void ServeRecCenter(ECSimRecCenter *sender){
        throw std::string("BAD REQUEST");
    }
    virtual void ServeDiningHall(ECSimDiningHall *sender){
        throw std::string("BAD REQUEST");
    }

protected:
    int _id;
    int _balance;
};



class ECCampusSimScript
{
public:
    ECCampusSimScript();
    // Mark the end of a day; unitl calling it again, any events before are the current day
    void EndofDay();
    // Add a simulation event. An event is from a sender (with type and id) to a receiver (with type and id). Also evtCode is the code of the type of event between these two kinds of entities. For example, a student (sender) enrolls (event code 0) in univerisity (receiver)
    void AddSimEvt(int idSender, int idReceiver);
    
    // Your code here...

    //public so that Simulator can access it
    std::vector< std::pair<int,int> > listEvents;
};






// ***********************************************************
// Simulator

class ECCampusSimulator
{
public:
    ECCampusSimulator();
    ~ECCampusSimulator();
    void Simulate(const ECCampusSimScript &script);
    
    // Add a new sim item
    void AddSimItem(ECSimEntity *pe);

    // Your code goes here..
private:
    std::set<ECSimEntity *> _listSimItems;

};

#endif /* ECCampusSimulator_h */
