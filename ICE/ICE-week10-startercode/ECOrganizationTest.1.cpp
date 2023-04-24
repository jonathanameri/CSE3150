#include "ECOrganization.cpp"
#include <iostream>
using namespace std;

int main()
{
  ECDepartment *pCSE = new ECDepartment(100);
  ECDepartment *pME = new ECDepartment(200);
  ECOffice *pDeanOffice = new ECOffice(10);
  ECCompositeUnit schoolOfEngr;
  schoolOfEngr.AddChild(pCSE);
  schoolOfEngr.AddChild(pME);
  schoolOfEngr.AddChild(pDeanOffice);
//  ASSERT_EQ(schoolOfEngr.GetBudget(), 310);
  cout << "School budget: " << schoolOfEngr.GetBudget() << endl;
}
