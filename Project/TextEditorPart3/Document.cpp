#include "Document.h"

// **********************************************************
// Controller for text document

ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn, ECTextViewImp *view, string filename) : doc(docIn), _view(view), _filename(filename), mode(0), numCommands(0)      // conroller constructor takes the document as input
{
    // //Create the file if it doesnt exist
    // ofstream a_file ( filename);
    // a_file.close();

    //Read the file
    string line;
    ifstream myfile (filename);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            for(int i = 0; i < line.length(); i++){
                doc.InsertCharAt(doc.GetNumRows()-1, doc.GetRowLen(doc.GetNumRows()-1), line[i]);
            }
            // doc.InsertRow(doc.GetNumRows()-1, line);
        }
        myfile.close();

        // doc.RemoveRow(doc.GetNumRows()-1);
    }

    SetCursorX(0);
    SetCursorY(0);
    UpdateView();
    // else return -1; 
}
ECTextDocumentCtrl :: ~ECTextDocumentCtrl(){
    // Save the document to the file
    ofstream myfile;
    myfile.open (_filename);
    vector<string> document = GetDocument();
    for(int i = 0; i < document.size(); i++){
        myfile << document[i] << endl;
    }
    myfile.close();

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
vector<string> ECTextDocumentCtrl :: GetDocument() const
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
        if(numCommands > 0) histCmds.AddCheckpoint(numCommands);
        numCommands = 0;
    }
    else if (newMode == 1){
        _view->ClearStatusRows();
        _view->AddStatusRow("Text Mode", _filename, true);
    }
}



// **********************************************************
//ECTextDocument
ECTextDocument :: ECTextDocument() : cursorX(0), cursorY(0){ listRows.push_back( Row{"", false}); }
ECTextDocument :: ~ECTextDocument()
{
    listRows.clear();
}

int ECTextDocument :: GetNumRows() const { return listRows.size(); }
int ECTextDocument :: GetRowLen(int row) const { return listRows[row].text.size(); }


//TODO maybe change this so that GetRow returns the wrapped text from next line(s)
string ECTextDocument :: GetRow(int row) const
{
    // if(GetNumRows()-1 >= row+1 && IsRowWrapped(row+1)){
    //     return listRows[row].text + GetRow(row+1);
    // }
    return listRows[row].text;
}

//Representing Enter key being hit
void ECTextDocument :: NewLine(int row, int pos, bool isWrapped){
    //No matter what there will be a new line created
    listRows.insert( listRows.begin()+row, Row{"", isWrapped} );


    if(pos < GetRowLen(row)){
        //Split the string
        string str1 = listRows[row].text.substr(0,pos);
        string str2 = listRows[row].text.substr(pos);
        
        //Erase old line
        for(int i = GetRowLen(row) - 1; i >= 0 ; i--){
            RemoveCharAt(row, i-1);
        }

        //Insert new lines
        for(int i = 0; i < str1.size(); i++){
            InsertCharAt(row, i, str1[i]);
        }
        for(int i = 0; i < str2.size(); i++){
            InsertCharAt(row+1, i, str2[i]);
        }
        // listRows.insert( listRows.begin()+row+1, listRows[row+1].substr(pos) );
        // listRows[row] = listRows[row].substr(0, pos);
    }
    SetCursorX(0);
    SetCursorY(row+1);
    // listRows.insert( listRows.begin()+row, listRows[row].substr(pos) );
}


//****************************************************************************************
//TEMPORAILY IMPLEMENTING THESE FOR TESTING PURPOSES
//****************************************************************************************

void ECTextDocument :: InsertRow(int row, const string &str)
{
    NewLine(row, 0, false);
    for(int i = 0; i < str.size(); i++){
        InsertCharAt(row, i, str[i]);
    }
    // listRows.insert( listRows.begin()+row, str );
}
void ECTextDocument :: RemoveRow(int row){
    for(int i = GetRowLen(row) - 1; i >= 0 ; i--){
        RemoveCharAt(row, i);
    }
}
void ECTextDocument :: SetRow(int row, string &str){
    for(int i = GetRowLen(row) - 1; i >= 0 ; i--){
        RemoveCharAt(row, i);
    }
    for(int i = 0; i < str.size(); i++){
        InsertCharAt(row, i, str[i]);
    }
}


char ECTextDocument :: GetCharAt(int row, int pos) const
{
    return listRows[row].text[pos];
}
void ECTextDocument :: InsertCharAt(int row, int pos, char ch)
{
    //Simply insert the character
    listRows[row].text.insert( listRows[row].text.begin()+pos, ch ); 

    //Check if the line is now too long
    if(GetRowLen(row) > MAX_LINE_LEN){
        if(GetNumRows()-1 >= row+1){
            if(!IsRowWrapped(row+1)){
                NewLine(row, MAX_LINE_LEN, true);
            }
            InsertCharAt(row+1, 0, listRows[row].text[MAX_LINE_LEN]);
            listRows[row].text.erase( listRows[row].text.begin()+MAX_LINE_LEN );
        }
        else{
            NewLine(row, MAX_LINE_LEN, true);
            InsertCharAt(row+1, 0, listRows[row].text[MAX_LINE_LEN]);
            listRows[row].text.erase( listRows[row].text.begin()+MAX_LINE_LEN );
        }
    }

    //cursor is always increased no matter what happened
    cursorX++;
}
void ECTextDocument :: RemoveCharAt(int row, int pos)
{
    //If at beginning of a line
    if(cursorX == 0 && cursorY > 0){
        cursorY--;
        cursorX = GetRowLen(cursorY);

        //Move text from current line to previous line
        listRows[cursorY].text += listRows[cursorY+1].text;
        listRows.erase( listRows.begin()+cursorY+1 );

        //Check if the previous line is now too long
        if(GetRowLen(cursorY) > MAX_LINE_LEN){
            if(GetNumRows()-1 >= cursorY+1){
                if(!IsRowWrapped(cursorY+1)){
                    NewLine(cursorY, MAX_LINE_LEN, true);
                }
                for(int i = MAX_LINE_LEN; i < GetRowLen(cursorY); i++){
                    InsertCharAt(cursorY+1, i-MAX_LINE_LEN, listRows[cursorY].text[i]);
                }
                listRows[cursorY].text.erase( listRows[cursorY].text.begin()+MAX_LINE_LEN, listRows[cursorY].text.end() );
                // InsertCharAt(row+1, 0, listRows[row].text[MAX_LINE_LEN]);
                // listRows[row].text.erase( listRows[row].text.begin()+MAX_LINE_LEN );
            }
            else{
                NewLine(row, MAX_LINE_LEN, true);
                for(int i = MAX_LINE_LEN; i < GetRowLen(cursorY); i++){
                    InsertCharAt(cursorY+1, i-MAX_LINE_LEN, listRows[cursorY].text[i]);
                }
                listRows[cursorY].text.erase( listRows[cursorY].text.begin()+MAX_LINE_LEN, listRows[cursorY].text.end() );
                // InsertCharAt(row+1, 0, listRows[row].text[MAX_LINE_LEN]);
                // listRows[row].text.erase( listRows[row].text.begin()+MAX_LINE_LEN );
            }
        }
        cursorX--;
        return;
    }
    listRows[row].text.erase( listRows[row].text.begin()+pos );
    cursorX--;
}

vector<string> ECTextDocument :: GetDocument() const
{
    vector<string> doc;
    for(int i = 0; i < GetNumRows(); i++){
        doc.push_back(GetRow(i));
    }
    return doc;
}