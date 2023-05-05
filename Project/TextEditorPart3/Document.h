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


using namespace std;

struct Row{
        string text;
        bool wrapped;
};


// **********************************************************
// Controller for text document
class ECTextDocumentCtrl
{
public:
    ECTextDocumentCtrl(ECTextDocument &docIn, ECTextViewImp *view, string filename);     // conroller constructor takes the document as input
    virtual ~ECTextDocumentCtrl();
    void InsertCharAt(int row, int pos, char charIns);    // insert a list of characters starting at position
    void RemoveCharAt(int row, int pos);                            // remove a segment of characters  of lenToRemove starting from pos                          // Lowercase the text of lenToLoer starting from pos
    bool Undo();                                      // undo any change you did to the text
    bool Redo();                                              // redo the change to the text
    
    //Commands needed to update the model
    void DeleteTextCommand();
    void NewLineCommand();
    void InsertTextCommand(char ch);

    //Function to update the view
    void UpdateView(bool checkWrappedRows);

    //Getters and Setters
    vector<string> GetDocument() const;                             // update the view
    int GetCursorX() const; 
    int GetCursorY() const; 
    void SetCursorX(int x);
    void SetCursorY(int y);
    int GetRowLen(int row) const;
    int GetNumRows() const;
    int GetMode() const;
    void SetMode(int mode);

    int GetMaxRows() const;
    bool IsRowWrapped(int row) const;

private:
    ECTextDocument &doc;
    ECTextViewImp *_view;
    ECCommandHistory histCmds;
    int mode;   //0 for command mode, 1 for insert mode
    string _filename;
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



//****************************************************************************************
//TEMPORAILY IMPLEMENTING THESE FOR TESTING PURPOSES
//****************************************************************************************
    // void InsertRow(int row, const string &str);    // insert a row of text
    // void SetRow(int row, string &str);
    // void RemoveRow(int row);
    char GetCharAt(int row, int pos) const;          // get char at current position




    void NewLine(int row, int pos, bool isWrapped);
    int GetNumRows() const;
    int GetRowLen(int row) const;
    string GetRow(int row) const;
    void InsertCharAt(int row, int pos, char ch);    // insert a single char at position
    void RemoveCharAt(int row, int pos);             // erase a single char at position

    void CheckWrappedRows(int oldCursorX, int oldCursorY);

    int GetCursorX() const { return cursorX; }
    int GetCursorY() const { return cursorY; }
    void SetCursorX(int x) { cursorX = x; }
    void SetCursorY(int y) { cursorY = y; }

    int GetMaxLen() const { return MAX_LINE_LEN; }
    int GetMaxRows() const { return MAX_NUM_ROWS; }
    bool IsRowWrapped(int row) const { return listRows[row].wrapped; }

    // void Dump() const;
    vector<Row> GetDocument() const;

    void AddKeyword(string &word);
    void CheckKeywords();
    vector<vector<int>> GetKeywordPositions() const;
    vector<int> FindWordWithinLine( int row, string &word ) const;
    
private:
    // vector<string> listRows;
    int cursorX;
    int cursorY;
    int MAX_LINE_LEN = 20;
    int MAX_NUM_ROWS = 20;
    vector<Row> listRows;
    vector<string> keywords;
    vector<vector<int>> keywordPositions;
    // map<int, map<int, pair<int, TEXT_COLOR> > > clrTextInfo;

};



#endif /* ECTextDocument_h */
