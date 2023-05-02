
#include "ECCommand.h"

// ******************************************************
// Implement command history

ECCommandHistory :: ~ECCommandHistory()
{
    for(unsigned int i=0; i<listCommands.size(); ++i)
    {
        delete listCommands[i];
    }
    listCommands.clear();
    posCurrCmd = -1;
}

bool ECCommandHistory :: Undo()
{
    if (posCheckpoint < 0) return false;
    for(int i = 0; i < checkpoints[posCheckpoint]; i++){
        if( posCurrCmd < 0  )
        {
            return false;
        }
        listCommands[posCurrCmd]->UnExecute();
        --posCurrCmd;
    }
    --posCheckpoint;
    return true;
}

bool ECCommandHistory :: Redo()
{
    if(posCheckpoint >= (int)checkpoints.size()-1) return false;
    ++posCheckpoint;
    for(int i = 0; i < checkpoints[posCheckpoint]; i++){
        if( posCurrCmd >= (int)listCommands.size()-1  )
        {
            return false;
        }
        ++posCurrCmd;
        listCommands[posCurrCmd]->Execute();
    }
    return true;
}

void ECCommandHistory :: ExecuteCmd( ECCommand *pCmd )
{
    pCmd->Execute();
    // clear up all cmds from current pos to end
    if( posCurrCmd >= -1 )
    {
        int szList = listCommands.size();
        for(unsigned int i=posCurrCmd+1; i<szList; ++i)
        {
            delete listCommands.back();
            listCommands.pop_back();
        }
    }
    
    listCommands.push_back(pCmd);
    ++posCurrCmd;
}

void ECCommandHistory:: AddCheckpoint(int x){
    if(posCheckpoint >= -1)
    {
        int szList = checkpoints.size();
        for(unsigned int i=posCheckpoint+1; i<szList; ++i)
        {
            checkpoints.pop_back();
        }
    }

    checkpoints.push_back(x);
    posCheckpoint++;
}

