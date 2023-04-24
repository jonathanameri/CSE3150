// just include the cpp file; it is a hack; don't do this in your code
#include "ECScheduler.cpp"
#include <iostream>
using namespace std;

int main()
{
  ECScheduler::Instance().StartTask(1);
//  ASSERT_EQ(ECScheduler::Instance().GetNumRunTasks(),1);
  cout << "Adding task 1: number of tasks: " << ECScheduler::Instance().GetNumRunTasks() << endl;
  ECScheduler::Instance().StartTask(2);
  //ASSERT_EQ(ECScheduler::Instance().GetNumRunTasks(),2);
  cout << "Adding task 2: number of tasks: " << ECScheduler::Instance().GetNumRunTasks() << endl;
  ECScheduler::Instance().StartTask(3);
  ECScheduler::Instance().StartTask(5);
  ECScheduler::Instance().StartTask(8);
  ECScheduler::Instance().StopTask(5);
  //ASSERT_EQ(ECScheduler::Instance().GetNumRunTasks(),4);
  cout << "Finally, number of tasks: " << ECScheduler::Instance().GetNumRunTasks() << endl;
}
