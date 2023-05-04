#include "Observers.h"
#include <iostream>


#include "log.h"

class ECTextDocumentCtrl;
class ECTextViewImp;
class ECTextDocument;

using namespace std;

//***********************************************************
//ArrowKeyObserver
void ArrowKeyObserver :: Update(){
    int code = _subject->GetPressedKey();

    if(code == ARROW_LEFT){
        logxy("left " + to_string(_docCtrl->GetCursorX()) + " " + to_string(_docCtrl->GetCursorY()));

        if(_docCtrl->GetCursorX() - 1 >= 0){
            _docCtrl->SetCursorX(_docCtrl->GetCursorX() - 1);
        }
        else if(_docCtrl->GetCursorX() == 0 && _docCtrl->GetCursorY() - 1 >= 0){
            if(_docCtrl->IsRowWrapped(_docCtrl->GetCursorY())){
                _docCtrl->SetCursorY(_docCtrl->GetCursorY() - 1);
                _docCtrl->SetCursorX(_docCtrl->GetRowLen(_docCtrl->GetCursorY()));
            }
        }
    }
    else if(code == ARROW_RIGHT){
        logxy("right " + to_string(_docCtrl->GetCursorX()) + " " + to_string(_docCtrl->GetCursorY()));

        if(_docCtrl->GetCursorX() + 1 <= _docCtrl->GetRowLen(_docCtrl->GetCursorY())){
            _docCtrl->SetCursorX(_docCtrl->GetCursorX() + 1);
        }
        else if(_docCtrl->GetCursorY() + 1 <= _docCtrl->GetNumRows() -1 && _docCtrl->IsRowWrapped(_docCtrl->GetCursorY()+1)){
            _docCtrl->SetCursorY(_docCtrl->GetCursorY() + 1);
            _docCtrl->SetCursorX(0);
        }
    }
    else if(code == ARROW_UP){
        logxy("up " + to_string(_docCtrl->GetCursorX()) + " " + to_string(_docCtrl->GetCursorY()));

        int localCursorY = _docCtrl->GetCursorY();
        while(localCursorY - 1 >= 0){
            localCursorY--;
            if(!_docCtrl->IsRowWrapped(localCursorY)){
                break;
            }
        }
            if(_docCtrl->GetRowLen(localCursorY) < _docCtrl->GetCursorX())
                _docCtrl->SetCursorX(_docCtrl->GetRowLen(localCursorY));
            _docCtrl->SetCursorY(localCursorY);
    }
    else if(code == ARROW_DOWN){
        logxy("down " + to_string(_docCtrl->GetCursorX()) + " " + to_string(_docCtrl->GetCursorY()));

        // if(_docCtrl->GetCursorY() + 1 < _docCtrl->GetNumRows()){
        int displaySize = (_docCtrl->GetNumRows() >= _docCtrl->GetMaxRows()) ? _docCtrl->GetMaxRows() : _docCtrl->GetNumRows();

        int localCursorY = _docCtrl->GetCursorY();
        while(localCursorY + 1 < displaySize){
            localCursorY++;
            if(!_docCtrl->IsRowWrapped(localCursorY)){
                break;
            }
        }
        // if(_docCtrl->GetCursorY() + 1 < displaySize){

            if(_docCtrl->GetRowLen(localCursorY) < _docCtrl->GetCursorX())
                _docCtrl->SetCursorX(_docCtrl->GetRowLen(localCursorY));
            _docCtrl->SetCursorY(localCursorY);
        // }
    }
    //Update cursor position in view
    _docCtrl->UpdateView();
}

//***********************************************************
//BackspaceObserver
void BackspaceObserver :: Update(){
    if(_docCtrl->GetMode() == 1){
        int code = _subject->GetPressedKey();
        if(code == 127){ // code for backspace
            logxy("backspace " + to_string(_docCtrl->GetCursorX()) + " " + to_string(_docCtrl->GetCursorY()));
            _docCtrl->DeleteTextCommand();
            // if(_docCtrl->GetCursorX() == 0 )
            // {
            //     if(_docCtrl->GetCursorY() == 0)
            //         return;
            //     else
            //         _docCtrl->MergeLineCommand();
            // }
            // else{
            //     _docCtrl->DeleteTextCommand();
            // }
            _docCtrl->UpdateView();
        }
    }    
}

//***********************************************************
//EnterObserver
void EnterObserver :: Update(){
    int code = _subject->GetPressedKey();
    if (code == 13 && _docCtrl->GetMode() == 1){
        logxy("enter " + to_string(_docCtrl->GetCursorX()) + " " + to_string(_docCtrl->GetCursorY()));
        _docCtrl->NewLineCommand();
        _docCtrl->UpdateView();
    }
}

//***********************************************************
//InsertObserver
void InsertObserver :: Update(){
    int code = _subject->GetPressedKey();
    if(_docCtrl->GetMode() == 0 && (char)code == 'i'){
        logxy("i " + to_string(_docCtrl->GetCursorX()) + " " + to_string(_docCtrl->GetCursorY()));
        _docCtrl->SetMode(1);
        return;
    }

    if(_docCtrl->GetMode() != 1) return;
    //Hardcoded for now... May change to be initialized in the main file

    //If key is a command, ignore, otherwise insert the character
    vector<int> commands = {ARROW_LEFT, ARROW_RIGHT, ARROW_UP, ARROW_DOWN, 127, 13, 27, 1}; //27 is escape
    for(int i = 0; i < commands.size(); i++){
        if(code == commands[i]){
            return;
        }
    }

    //If in insert mode, insert the character
    //If in command mode but key is 'i', switch to insert mode
    logxy("insert " + to_string(_docCtrl->GetCursorX()) + " " + to_string(_docCtrl->GetCursorY()));
    _docCtrl->InsertTextCommand( (char)code );
    _docCtrl->UpdateView();
}

//***********************************************************
//EscapeObserver
void EscapeObserver :: Update(){
    if(_docCtrl->GetMode() != 1) return;
    int code = _subject->GetPressedKey();
    if(code == 27 || code == 1){
        logxy("escape " + to_string(_docCtrl->GetCursorX()) + " " + to_string(_docCtrl->GetCursorY()));
        _docCtrl->SetMode(0);
    }
}

//***********************************************************
//UndoRedoObserver
void UndoRedoObserver :: Update(){
    if(_docCtrl->GetMode() != 0) return;
    int code = _subject->GetPressedKey();
    if(code == 26){
        _docCtrl->Undo();
    }
    else if(code == 25){
        _docCtrl->Redo();
    }
    _docCtrl->UpdateView();
}

ECEditorView :: ECEditorView(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl){
    //Create Observers
    ArrowKeyObserver *arrowKeyObserver = new ArrowKeyObserver(subject, docCtrl);
    BackspaceObserver *backspaceObserver = new BackspaceObserver(subject, docCtrl);
    EnterObserver *enterObserver = new EnterObserver(subject, docCtrl);
    InsertObserver *insertObserver = new InsertObserver(subject, docCtrl);
    EscapeObserver *escapeObserver = new EscapeObserver(subject, docCtrl);
    UndoRedoObserver *undoRedoObserver = new UndoRedoObserver(subject, docCtrl);

    //Attach Observers
    subject->Attach(arrowKeyObserver);
    subject->Attach(backspaceObserver);
    subject->Attach(enterObserver);
    subject->Attach(insertObserver);
    subject->Attach(escapeObserver);
    subject->Attach(undoRedoObserver);
}