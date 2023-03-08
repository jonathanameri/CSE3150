//
//  ECSimTaskScheduler2.cpp
//  
//
//

#include <vector>
#include <iostream>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

#include "ECSimTaskScheduler2.h"
#include "ECSimTask.h"


ECSimLWTFTaskScheduler :: ECSimLWTFTaskScheduler() {}


ECSimTask * ECSimLWTFTaskScheduler :: ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const
{
    int longestWait = -1;
    int longestWaitIndex = -1;
    for (int i = 0; i < listReadyTasks.size(); i++)
    {
        if (listReadyTasks[i]->GetTotWaitTime() > longestWait) 
        {
            longestWait = listReadyTasks[i]->GetTotWaitTime();
            longestWaitIndex = i;
        }
    }
    if (longestWaitIndex == -1)
    {
        return NULL;
    }
    return listReadyTasks[longestWaitIndex];

}



ECSimPriorityScheduler :: ECSimPriorityScheduler() {}

ECSimTask * ECSimPriorityScheduler :: ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const
{
    int highestPriority = INT_MAX;
    int highestPriorityIndex = INT_MAX;
    for (int i = 0; i < listReadyTasks.size(); i++)
    {
        if (listReadyTasks[i]->GetPriority() < highestPriority) 
        {
            highestPriority = listReadyTasks[i]->GetPriority();
            highestPriorityIndex = i;
        }
    }
    if (highestPriorityIndex == INT_MAX)
    {
        return NULL;
    }
    return listReadyTasks[highestPriorityIndex];
}




ECSimRoundRobinTaskScheduler :: ECSimRoundRobinTaskScheduler() {}



ECSimTask * ECSimRoundRobinTaskScheduler :: ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const
{
    static map<ECSimTask *, int> mapTasks;

    if (listReadyTasks.size() == 0){
        return NULL;
    }

    for(auto x : listReadyTasks)
    {
        if (mapTasks.find(x) == mapTasks.end()){
            mapTasks[x] = 0;
        }

    }
    
    int shortestRunTime = INT_MAX;
    ECSimTask* res = NULL;
    vector<ECSimTask*> listTasks;
    for(auto it : mapTasks)
    {
        if(it.second < shortestRunTime && (std::find(listReadyTasks.begin(), listReadyTasks.end(), it.first) != listReadyTasks.end()))
        {
            // listTasks.push_back(it->first);
            shortestRunTime = it.second;
            // res = it->first;
        }
    }
    for(int i = 0; i < listReadyTasks.size(); i++)
    {
        if(mapTasks[listReadyTasks[i]] == shortestRunTime )
        {
            listTasks.push_back(listReadyTasks[i]);
            // shortestRunTime = it->second;
            res = listReadyTasks[i];
        }
    }

    for(int i = 0; i < listReadyTasks.size(); i++)
    {
        if (std::find(listTasks.begin(), listTasks.end(), listReadyTasks[i]) != listTasks.end()){
            res = listReadyTasks[i];
            mapTasks[listReadyTasks[i]] = mapTasks[listReadyTasks[i]] + 1;
            break;
        }
    }

    cout << "Current time: " << GetTime() << endl;
    for (int i = 0; i < listReadyTasks.size(); i++)
    {
        cout << "Task " << listReadyTasks[i]->GetId() << " has " << mapTasks[listReadyTasks[i]] << " ticks" << endl;
    }
    cout << res->GetId() << " is the selected task" << endl;

    return res;

}