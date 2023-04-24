#include "Document.h"
#include <iostream>
#include <cctype>

using namespace std;


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


// **********************************************************
//ECTextDocument
ECTextDocument :: ECTextDocument() : docCtrl(*this){}
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
char ECTextDocument :: GetCharAt(int row, int pos) const
{
    return listRows[row][pos];
}
void ECTextDocument :: InsertCharAt(int row, int pos, char ch)
{
    // insert at a postion
    listRows[row].insert( listRows[row].begin()+pos, ch );
}
void ECTextDocument :: RemoveCharAt(int row, int pos)
{
    listRows[row].erase( listRows[row].begin()+pos );
}