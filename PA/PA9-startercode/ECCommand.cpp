//
//  ECCommand.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECCommand.h"

// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory() 
{
  //unsure what i have to do here?
}

ECCommandHistory :: ~ECCommandHistory()
{
  // your code goes here
}

void ECCommandHistory :: ExecuteCmd( ECCommand *pCmd )
{
  command.push(pCmd);
  pCmd->Execute();

}

bool ECCommandHistory :: Undo()
{
  if (command.empty())
  {
    return false;
  }
  else
  {
    ECCommand *pCmd = command.top();
    command.pop();
    pCmd->UnExecute();
    undoStack.push(pCmd);
    return true;
  }
}

bool ECCommandHistory :: Redo()
{
  if (undoStack.empty())
  {
    return false;
  }
  else
  {
    ECCommand *pCmd = undoStack.top();
    undoStack.pop();
    pCmd->Execute();
    command.push(pCmd);
    return true;
  }
}