//
//  ECSimHuman.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECSimHuman.h"
#include "ECSimOrganization.h"

//HUMAN
ECSimHuman::ECSimHuman(int id) : ECSimEntity(id) {}
ECSimHuman::~ECSimHuman() {}
//STUDENT
ECSimStudent::ECSimStudent(int id) : ECSimHuman(id) {}
void ECSimStudent::Request(ECSimEntity *receiver){
    receiver->ServeStudent(this);
}
void ECSimStudent::ServeBursar(ECSimBursar *sender){
    sender->Charged(1000);
    this->Paid(1000);
}
void ECSimStudent::ServeLibrary(ECSimLibrary *sender){}
void ECSimStudent::ServeEmployee(ECSimEmployee *sender){
}
void ECSimStudent::ServeStudent(ECSimStudent *sender){
}
//EMPLOYEE
ECSimEmployee::ECSimEmployee(int id) : ECSimHuman(id) {}
ECSimEmployee::~ECSimEmployee() {}
void ECSimEmployee::SetPayrate(int rate){
    _payrate = rate;
}
int ECSimEmployee::GetPayrate() const{
    return _payrate;
}

void ECSimEmployee::Request(ECSimEntity *receiver){
    receiver->ServeEmployee(this);
}
void ECSimEmployee::ServeLibrary(ECSimLibrary *sender){
}
void ECSimEmployee::ServeHR(ECSimHR *sender){
    this->Paid(2000);
    sender->Charged(2000);
}
void ECSimEmployee::ServeEmployee(ECSimEmployee *sender){
}
void ECSimEmployee::ServeStudent(ECSimStudent *sender){
}