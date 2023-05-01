#include "Document.h"
#include <iostream>
#include <cctype>

using namespace std;

//***********************************************************
// Checkpoint command
// void ECCheckpoint :: Execute()
// {
//     //Do nothing
//     return;
// }
// void ECCheckpoint :: UnExecute()
// {
//     //Do nothing
//     return;
// }

// **********************************************************
// Command for new line
void ECNewLineCmd :: Execute()
{
    //Check if mid line or at end of line
    cursorX = doc.GetCursorX();
    cursorY = doc.GetCursorY();
    oldLine = doc.GetRow(cursorY);
    if (cursorX == doc.GetRowLen(row))
    {
        //Insert new line
        doc.InsertRow( row + 1, "" );
        doc.SetCursorX(0);
        doc.SetCursorY(cursorY + 1);
    }
    else{
        //Split line
        string str = doc.GetRow(row);
        string str1 = str.substr(0, cursorX);
        string str2 = str.substr(cursorX, str.length() - cursorX);
        doc.SetRow(row, str1);
        doc.InsertRow(row + 1, str2);
        doc.SetCursorX(0);
        doc.SetCursorY(cursorY + 1);
    }
}

void ECNewLineCmd :: UnExecute()
{
    // undo (i.e. remove the inserted characters)
    doc.SetRow(row, oldLine);
    doc.RemoveRow(row + 1);
    doc.SetCursorX(cursorX);
    doc.SetCursorY(cursorY);
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
    doc.SetCursorX(str1.length());
    doc.SetCursorY(row - 1);
    
}

void ECMergeLineCmd :: UnExecute()
{
    // string str = doc.GetRow(row-1);
    // string str1 = str.substr(0, lenLine);
    // string str2 = str.substr(lenLine, str.length() - lenLine);
    doc.SetRow(row-1, str1);
    doc.InsertRow(row, str2);
    doc.SetCursorX(cursorX);
    doc.SetCursorY(cursorY);
}


// **********************************************************
// Command for insertion
void ECInsTextCmd :: Execute()
{
    // insert to document
    doc.InsertCharAt( row, posIns, charIns );
}
void ECInsTextCmd :: UnExecute()
{
    // undo (i.e. remove the inserted characters)
    doc.RemoveCharAt( row, posIns );
}


// **********************************************************
// Command for deletion
ECDelTextCmd :: ~ECDelTextCmd()
{
    listCharsDel.clear();
}
void ECDelTextCmd :: Execute()
{
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
}



// **********************************************************
// Controller for text document
ECTextDocumentCtrl :: ~ECTextDocumentCtrl(){}
void ECTextDocumentCtrl :: InsertCharAt(int row, int pos, char charIns)
{
    ECInsTextCmd *pCmdIns = new ECInsTextCmd( this->doc, row, pos, charIns );
    histCmds.ExecuteCmd( pCmdIns );
}
void ECTextDocumentCtrl :: RemoveCharAt(int row, int pos)
{
    ECDelTextCmd *pCmdDel = new ECDelTextCmd( this->doc, row, pos);
    histCmds.ExecuteCmd( pCmdDel );
}
bool ECTextDocumentCtrl :: Undo()
{
    return histCmds.Undo();
}
bool ECTextDocumentCtrl :: Redo()
{
    return histCmds.Redo();
}
void ECTextDocumentCtrl :: UpdateView(){
    //Make Changes
    _view->InitRows();
    _view->ClearColor();
    vector<string> document = GetDocument();
    for(int i = 0; i < document.size(); i++){
        _view->AddRow(document[i]);
    }
    _view->SetCursorX(GetCursorX());
    _view->SetCursorY(GetCursorY());
}

//Commands called by observer
void ECTextDocumentCtrl :: MergeLineCommand()
{
    if(mode != 1) return;
    ECMergeLineCmd *pCmdMerge = new ECMergeLineCmd( this->doc, doc.GetCursorY() );
    histCmds.ExecuteCmd( pCmdMerge );
    numCommands++;
}

void ECTextDocumentCtrl :: DeleteTextCommand()
{
    if(mode != 1 ) return;
    ECDelTextCmd *pCmdDel = new ECDelTextCmd( this->doc, doc.GetCursorY(), doc.GetCursorX() - 1);
    histCmds.ExecuteCmd( pCmdDel );
    numCommands++;
}
void ECTextDocumentCtrl :: NewLineCommand()
{
    if(mode != 1 ) return;
    ECNewLineCmd *pCmdNewLine = new ECNewLineCmd( this->doc, doc.GetCursorY() );
    histCmds.ExecuteCmd( pCmdNewLine );
    numCommands++;
}
void ECTextDocumentCtrl :: InsertTextCommand(char ch)
{
    if(mode != 1 ) return;
    ECInsTextCmd *pCmdIns = new ECInsTextCmd( this->doc, doc.GetCursorY(), doc.GetCursorX(), ch );
    histCmds.ExecuteCmd( pCmdIns );
    numCommands++;
}

//********************************************************************************
//Getters and Setters
std::vector<std::string> ECTextDocumentCtrl :: GetDocument() const
{
    return doc.GetDocument();
}
int ECTextDocumentCtrl :: GetCursorX() const
{
    return doc.GetCursorX();
}
int ECTextDocumentCtrl :: GetCursorY() const
{
    return doc.GetCursorY();
}
void ECTextDocumentCtrl :: SetCursorX(int x)
{
    doc.SetCursorX(x);
}
void ECTextDocumentCtrl :: SetCursorY(int y)
{
    doc.SetCursorY(y);
}
int ECTextDocumentCtrl :: GetRowLen(int row) const
{
    return doc.GetRowLen(row);
}
int ECTextDocumentCtrl :: GetNumRows() const
{
    return doc.GetNumRows();
}
int ECTextDocumentCtrl :: GetMode() const
{
    return mode;
}
void ECTextDocumentCtrl :: SetMode(int newMode)
{
    if(newMode == this->mode) return;
    this->mode = newMode;

    if(newMode == 0){
        _view->ClearStatusRows();
        _view->AddStatusRow("Command Mode", _filename, true);
        histCmds.AddCheckpoint(numCommands);
        numCommands = 0;
    }
    else if (newMode == 1){
        _view->ClearStatusRows();
        _view->AddStatusRow("Text Mode", _filename, true);
    }
}



// **********************************************************
//ECTextDocument
ECTextDocument :: ECTextDocument() : cursorX(0), cursorY(0){ listRows.push_back(""); }
ECTextDocument :: ~ECTextDocument()
{
    listRows.clear();
}
void ECTextDocument :: InsertRow(int row, const std::string &str)
{
    listRows.insert( listRows.begin()+row, str );
}
int ECTextDocument :: GetRowLen(int row) const
{
    return listRows[row].size();
}
std::string ECTextDocument :: GetRow(int row) const
{
    return listRows[row];
}
void ECTextDocument :: SetRow(int row, std::string &str){
    listRows[row] = str;
}
void ECTextDocument :: RemoveRow(int row){
    listRows.erase( listRows.begin()+row );
}
char ECTextDocument :: GetCharAt(int row, int pos) const
{
    return listRows[row][pos];
}
void ECTextDocument :: InsertCharAt(int row, int pos, char ch)
{
    // insert at a postion
    listRows[row].insert( listRows[row].begin()+pos, ch );
    cursorX++;
}
void ECTextDocument :: RemoveCharAt(int row, int pos)
{
    listRows[row].erase( listRows[row].begin()+pos );
    cursorX--;
}
void ECTextDocument :: Dump() const
{
    cout << "*********************************" << endl;
    for(unsigned int i=0; i<listRows.size(); ++i)
    {
        cout <<" "<<i << "|";
        for(unsigned int j=0; j<=listRows[i].size(); ++j)
        {
            if(j == cursorX && i == cursorY)
                cout << "#";
            cout << listRows[i][j];
            
        }
        cout << endl;
    }
    cout << "*********************************" << endl;
}

std::vector<std::string> ECTextDocument :: GetDocument() const
{
    return listRows;
}