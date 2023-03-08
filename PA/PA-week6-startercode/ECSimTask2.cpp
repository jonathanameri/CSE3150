//
//  ECSimTask2.cpp
//  
//
//

#include "ECSimTask2.h"
#include <iostream>

// ********************* MULTI INTERVAL TASK *********************

ECMultiIntervalsTask :: ECMultiIntervalsTask(const std::string &tid) : ECSimTask(tid)
{
}

// Add new interval by appending the time start and time end vectors
void ECMultiIntervalsTask :: AddInterval(int tmStart, int tmEnd)
{
    tmStarts.push_back(tmStart);
    tmEnds.push_back(tmEnd);
}

bool ECMultiIntervalsTask :: IsReadyToRun(int tick) const
{
    // Check if the current tick is within any of the intervals
    for (int i = 0; i < tmStarts.size(); i++)
    {
        if (tick >= tmStarts[i] && tick <= tmEnds[i])
        {
            return true;
        }
    }
    return false;
}

bool ECMultiIntervalsTask :: IsFinished(int tick) const
{
    for (int i = 0; i < tmEnds.size(); i++)
    {
        if (tick <= tmEnds[i])
        {
            return false;
        }
    }
    return true;
}


// ********************* HARD INTERVAL TASK *********************

//Not positive that this is correct, concerned about 'ECSimTask(tid)'
ECHardIntervalTask :: ECHardIntervalTask(const std::string &tid, int tmStart, int tmEnd) : ECSimTask(tid), tmStart(tmStart), tmEnd(tmEnd)
{
}

bool ECHardIntervalTask :: IsReadyToRun(int tick) const
{
    // Check if the current tick is within the interval
    if (tick == tmStart && tick <= tmEnd)
    {
        return true;
    }
    return false;
}

bool ECHardIntervalTask :: IsFinished(int tick) const
{
    if (tick >= tmEnd)
    {
        return true;
    }
    return false;
}



// ********************* CONSECUTIVE INTERVAL TASK *********************

ECConsecutiveIntervalTask :: ECConsecutiveIntervalTask(const std::string &tid, int tmStart, int tmEnd) : ECSimTask(tid), tmStart(tmStart), tmEnd(tmEnd), numExec(0), running(false), wait(false)
{}

void ECConsecutiveIntervalTask :: Run(int tick, int duration) 
{
    // std::cout << "tmExec " << tmExec << std::endl;
    if(!running)
        numExec++;
    running = true;
    ECSimTask :: Run(tick, duration);
}
void ECConsecutiveIntervalTask :: Wait(int tick, int duration) 
{
    if(running){
        running = false;
        wait = true;
    }
    
    ECSimTask :: Wait(tick, duration);
}
// Is task ready to run at certain time? tick: the current clock time (in simulation unit)
bool ECConsecutiveIntervalTask :: IsReadyToRun(int tick) const
{
    if (wait) return false;
    if (tick >= tmStart && tick <= tmEnd && (running || numExec == 0))
    {
        return true;
    }
    return false;
}
// Is task complete at certain time? If so, scheduler may remove it from the list. tick the current clock time (in simulation unit)
bool ECConsecutiveIntervalTask :: IsFinished(int tick) const
{
    // std::cout<< "if" << std::endl;
    if (numExec > 1 || wait) return true;
    else if (tick < tmEnd)
    {
        return false;
    }
    return true;
}

//CONSECUTIVE DONT WORK!CONSECUTIVE DONT WORK!CONSECUTIVE DONT WORK!CONSECUTIVE DONT WORK!CONSECUTIVE DONT WORK!CONSECUTIVE DONT WORK!
// FINISH THIS JOHNSON!!!!!!!!!!!!!!^^^^^^^^^^^^^^^^^^^^^^!!!!!!!!!!!!!!!!!!!!^^^^^^^
// FINISH THIS JOHNSON!!!!!!!!!!!!!!^^^^^^^^^^^^^^^^^^^^^^!!!!!!!!!!!!!!!!!!!!^^^^^^^
// FINISH THIS JOHNSON!!!!!!!!!!!!!!^^^^^^^^^^^^^^^^^^^^^^!!!!!!!!!!!!!!!!!!!!^^^^^^^
// FINISH THIS JOHNSON!!!!!!!!!!!!!!^^^^^^^^^^^^^^^^^^^^^^!!!!!!!!!!!!!!!!!!!!^^^^^^^
// FINISH THIS JOHNSON!!!!!!!!!!!!!!^^^^^^^^^^^^^^^^^^^^^^!!!!!!!!!!!!!!!!!!!!^^^^^^^
// FINISH THIS JOHNSON!!!!!!!!!!!!!!^^^^^^^^^^^^^^^^^^^^^^!!!!!!!!!!!!!!!!!!!!^^^^^^^
// FINISH THIS JOHNSON!!!!!!!!!!!!!!^^^^^^^^^^^^^^^^^^^^^^!!!!!!!!!!!!!!!!!!!!^^^^^^^
// FINISH THIS JOHNSON!!!!!!!!!!!!!!^^^^^^^^^^^^^^^^^^^^^^!!!!!!!!!!!!!!!!!!!!^^^^^^^

ECPeriodicTask :: ECPeriodicTask(const std::string &tid, int tmStart, int runLen, int sleepLen) : ECSimTask(tid), tmStart(tmStart), runLen(runLen), sleepLen(sleepLen)
{}


bool ECPeriodicTask::IsReadyToRun(int tick) const
{
    if (tick < tmStart)
    {
        return false;
    }
    return runLen > ((tick - tmStart) % (runLen + sleepLen));
}

bool ECPeriodicTask :: IsFinished(int tick) const
{
    return false;
}