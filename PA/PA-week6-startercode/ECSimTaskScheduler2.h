//
//  ECSimTaskScheduler2.h
//  
//
//  Created by Yufeng Wu on 2/11/23.
//

#ifndef ECSimTaskScheduler2_h
#define ECSimTaskScheduler2_h

#include "ECSimTaskScheduler.h"
#include <map>

// Now define your new schedulers here...

//***********************************************************
// Longest wait-time first scheduler: choose the task that has waited the longest so far; break ties by the order of requests receiving
class ECSimLWTFTaskScheduler : public ECSimTaskScheduler
{
public:
    ECSimLWTFTaskScheduler();
    
    ECSimTask * ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const;
};

//***********************************************************
// Priority-based scheduler. By default, each task has the same priority 0; this priorty can be set (the smaller the higher priority, as in Unix/Linux).
class ECSimPriorityScheduler : public ECSimTaskScheduler
{
public:
    ECSimPriorityScheduler();
    
    ECSimTask * ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const;  
};

//***********************************************************
// Round-robin scheduler: the task having run the fewest in the past, get the highest priority
class ECSimRoundRobinTaskScheduler : public ECSimTaskScheduler
{
public:
    ECSimRoundRobinTaskScheduler();

    // int ECSimRoundRobinTaskScheduler :: Simulate(int duration);

    ECSimTask * ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const;

    // ECSimTask * ChooseTaskToSchedule2(const std::vector<ECSimTask *> &listReadyTasks);
    
// private:
    // std::map<ECSimTask *, int> mapTaskToRunTime;

    // std::vector<ECSimTask *> listTasks;
    // std::vector<int> listRunTime;
};


#endif /* ECSimTaskScheduler2_h */
