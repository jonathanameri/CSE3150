#include "ECOrganization.cpp"
#include <iostream>
using namespace std;

int main()
{
  ECDepartment *pCSE = new ECDepartment(100);
  ECDepartment *pME = new ECDepartment(200);
  ECOffice *pDeanOffice = new ECOffice(10);
  ECCompositeUnit *schoolOfEngr = new ECCompositeUnit;
  schoolOfEngr->AddChild(pCSE);
  schoolOfEngr->AddChild(pME);
  schoolOfEngr->AddChild(pDeanOffice);
  ECDepartment *pMath = new ECDepartment(150);
  ECDepartment *pChemistry = new ECDepartment(250);
  ECCompositeUnit *schoolOfScience = new ECCompositeUnit;
  schoolOfScience->AddChild(pMath);
  schoolOfScience->AddChild(pChemistry);
  //ASSERT_EQ(schoolOfScience->GetBudget(), 400);
  cout << "School of Engineering budget: " << schoolOfScience->GetBudget() << endl;
  ECOffice *pAdmission = new ECOffice(10);
  ECCompositeUnit university;
  university.AddChild(pAdmission);
  university.AddChild(schoolOfEngr);
  university.AddChild(schoolOfScience);
  //ASSERT_EQ(university.GetBudget(), 720);
  cout << "University budget: " << university.GetBudget() << endl;
}
