#include "Observers.h"
#include <iostream>

class ECTextDocumentCtrl;
class ECTextViewImp;
class ECTextDocument;

using namespace std;

//***********************************************************
//ArrowKeyObserver
void ArrowKeyObserver :: Update(){
    int code = _subject->GetPressedKey();

    if(code == ARROW_LEFT){
        if(_docCtrl->GetCursorX() - 1 >= 0){
            _docCtrl->SetCursorX(_docCtrl->GetCursorX() - 1);
        }
    }
    else if(code == ARROW_RIGHT){
        if(_docCtrl->GetCursorX() + 1 <= _docCtrl->GetRowLen(_docCtrl->GetCursorY())){
            _docCtrl->SetCursorX(_docCtrl->GetCursorX() + 1);
        }
    }
    else if(code == ARROW_UP){
        if(_docCtrl->GetCursorY() - 1 >= 0){
            if(_docCtrl->GetRowLen(_docCtrl->GetCursorY() - 1) < _docCtrl->GetCursorX())
                _docCtrl->SetCursorX(_docCtrl->GetRowLen(_docCtrl->GetCursorY() - 1));
            _docCtrl->SetCursorY(_docCtrl->GetCursorY() - 1);
        }
    }
    else if(code == ARROW_DOWN){
        if(_docCtrl->GetCursorY() + 1 < _docCtrl->GetNumRows()){
            if(_docCtrl->GetRowLen(_docCtrl->GetCursorY() + 1) < _docCtrl->GetCursorX())
                _docCtrl->SetCursorX(_docCtrl->GetRowLen(_docCtrl->GetCursorY() + 1));
            _docCtrl->SetCursorY(_docCtrl->GetCursorY() + 1);
        }
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
            if(_docCtrl->GetCursorX() == 0 )
            {
                if(_docCtrl->GetCursorY() == 0)
                    return;
                else
                {
                    _docCtrl->MergeLineCommand();
                }
            }
            else{
                _docCtrl->DeleteTextCommand();
            }
            _docCtrl->UpdateView();
        }
    }    
}

//***********************************************************
//EnterObserver
void EnterObserver :: Update(){
    int code = _subject->GetPressedKey();
    if (code == 13 && _docCtrl->GetMode() == 1){
        _docCtrl->NewLineCommand();
        _docCtrl->UpdateView();
    }
}

//***********************************************************
//InsertObserver
void InsertObserver :: Update(){
    int code = _subject->GetPressedKey();
    if(_docCtrl->GetMode() == 0 && (char)code == 'i'){
        _docCtrl->SetMode(1);
        return;
    }

    if(_docCtrl->GetMode() != 1) return;
    //Hardcoded for now... May change to be initialized in the main file

    //If key is a command, ignore, otherwise insert the character
    vector<int> commands = {ARROW_LEFT, ARROW_RIGHT, ARROW_UP, ARROW_DOWN, 127, 13, 27}; //27 is escape
    for(int i = 0; i < commands.size(); i++){
        if(code == commands[i]){
            return;
        }
    }

    //If in insert mode, insert the character
    //If in command mode but key is 'i', switch to insert mode
    _docCtrl->InsertTextCommand( (char)code );
    _docCtrl->UpdateView();
}

//***********************************************************
//EscapeObserver
void EscapeObserver :: Update(){
    if(_docCtrl->GetMode() != 1) return;
    int code = _subject->GetPressedKey();
    if(code == 27 || code == 1){
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