
#include "ECCommand.h"
#include "Document.h"

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



// ****************************************************************************
// COMMANDS
// ****************************************************************************

// **********************************************************
// Command for new line
void ECNewLineCmd :: Execute()
{
    //Check if mid line or at end of line
    if(cursorX == -1) cursorX = doc.GetCursorX();
    if(cursorY == -1) cursorY = doc.GetCursorY();
    oldLine = doc.GetRow(row);
    if (cursorX == doc.GetRowLen(row))
    {
        //Insert new line
        doc.InsertRow( row + 1, "" );
        // doc.SetCursorX(0);
        // doc.SetCursorY(row + 1);
    }
    else{
        //Split line
        string str = doc.GetRow(row);
        string str1 = str.substr(0, cursorX);
        string str2 = str.substr(cursorX, str.length() - cursorX);
        doc.SetRow(row, str1);
        doc.InsertRow(row + 1, str2);
        // doc.SetCursorX(0);
        // doc.SetCursorY(row + 1);
    }
}

void ECNewLineCmd :: UnExecute()
{
    // undo (i.e. remove the inserted characters)
    doc.SetRow(row, oldLine);
    doc.RemoveRow(row + 1);
    // doc.SetCursorX(cursorX);
    // doc.SetCursorY(cursorY);
}


// **********************************************************
// Command for merging lines
void ECMergeLineCmd :: Execute()
{
    cursorX = doc.GetCursorX();
    cursorY = doc.GetCursorY();
    str1 = doc.GetRow(row-1);
    str2 = doc.GetRow(row);
    string str = str1 + str2;
    doc.SetRow(row - 1, str);
    doc.RemoveRow(row);
    // doc.SetCursorX(str1.length());
    // doc.SetCursorY(row - 1);
}

void ECMergeLineCmd :: UnExecute()
{
    // string str = doc.GetRow(row-1);
    // string str1 = str.substr(0, lenLine);
    // string str2 = str.substr(lenLine, str.length() - lenLine);
    doc.SetRow(row-1, str1);
    doc.InsertRow(row, str2);
    // doc.SetCursorX(cursorX);
    // doc.SetCursorY(cursorY);
}


// **********************************************************
// Command for insertion
void ECInsTextCmd :: Execute()
{
    // insert to document
    cursorX = doc.GetCursorX();
    doc.InsertCharAt( row, posIns, charIns );
}
void ECInsTextCmd :: UnExecute()
{
    // undo (i.e. remove the inserted characters)
    doc.RemoveCharAt( row, posIns );
    // doc.SetCursorX(cursorX);
}


// **********************************************************
// Command for deletion
ECDelTextCmd :: ~ECDelTextCmd()
{
    listCharsDel.clear();
}
void ECDelTextCmd :: Execute()
{
    cursorX = doc.GetCursorX();
    char ch = doc.GetCharAt(rowDel, posDel);
    listCharsDel.push_back(ch);
    doc.RemoveCharAt( rowDel, posDel );
}
void ECDelTextCmd :: UnExecute()
{
    // undo: that is, adding the deleted text back
    for(unsigned int i=0; i<listCharsDel.size(); ++i)
    {
        doc.InsertCharAt( rowDel, posDel+i, listCharsDel[i] );
    }
    listCharsDel.clear();
    // doc.SetCursorX(cursorX);
}

