//
//  ECTextDocument.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Commands


ECCommandInsert :: ECCommandInsert(ECTextDocument *doc, int pos, const std::vector<char> &listCharsToIns ) 
{
  this->doc = doc;
  this->pos = pos;
  this->listCharsToIns = listCharsToIns;
}

ECCommandInsert :: ~ECCommandInsert(){}

void ECCommandInsert :: Execute(){
  for(int i = 0; i < listCharsToIns.size(); i++){
    doc->InsertCharAt(pos + i, listCharsToIns[i]);
  }
}

void ECCommandInsert :: UnExecute(){
  for(int i = 0; i < listCharsToIns.size(); i++){
    doc->RemoveCharAt(pos);
  }
}

ECCommandRemove :: ECCommandRemove(ECTextDocument *doc, int pos, int lenToRemove ) 
{
  this->doc = doc;
  this->pos = pos;
  this->lenToRemove = lenToRemove;
}

ECCommandRemove :: ~ECCommandRemove(){}

void ECCommandRemove :: Execute(){
  for(int i = 0; i < lenToRemove; i++){
    listCharsRemoved.push_back(doc->GetCharAt(pos));
    doc->RemoveCharAt(pos);
  }
}

void ECCommandRemove :: UnExecute(){
  for(int i = 0; i < lenToRemove; i++){
    doc->InsertCharAt(pos + i, listCharsRemoved[i]);
  }
}

ECCommandUpper :: ECCommandUpper(ECTextDocument *doc, int pos, int lenToCap ) 
{
  this->doc = doc;
  this->pos = pos;
  this->lenToCap = lenToCap;
}

ECCommandUpper :: ~ECCommandUpper(){}

void ECCommandUpper :: Execute(){
  for(int i = 0; i < lenToCap; i++){
    doc->CapCharAt(pos + i);
  }
}

void ECCommandUpper :: UnExecute(){
  for(int i = 0; i < lenToCap; i++){
    doc->LowerCharAt(pos + i);
  }
}

ECCommandLower :: ECCommandLower(ECTextDocument *doc, int pos, int lenToLower ) 
{
  this->doc = doc;
  this->pos = pos;
  this->lenToLower = lenToLower;
}

ECCommandLower :: ~ECCommandLower(){}

void ECCommandLower :: Execute(){
  for(int i = 0; i < lenToLower; i++){
    doc->LowerCharAt(pos + i);
  }
}


void ECCommandLower :: UnExecute(){
  for(int i = 0; i < lenToLower; i++){
    doc->CapCharAt(pos + i);
  }
}


// **********************************************************
// Controller for text document

ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn) 
{
  doc = &docIn;
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl :: InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
  ECCommandInsert *cmd = new ECCommandInsert(doc, pos, listCharsToIns);
  cmdHistory.ExecuteCmd(cmd);
}

void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
  ECCommandRemove *cmd = new ECCommandRemove(doc, pos, lenToRemove);
  cmdHistory.ExecuteCmd(cmd);
}

void ECTextDocumentCtrl :: CapTextAt(int pos, int lenToCap)
{
  ECCommandUpper *cmd = new ECCommandUpper(doc, pos, lenToCap);
  cmdHistory.ExecuteCmd(cmd);
}

void ECTextDocumentCtrl :: LowerTextAt(int pos, int lenToLower)
{
  ECCommandLower *cmd = new ECCommandLower(doc, pos, lenToLower);
  cmdHistory.ExecuteCmd(cmd);
}

bool ECTextDocumentCtrl :: Undo()
{
  return cmdHistory.Undo();
}

bool ECTextDocumentCtrl :: Redo()
{
  return cmdHistory.Redo();
}

// **********************************************************
// Document for text document


ECTextDocument :: ECTextDocument() 
{
  docCtrl = new ECTextDocumentCtrl(*this);
}

ECTextDocument :: ~ECTextDocument()
{
}

ECTextDocumentCtrl & ECTextDocument :: GetCtrl()
{
    return *docCtrl;
}

char ECTextDocument :: GetCharAt(int pos) const
{
    return listChars[pos];
}

void ECTextDocument :: InsertCharAt(int pos, char ch)
{
  listChars.insert(listChars.begin() + pos, ch);

}

void ECTextDocument :: RemoveCharAt(int pos)
{
  listChars.erase(listChars.begin() + pos);
}

void ECTextDocument :: CapCharAt(int pos)
{
  listChars[pos] = toupper(listChars[pos]);
}

void ECTextDocument :: LowerCharAt(int pos)
{
  listChars[pos] = tolower(listChars[pos]);
}

