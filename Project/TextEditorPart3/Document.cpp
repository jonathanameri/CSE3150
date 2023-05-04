#include "Document.h"
// #include "log.h"

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
    vector<string> current;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            current.push_back(line);
            // for(int i = 0; i < line.length(); i++){
            //     doc.InsertCharAt(lineNum, i, line[i]);
            // }
            // // doc.NewLine( lineNum, GetRowLen(lineNum), false );
            // //*************************************************************************************
            // doc.NewLine( lineNum+1, 0, false );
            // lineNum++;
            // doc.InsertRow(doc.GetNumRows()-1, line);
        }
        // doc.RemoveRow(lineNum+1);
        // doc.RemoveCharAt(doc.GetNumRows()-1, 0);
        myfile.close();

        // current.erase(current.begin() + current.size() - 1);
        if(current.size() == 0){
            doc.NewLine(0,0,false);
        }
        for(int i = current.size() - 1; i >= 0; i--){
            for(int j = current[i].size() - 1; j >= 0; j--){
                doc.InsertCharAt(0, 0, current[i][j]);
            }
            doc.NewLine(0, 0, false);
        }
        doc.RemoveCharAt(1, 0);
    }

    // if (myfile.is_open())
    // {
    //     int lineNum = 0;
    //     while ( getline (myfile,line) )
    //     {
    //         for(int i = 0; i < line.length(); i++){
    //             doc.InsertCharAt(lineNum, i, line[i]);
    //         }
    //         // doc.NewLine( lineNum, GetRowLen(lineNum), false );
    //         //*************************************************************************************
    //         doc.NewLine( lineNum+1, 0, false );
    //         lineNum++;
    //         // doc.InsertRow(doc.GetNumRows()-1, line);
    //     }
    //     // doc.RemoveRow(lineNum+1);
    //     doc.RemoveCharAt(doc.GetNumRows()-1, 0);
    //     myfile.close();

    //     // doc.RemoveRow(doc.GetNumRows()-1);
    // }

    SetCursorX(0);
    SetCursorY(0);
    UpdateView();
    // else return -1; 
}
ECTextDocumentCtrl :: ~ECTextDocumentCtrl(){
    // Save the document to the file
    // logxy("--------------------");
    ofstream myfile;
    myfile.open (_filename);
    vector<Row> document = doc.GetDocument();

    int i = 0;
    while(i < document.size() - 1){
        if(document[i+1].wrapped){
            myfile << document[i].text;
        }
        else{
            myfile << document[i].text << endl;
        }
        i++;
    }
    myfile << document[i].text << endl;

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
    vector<Row> document = doc.GetDocument();
    // for(int i = 0; i < document.size(); i++){
    //     _view->AddRow(document[i].text);
    // }
    int displaySize = (document.size() >= doc.GetMaxRows()) ? doc.GetMaxRows() : document.size();
    for(int i = 0; i < displaySize; i++){
        _view->AddRow(document[i].text);
    }
    _view->SetCursorX(GetCursorX());
    _view->SetCursorY(GetCursorY());
}

//Commands called by observer
// void ECTextDocumentCtrl :: MergeLineCommand()
// {
//     if(mode != 1) return;
//     ECMergeLineCmd *pCmdMerge = new ECMergeLineCmd( this->doc, doc.GetCursorY() );
//     histCmds.ExecuteCmd( pCmdMerge );
//     numCommands++;
// }

void ECTextDocumentCtrl :: DeleteTextCommand()
{
    if(mode != 1 ) return;
    ECDelTextCmd *pCmdDel = new ECDelTextCmd( this->doc, doc.GetCursorY(), doc.GetCursorX() );
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
    vector<string> document;
    for(int i = 0; i < doc.GetNumRows(); i++){
        document.push_back(doc.GetRow(i));
    }
    return document;
    // return doc.GetDocument();
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
int ECTextDocumentCtrl :: GetMaxRows() const
{
    return doc.GetMaxRows();
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


// ****************************************************************************************
// TEMPORAILY IMPLEMENTING THESE FOR TESTING PURPOSES
// ****************************************************************************************

// void ECTextDocument :: InsertRow(int row, const string &str)
// {
//     NewLine(row, 0, false);
//     for(int i = 0; i < str.size(); i++){
//         InsertCharAt(row, i, str[i]);
//     }
//     // listRows.insert( listRows.begin()+row, str );
// }
// void ECTextDocument :: RemoveRow(int row){
//     for(int i = GetRowLen(row) - 1; i >= 0 ; i--){
//         RemoveCharAt(row, i);
//     }
// }
// void ECTextDocument :: SetRow(int row, string &str){
//     for(int i = GetRowLen(row) - 1; i >= 0 ; i--){
//         RemoveCharAt(row, i);
//     }
//     for(int i = 0; i < str.size(); i++){
//         InsertCharAt(row, i, str[i]);
//     }
// }

char ECTextDocument :: GetCharAt(int row, int pos) const
{
    return listRows[row].text[pos];
}

// ****************************************************************************************
// TEMPORAILY IMPLEMENTING THESE FOR TESTING PURPOSES
// ****************************************************************************************


//Representing Enter key being hit
void ECTextDocument :: NewLine(int row, int pos, bool isWrapped){
    cursorX = pos;
    cursorY = row;

    //No matter what there will be a new line created
    if(IsRowWrapped(cursorY)){
        listRows.insert( listRows.begin()+cursorY, Row{"", true} );
    }
    else{
        listRows.insert( listRows.begin()+cursorY, Row{"", false} );
    }
    //TODO change the inserted line to check if it should be wrapped without assuming false (This is the case if its a multi wrapped line)
    // listRows.insert( listRows.begin()+cursorY, Row{"", false} );
    // listRows.insert( listRows.begin()+cursorY, Row{"", isWrapped} );
    listRows[cursorY+1].wrapped = isWrapped;

    cursorY++;
    int lineToSplit = cursorY;
    // if(cursorY > 0) lineToSplit = cursorY ;

    if(cursorX < GetRowLen(lineToSplit)){
        //Split the string
        string str1 = listRows[lineToSplit].text.substr(0,cursorX);
        string str2 = listRows[lineToSplit].text.substr(cursorX);
        
        //Erase old line
        //************* STRANGE IMPLEMENTATION BUT ITS HOW I DID IT!!!! *************
        //The syntax here is weird because RemoveCharAt deletes the char BEFORE the cursor
        for(int i = GetRowLen(lineToSplit) ; i > 0 ; i--){
            RemoveCharAt(lineToSplit, i);
        }

        //Insert new lines
        for(int i = 0; i < str2.size(); i++){
            InsertCharAt(lineToSplit, i, str2[i]);
        }
        for(int i = 0; i < str1.size(); i++){
            InsertCharAt(lineToSplit-1, i, str1[i]);
        }
        
        // listRows.insert( listRows.begin()+row+1, listRows[row+1].substr(pos) );
        // listRows[row] = listRows[row].substr(0, pos);
    }
    else{
        string str = listRows[lineToSplit].text;
        for(int i = 0; i < str.size(); i ++){
            InsertCharAt(lineToSplit-1, i, str[i]);
        }
        for(int i = GetRowLen(lineToSplit) ; i > 0 ; i--){
            RemoveCharAt(lineToSplit, i);
        }
    }
    SetCursorX(0);
    // SetCursorY(cursorY+1);
    // listRows.insert( listRows.begin()+row, listRows[row].substr(pos) );
}

void ECTextDocument :: InsertCharAt(int row, int pos, char ch)
{
    //Simply insert the character
    cursorX = pos;
    cursorY = row;

    listRows[cursorY].text.insert( listRows[cursorY].text.begin()+cursorX, ch ); 

    //cursor is always increased no matter what happened
    cursorX++;

    //Check if the line is now too long
    if(GetRowLen(cursorY) > MAX_LINE_LEN){
        //If not the last line ( here just to be safe for the next if statement)
        if(GetNumRows()-1 >= cursorY+1){
            //If the next line is not wrapped
            if(!IsRowWrapped(cursorY+1)){
                NewLine(cursorY, MAX_LINE_LEN, true);
                cursorX++;
            }
            //IF THE NEXT LINE IS ALREADY WRAPPED
            else{
                NewLine(cursorY, MAX_LINE_LEN, true);
                cursorY++;
                RemoveCharAt(cursorY+1, 0);
                SetCursorX(GetRowLen(cursorY));
            }
        }
        else{
            NewLine(cursorY, MAX_LINE_LEN, true);
            cursorY++;
            SetCursorX(GetRowLen(cursorY));
        }
    }

    
}
void ECTextDocument :: RemoveCharAt(int row, int pos)
{
    cursorX = pos;
    cursorY = row;

    //If at beginning of a line
    if(cursorX == 0 && cursorY >= 0){
        if(cursorY == 0) return;
        cursorY--;
        cursorX = GetRowLen(cursorY);

        //ERASE CURRENT LINE AND move text from current line to previous line
        listRows[cursorY].text += listRows[cursorY+1].text;
        listRows.erase( listRows.begin()+cursorY+1 );



        //Check if the line is now too long
        if(GetRowLen(cursorY) > MAX_LINE_LEN){
            //If not the last line ( here just to be safe for the next if statement)
            if(GetNumRows()-1 >= cursorY+1){
                //If the next line is not wrapped
                if(!IsRowWrapped(cursorY+1)){
                    NewLine(cursorY, MAX_LINE_LEN, true);
                    cursorX++;
                }
                //IF THE NEXT LINE IS ALREADY WRAPPED
                else{
                    NewLine(cursorY, MAX_LINE_LEN, true);
                    cursorY++;
                    RemoveCharAt(cursorY+1, 0);
                    SetCursorX(GetRowLen(cursorY));
                }
            }
            else{
                NewLine(cursorY, MAX_LINE_LEN, true);
                cursorY++;
                SetCursorX(GetRowLen(cursorY));
            }
        }





        //Check if the previous line is now too long
        if(GetRowLen(cursorY) > MAX_LINE_LEN){
            //If not the last line ( here just to be safe for the next if statement)
            if(GetNumRows()-1 >= cursorY+1){
                //If the next line is not wrapped
                if(!IsRowWrapped(cursorY+1)){
                    NewLine(cursorY, MAX_LINE_LEN, true);
                    cursorX++;
                }
                //IF THE NEXT LINE IS ALREADY WRAPPED
                else{
                    NewLine(cursorY, MAX_LINE_LEN, true);
                    cursorY++;
                    RemoveCharAt(cursorY+1, 0);
                    SetCursorX(GetRowLen(cursorY));
                }
                // for(int i = MAX_LINE_LEN; i < GetRowLen(cursorY); i++){
                //     InsertCharAt(cursorY+1, i-MAX_LINE_LEN, listRows[cursorY].text[i]);
                // }
                // listRows[cursorY].text.erase( listRows[cursorY].text.begin()+MAX_LINE_LEN, listRows[cursorY].text.end() );
            }
            else{
                NewLine(cursorY, MAX_LINE_LEN, true);
                cursorY++;
                SetCursorX(GetRowLen(cursorY));
                // NewLine(cursorY, MAX_LINE_LEN, true);
                // for(int i = MAX_LINE_LEN; i < GetRowLen(cursorY); i++){
                //     InsertCharAt(cursorY+1, i-MAX_LINE_LEN, listRows[cursorY].text[i]);
                // }
                // listRows[cursorY].text.erase( listRows[cursorY].text.begin()+MAX_LINE_LEN, listRows[cursorY].text.end() );
            }
        }
    }
    else{
        listRows[cursorY].text.erase( listRows[cursorY].text.begin()+cursorX -1);
        cursorX--;
    }
}

vector<Row> ECTextDocument :: GetDocument() const
{
    // vector<string> doc;
    // for(int i = 0; i < GetNumRows(); i++){
    //     doc.push_back(GetRow(i));
    // }
    // // doc.erase( doc.begin()+GetNumRows() - 1);
    // return doc;
    return listRows;
}