//
//  ECCampusSimulator.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECCampusSimulator.h"
#include "ECSimOrganization.h"
#include "ECSimHuman.h"

using namespace std;
// Your code here
ECSimEntity::ECSimEntity(int id){
    _id = id;
    _balance = 0;
}
ECSimEntity :: ~ ECSimEntity () {}
void ECSimEntity::Paid (int amt) { 
    _balance += amt ; 
}
void ECSimEntity::Charged (int amt) {
    if (_balance - amt < 0){
        // std::cout<<"Entity "<<_id<<" is bankrupt"<<std::endl;
        throw std::string("BANKRUPT");
    }
    _balance -= amt; 
}
int ECSimEntity::GetBalance () const { 
    return _balance; 
}
int ECSimEntity::GetID () const { 
    return _id; 
}
ECCampusSimScript::ECCampusSimScript(){}
void ECCampusSimScript::AddSimEvt(int idSender, int idReceiver){
    std::pair<int,int> event;
    event.first = (idSender);
    event.second = (idReceiver);
    listEvents.push_back(event);
}
void ECCampusSimScript::EndofDay(){
    listEvents.push_back(std::pair<int,int>(-1,-1));
}
ECCampusSimulator::ECCampusSimulator(){}
ECCampusSimulator::~ECCampusSimulator(){}
void ECCampusSimulator::Simulate(const ECCampusSimScript &script){
    //iterate through all events
    for(auto &event : script.listEvents){
        //Get sender and receiver IDs
        int senderID = event.first;
        int receiverID = event.second;
        if(event.first == -1 && event.second == -1){
            //End of day
            //Subtract budget from organization (DOES NOT TRANSFER JUST DELETES)
            for(auto &item : _listSimItems){
                if(dynamic_cast<Organization*>(item)){
                    Organization *org = dynamic_cast<Organization*>(item);
                    org->Charged(org->GetBudgetForDay());
                }
            }
            //Event is complete, onto the next
            continue;
        }
        //Retrieve the sender and receiver instances
        ECSimEntity *sender = nullptr;
        ECSimEntity *receiver = nullptr;
        for (auto &item : _listSimItems)
        {
            if (item->GetID() == senderID)
            {
                sender = item;
            }
            if (item->GetID() == receiverID)
            {
                receiver = item;
            }
        }
        //Generic call to request
        sender->Request(receiver);
    }
}
void ECCampusSimulator::AddSimItem(ECSimEntity *pe){
    //Insert should handle duplicates because _listSimItems is a set
    _listSimItems.insert(pe);
}