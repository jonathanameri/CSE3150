#ifndef ECCommand_h
#define ECCommand_h

#include <vector>
#include <string>
// #include "Document.h"

using namespace std;

class ECTextDocument;
class ECTextDocumentCtrl;

// ******************************************************
// Implement command design pattern

class ECCommand
{
public:
    virtual ~ECCommand() {}
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};

// ******************************************************
// Implement command history

class ECCommandHistory
{
public:
    ECCommandHistory() : posCurrCmd(-1), posCheckpoint(-1) {} ;
    virtual ~ECCommandHistory();
    bool Undo();
    bool Redo();
    void ExecuteCmd( ECCommand *pCmd );
    void AddCheckpoint(int x);
    
private:
    vector<ECCommand *> listCommands;
    int posCurrCmd;
    vector<int> checkpoints;
    int posCheckpoint;
};



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
    string oldLine;
    bool endOfLine;
};


// **********************************************************
// Command for merging lines
// class ECMergeLineCmd : public ECCommand
// {
// public:
//     ECMergeLineCmd( ECTextDocument &docIn, int rowIn ) : doc(docIn), row(rowIn) {} ;
//     void Execute();
//     void UnExecute();
// private:
//     ECTextDocument &doc;
//     int row;
//     string str1;
//     string str2;
//     int cursorX;
//     int cursorY;
// };

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
    // ~ECDelTextCmd();
    virtual void Execute();
    virtual void UnExecute();
    
private:
    ECTextDocument &doc;
    int rowDel;
    int posDel;
    char delChar;
    int cursorX;
    int cursorY;
    bool startLine;
    int lenPrevLine;
};




#endif /* ECCommand_h */
