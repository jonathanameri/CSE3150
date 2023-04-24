// implement a task scheduler based on the Singleton pattern
#include <set>

class ECScheduler
{
public:
  static ECScheduler& Instance() 
  {
    static ECScheduler instance;
    return instance;
  }

  void StartTask(int id) { setIDs.insert(id);}
  void StopTask(int id) { setIDs.erase(id); }
  int GetNumRunTasks() const { return setIDs.size(); }
  
private:
  ECScheduler(){}
  std::set<int> setIDs; //set of task ids
};
