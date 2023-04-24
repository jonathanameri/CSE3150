//
//  ECSimOrganization.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECSimOrganization.h"
#include "ECSimHuman.h"

// Your code goes here

//ORGANIZATION
Organization::Organization(int id) : _budgetForDay(0), ECSimEntity(id) {}
Organization::~Organization() {}
void Organization::SetBudgetForDay(int budget){
    _budgetForDay = budget;
}

int Organization::GetBudgetForDay() const{
    return _budgetForDay;
}
//BURSAR
ECSimBursar::ECSimBursar(int id) : Organization(id){}

void ECSimBursar::SetTuition(int tuitionIn){
    _tuition = tuitionIn;
}
int ECSimBursar::GetTuition() const{
    return _tuition;
}

void ECSimBursar::Request(ECSimEntity *pReceiver){
    pReceiver->ServeBursar(this);
}
void ECSimBursar::ServeStudent(ECSimStudent *sender){
    sender->Charged(_tuition);
    this->Paid(_tuition);
}
void ECSimBursar::ServeEmployee(ECSimEmployee *sender){
}
void ECSimBursar::ServeBursar(ECSimBursar *sender){
    sender->Paid(sender->GetBudgetForDay());
    this->Charged(sender->GetBudgetForDay());
}
void ECSimBursar::ServeLibrary(ECSimLibrary *sender){
    sender->Paid(sender->GetBudgetForDay());
    this->Charged(sender->GetBudgetForDay());
}
void ECSimBursar::ServeRecCenter(ECSimRecCenter *sender){
    sender->Paid(sender->GetBudgetForDay());
    this->Charged(sender->GetBudgetForDay());
}
void ECSimBursar::ServeDiningHall(ECSimDiningHall *sender){
    sender->Paid(sender->GetBudgetForDay());
    this->Charged(sender->GetBudgetForDay());
}
void ECSimBursar::ServeHR(ECSimHR *sender){
    sender->Paid(sender->GetBudgetForDay());
    this->Charged(sender->GetBudgetForDay());
}

//HR
ECSimHR::ECSimHR(int id) : Organization(id){}

void ECSimHR::Request(ECSimEntity *receiver){
    receiver->ServeHR(this);
}
void ECSimHR::ServeStudent(ECSimStudent *sender){
}
void ECSimHR::ServeEmployee(ECSimEmployee *sender){
    this->Charged(sender->GetPayrate());
    sender->Paid(sender->GetPayrate());
}
void ECSimHR::ServeLibrary(ECSimLibrary *sender){
}
//LIBRARY
ECSimLibrary::ECSimLibrary(int id) : Organization(id){}

void ECSimLibrary::Request(ECSimEntity *receiver){
    receiver->ServeLibrary(this);
}
void ECSimLibrary::ServeStudent(ECSimStudent *sender){
}
void ECSimLibrary::ServeEmployee(ECSimEmployee *sender){
}
void ECSimLibrary::ServeBursar(ECSimBursar *sender){
}
void ECSimLibrary::ServeLibrary(ECSimLibrary *sender){
}
void ECSimLibrary::ServeRecCenter(ECSimRecCenter *sender){
}
void ECSimLibrary::ServeDiningHall(ECSimDiningHall *sender){
}
void ECSimLibrary::ServeHR(ECSimHR *sender){
}

//RECREATION CENTER
ECSimRecCenter::ECSimRecCenter(int id) : Organization(id){}
void ECSimRecCenter::Request(ECSimEntity *receiver){
    receiver->ServeRecCenter(this);
}
void ECSimRecCenter::ServeStudent(ECSimStudent *sender){
    sender->Charged(10);
    this->Paid(10);
}
void ECSimRecCenter::ServeEmployee(ECSimEmployee *sender){
    sender->Charged(20);
    this->Paid(20);
}
void ECSimRecCenter::ServeBursar(ECSimBursar *sender){
    sender->Paid(this->GetBalance());
    this->Charged(this->GetBalance());
}
void ECSimRecCenter::ServeLibrary(ECSimLibrary *sender){
}
//DINING HALL
ECSimDiningHall::ECSimDiningHall(int id) : Organization(id){}

void ECSimDiningHall::Request(ECSimEntity *receiver){
    receiver->ServeDiningHall(this);
}
void ECSimDiningHall::ServeStudent(ECSimStudent *sender){
    sender->Charged(5);
    this->Paid(5);
}
void ECSimDiningHall::ServeEmployee(ECSimEmployee *sender){
    sender->Charged(10);
    this->Paid(10);
}
void ECSimDiningHall::ServeBursar(ECSimBursar *sender){
    sender->Paid(this->GetBalance());
    this->Charged(this->GetBalance());
}
void ECSimDiningHall::ServeLibrary(ECSimLibrary *sender){
}