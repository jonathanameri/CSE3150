#include "Document.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Command for new line
ECNewLineCmd :: ECNewLineCmd( ECTextDocument &docIn, int rowIn ) : doc(docIn), row(rowIn)
{}

void ECNewLineCmd :: Execute()
{
    //Check if mid line or at end of line
    int cursorX = doc.GetCursorX();
    int cursorY = doc.GetCursorY();
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
    // doc.InsertRow( row, "" );
    // posAt = 0;
}

void ECNewLineCmd :: UnExecute()
{
    // undo (i.e. remove the inserted characters)
    //DO NOTHING FOR NOW
    int x = 0;
}


// **********************************************************
// Command for merging lines
ECMergeLineCmd :: ECMergeLineCmd( ECTextDocument &docIn, int rowIn ) : doc(docIn), row(rowIn)
{}

void ECMergeLineCmd :: Execute()
{
    string str1 = doc.GetRow(row);
    string str2 = doc.GetRow(row - 1);
    string str = str2 + str1;
    doc.SetRow(row - 1, str);
    doc.SetCursorX(str2.length());
    doc.SetCursorY(row - 1);
    doc.RemoveRow(row);
}

void ECMergeLineCmd ::UnExecute()
{
    //DO NOTHING FOR NOW
    int x = 0;
    }



// **********************************************************
// Command for insertion
ECInsTextCmd :: ECInsTextCmd( ECTextDocument &docIn, int row, int posInsIn, char charIns ) : doc(docIn), row(row), posIns(posInsIn), charIns(charIns)
{}

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
ECDelTextCmd :: ECDelTextCmd( ECTextDocument &docIn, int rowDelIn, int posDelIn ) : doc(docIn), rowDel(rowDelIn), posDel(posDelIn)
{}
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
ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn) : doc(docIn){}
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

void ECTextDocumentCtrl :: MergeLineCommand()
{
    ECMergeLineCmd *pCmdMerge = new ECMergeLineCmd( this->doc, doc.GetCursorY() );
    histCmds.ExecuteCmd( pCmdMerge );
}

void ECTextDocumentCtrl :: DeleteTextCommand()
{
    ECDelTextCmd *pCmdDel = new ECDelTextCmd( this->doc, doc.GetCursorY(), doc.GetCursorX() - 1);
    histCmds.ExecuteCmd( pCmdDel );
}
void ECTextDocumentCtrl :: NewLineCommand()
{
    ECNewLineCmd *pCmdNewLine = new ECNewLineCmd( this->doc, doc.GetCursorY() );
    histCmds.ExecuteCmd( pCmdNewLine );
}
void ECTextDocumentCtrl :: InsertTextCommand(char ch)
{
    ECInsTextCmd *pCmdIns = new ECInsTextCmd( this->doc, doc.GetCursorY(), doc.GetCursorX(), ch );
    histCmds.ExecuteCmd( pCmdIns );
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



// **********************************************************
//ECTextDocument
ECTextDocument :: ECTextDocument() : docCtrl(*this) , cursorX(0), cursorY(0){ listRows.push_back(""); }
ECTextDocument :: ~ECTextDocument()
{
    listRows.clear();
}
ECTextDocumentCtrl & ECTextDocument :: GetCtrl()
{
    return docCtrl;
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