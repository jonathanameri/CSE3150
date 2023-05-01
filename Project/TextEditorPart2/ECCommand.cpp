
#include "ECCommand.h"

// ******************************************************
// Implement command history


ECCommandHistory :: ECCommandHistory() : posCurrCmd(-1)
{
}

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
    if( posCurrCmd < 0  )
    {
        return false;
    }
    listCommands[posCurrCmd]->UnExecute();
    --posCurrCmd;
    return true;
}

bool ECCommandHistory :: Redo()
{
    if( posCurrCmd >= (int)listCommands.size()-1  )
    {
        return false;
    }
    ++posCurrCmd;
    listCommands[posCurrCmd]->Execute();
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

