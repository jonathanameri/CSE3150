#ifndef Document_h
#define Document_h

#include "ECCommand.h"
#include "ECTextViewImp.h"
#include "Observers.h"
#include <vector>
#include <iostream>
#include <cctype>
#include <fstream>
#include <string>

class ECTextDocument;
class ECEditorView;
class ECTextDocument;

//***********************************************************
// Checkpoint command



// **********************************************************
// Command for new line
class ECNewLineCmd : public ECCommand
{
public:
    ECNewLineCmd( ECTextDocument &docIn, int rowIn ) : doc(docIn), row(rowIn), cursorX(-1),cursorY(-1) {} ;
    void Execute();
    void UnExecute();
private:
    ECTextDocument &doc;
    int row;
    int cursorX;
    int cursorY;
    std::string oldLine;
};


// **********************************************************
// Command for merging lines
class ECMergeLineCmd : public ECCommand
{
public:
    ECMergeLineCmd( ECTextDocument &docIn, int rowIn ) : doc(docIn), row(rowIn) {} ;
    void Execute();
    void UnExecute();
private:
    ECTextDocument &doc;
    int row;
    std::string str1;
    std::string str2;
    int cursorX;
    int cursorY;
};

// **********************************************************
// Command for insertion
class ECInsTextCmd : public ECCommand
{
public:
    ECInsTextCmd( ECTextDocument &docIn, int row, int posInsIn, char charIns ) : doc(docIn), row(row), posIns(posInsIn), charIns(charIns) {};
    void Execute();
    void UnExecute();
    
private:
    ECTextDocument &doc;
    int row;
    int posIns;
    char charIns;
    int cursorX;
};

// **********************************************************
// Command for deletion
class ECDelTextCmd : public ECCommand
{
public:
    ECDelTextCmd( ECTextDocument &docIn, int rowDel, int posDelIn) : doc(docIn), rowDel(rowDel), posDel(posDelIn) {} ;
    ~ECDelTextCmd();
    virtual void Execute();
    virtual void UnExecute();
    
private:
    ECTextDocument &doc;
    int rowDel;
    int posDel;
    std::vector<char> listCharsDel;
    int cursorX;
};


// **********************************************************
// Controller for text document
class ECTextDocumentCtrl
{
public:
    ECTextDocumentCtrl(ECTextDocument &docIn, ECTextViewImp *view, std::string filename);     // conroller constructor takes the document as input
    virtual ~ECTextDocumentCtrl();
    void InsertCharAt(int row, int pos, char charIns);    // insert a list of characters starting at position
    void RemoveCharAt(int row, int pos);                            // remove a segment of characters  of lenToRemove starting from pos                          // Lowercase the text of lenToLoer starting from pos
    bool Undo();                                      // undo any change you did to the text
    bool Redo();                                              // redo the change to the text
    
    //Commands needed to update the model
    void MergeLineCommand();
    void DeleteTextCommand();
    void NewLineCommand();
    void InsertTextCommand(char ch);

    //Function to update the view
    void UpdateView();

    //Getters and Setters
    std::vector<std::string> GetDocument() const;                             // update the view
    int GetCursorX() const; 
    int GetCursorY() const; 
    void SetCursorX(int x);
    void SetCursorY(int y);
    int GetRowLen(int row) const;
    int GetNumRows() const;
    int GetMode() const;
    void SetMode(int mode);
private:
    ECTextDocument &doc;
    ECTextViewImp *_view;
    ECCommandHistory histCmds;
    int mode;   //0 for command mode, 1 for insert mode
    std::string _filename;
    int numCommands;
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
    std::string GetRow(int row) const;
    void SetRow(int row, std::string &str);
    void RemoveRow(int row);
    char GetCharAt(int row, int pos) const;          // get char at current position
    void InsertCharAt(int row, int pos, char ch);    // insert a single char at position
    void RemoveCharAt(int row, int pos);             // erase a single char at position

    int GetCursorX() const { return cursorX; }
    int GetCursorY() const { return cursorY; }
    void SetCursorX(int x) { cursorX = x; }
    void SetCursorY(int y) { cursorY = y; }

    void Dump() const;
    std::vector<std::string> GetDocument() const;
    
private:
    std::vector<std::string> listRows;
    int cursorX;
    int cursorY;
    // std::map<int, std::map<int, std::pair<int, TEXT_COLOR> > > clrTextInfo;

};



#endif /* ECTextDocument_h */
