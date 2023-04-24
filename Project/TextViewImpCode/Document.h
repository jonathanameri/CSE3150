#ifndef Document_h
#define Document_h

#include <vector>
#include "ECCommand.h"

class ECTextDocument;


// **********************************************************
// Command for insertion

class ECInsTextCmd : public ECCommand
{
public:
    ECInsTextCmd( ECTextDocument &docIn, int row, int posInsIn, char charIns );
    void Execute();
    void UnExecute();
    
private:
    ECTextDocument &doc;
    int row;
    int posIns;
    char charIns;
};

// **********************************************************
// Command for deletion

class ECDelTextCmd : public ECCommand
{
public:
    ECDelTextCmd( ECTextDocument &docIn, int rowDel, int posDelIn);
    ~ECDelTextCmd();
    virtual void Execute();
    virtual void UnExecute();
    
private:
    ECTextDocument &doc;
    int rowDel;
    int posDel;
    std::vector<char> listCharsDel;
};


// **********************************************************
// Controller for text document

class ECTextDocumentCtrl
{
public:
    ECTextDocumentCtrl(ECTextDocument &docIn);          // conroller constructor takes the document as input
    virtual ~ECTextDocumentCtrl();
    void InsertCharAt(int row, int pos, char charIns);    // insert a list of characters starting at position
    void RemoveCharAt(int row, int pos);                            // remove a segment of characters  of lenToRemove starting from pos                          // Lowercase the text of lenToLoer starting from pos
    bool Undo();                                                            // undo any change you did to the text
    bool Redo();                                                            // redo the change to the text
    
private:
    ECTextDocument &doc;
    ECCommandHistory histCmds;
};

// **********************************************************
// Document for text document

class ECTextDocument
{
public:
    ECTextDocument();
    virtual ~ECTextDocument();
    ECTextDocumentCtrl &GetCtrl();          // return document controller
    void InsertRow(int row, const std::string &str);    // insert a row of text
    int GetNumRows() const { return listRows.size(); }
    int GetRowLen(int row) const;
    char GetCharAt(int row, int pos) const;          // get char at current position
    void InsertCharAt(int row, int pos, char ch);    // insert a single char at position
    void RemoveCharAt(int row, int pos);             // erase a single char at position
    
    int GetCursorX() const { return cursorX; }
    int GetCursorY() const { return cursorY; }
    void SetCursorX(int x) { cursorX = x; }
    void SetCursorY(int y) { cursorY = y; }
    
private:
    ECTextDocumentCtrl docCtrl;
    std::vector<std::string> listRows;
    int cursorX;
    int cursorY;
    // std::map<int, std::map<int, std::pair<int, TEXT_COLOR> > > clrTextInfo;

};



#endif /* ECTextDocument_h */
