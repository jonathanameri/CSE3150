//
//  ECTextDocument.h
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#ifndef ECTextDocument_h
#define ECTextDocument_h

#include "ECCommand.h"
#include <vector>

class ECTextDocument;

// **********************************************************
// Implements Commands for editing 



class ECCommandInsert : public ECCommand
{
public:
    ECCommandInsert(ECTextDocument *doc, int pos, const std::vector<char> &listCharsToIns );
    virtual ~ECCommandInsert();
    void Execute();
    void UnExecute();
private:
    ECTextDocument *doc;
    int pos;
    std::vector<char> listCharsToIns;
};

class ECCommandRemove : public ECCommand
{
public:
    ECCommandRemove(ECTextDocument *doc, int pos, int lenToRemove );
    virtual ~ECCommandRemove();
    void Execute();
    void UnExecute();
private:
    ECTextDocument *doc;
    int pos;
    int lenToRemove;
    std::vector<char> listCharsRemoved;
};


class ECCommandUpper : public ECCommand{
public:
    ECCommandUpper(ECTextDocument *doc, int pos, int lenToCap );
    virtual ~ECCommandUpper();
    void Execute();
    void UnExecute();
private:
    ECTextDocument *doc;
    int pos;
    int lenToCap;
};

class ECCommandLower : public ECCommand{
public:
    ECCommandLower(ECTextDocument *doc, int pos, int lenToLower );
    virtual ~ECCommandLower();
    void Execute();
    void UnExecute();
private:
    ECTextDocument *doc;
    int pos;
    int lenToLower;
};



// **********************************************************
// Controller for text document

class ECTextDocumentCtrl
{
public:
    ECTextDocumentCtrl(ECTextDocument &docIn);          // conroller constructor takes the document as input
    virtual ~ECTextDocumentCtrl();
    void InsertTextAt(int pos, const std::vector<char> &listCharsToIns);    // insert a list of characters starting at position
    void RemoveTextAt(int pos, int lenToRemove);                            // remove a segment of characters  of lenToRemove starting from pos
    void CapTextAt(int pos, int lenToCap);                                  // Capitalize the text of lenToCap long starting from pos
    void LowerTextAt(int pos, int lenToLower);                              // Lowercase the text of lenToLoer starting from pos
    bool Undo();                                                            // undo any change you did to the text
    bool Redo();                                                            // redo the change to the text
    
private:
    ECTextDocument *doc;
    ECCommandHistory cmdHistory;
};

// **********************************************************
// Document for text document

class ECTextDocument
{
public:
    ECTextDocument();
    virtual ~ECTextDocument();
    ECTextDocumentCtrl &GetCtrl();          // return document controller
    int GetDocLen() const { return listChars.size(); }
    char GetCharAt(int pos) const;          // get char at current position
    void InsertCharAt(int pos, char ch);    // insert a single char at position
    void RemoveCharAt(int pos);             // erase a single char at position
    void CapCharAt(int pos);                // capitalize the char at position
    void LowerCharAt(int pos);              // lowercase the char at position
    
private:
    std::vector<char> listChars;
    ECTextDocumentCtrl *docCtrl;
};


#endif /* ECTextDocument_h */
