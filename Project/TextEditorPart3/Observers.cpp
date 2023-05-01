#include "Observers.h"
#include <iostream>

class ECTextDocumentCtrl;
class ECTextViewImp;
class ECTextDocument;

using namespace std;

//***********************************************************
//GeneralObserver
// GeneralObserver :: GeneralObserver(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl){
//     this->_subject = subject;
//     this->_docCtrl = docCtrl;
// }

void GeneralObserver :: MakeChanges(){
    //Get document from controller and update the view
    _subject->InitRows();
    _subject->ClearColor();
    vector<string> document = _docCtrl->GetDocument();
    for(int i = 0; i < document.size(); i++){
        _subject->AddRow(document[i]);
    }
    _subject->SetCursorX(_docCtrl->GetCursorX());
    _subject->SetCursorY(_docCtrl->GetCursorY());
}

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

    //Get document from controller and update the view
    _subject->InitRows();
    _subject->ClearColor();
    vector<string> document = _docCtrl->GetDocument();
    for(int i = 0; i < document.size(); i++){
        _subject->AddRow(document[i]);
    }
    _subject->SetCursorX(_docCtrl->GetCursorX());
    _subject->SetCursorY(_docCtrl->GetCursorY());

}

//***********************************************************
//BackspaceObserver
void BackspaceObserver :: Update(){
    int code = _subject->GetPressedKey();
    if(code == 127){ // code for backspace
        if(_docCtrl->GetCursorX() == 0 )
        {
            if(_docCtrl->GetCursorY() == 0)
                return;
            else
            {
                _docCtrl->MergeLineCommand();
                // ECMergeLineCmd *pCmdMergeLine = new ECMergeLineCmd( this->doc, _docCtrl->GetCursorY() );
                // _docCtrl->histCmds.ExecuteCmd( pCmdMergeLine );
            }
        }
        else{
            _docCtrl->DeleteTextCommand();
        }
    }

    //Make Changes
    _subject->InitRows();
    _subject->ClearColor();
    vector<string> document = _docCtrl->GetDocument();
    for(int i = 0; i < document.size(); i++){
        _subject->AddRow(document[i]);
    }
    _subject->SetCursorX(_docCtrl->GetCursorX());
    _subject->SetCursorY(_docCtrl->GetCursorY());
    
}

//***********************************************************
//EnterObserver
void EnterObserver :: Update(){
    int code = _subject->GetPressedKey();
    if (code == 13){
        _docCtrl->NewLineCommand();
    }

    //Make Changes
    _subject->InitRows();
    _subject->ClearColor();
    vector<string> document = _docCtrl->GetDocument();
    for(int i = 0; i < document.size(); i++){
        _subject->AddRow(document[i]);
    }
    _subject->SetCursorX(_docCtrl->GetCursorX());
    _subject->SetCursorY(_docCtrl->GetCursorY());
}

//***********************************************************
//InsertObserver
void InsertObserver :: Update(){
    int code = _subject->GetPressedKey();
    vector<int> commands = {ARROW_LEFT, ARROW_RIGHT, ARROW_UP, ARROW_DOWN, 127, 13};
    for(int i = 0; i < commands.size(); i++){
        if(code == commands[i]){
            return;
        }
    }
     _docCtrl->InsertTextCommand( (char)code );

     //Make Changes
    _subject->InitRows();
    _subject->ClearColor();
    vector<string> document = _docCtrl->GetDocument();
    for(int i = 0; i < document.size(); i++){
        _subject->AddRow(document[i]);
    }
    _subject->SetCursorX(_docCtrl->GetCursorX());
    _subject->SetCursorY(_docCtrl->GetCursorY());
}

ECEditorView :: ECEditorView(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl){
    //Create Observers
    ArrowKeyObserver *arrowKeyObserver = new ArrowKeyObserver(subject, docCtrl);
    BackspaceObserver *backspaceObserver = new BackspaceObserver(subject, docCtrl);
    EnterObserver *enterObserver = new EnterObserver(subject, docCtrl);
    InsertObserver *insertObserver = new InsertObserver(subject, docCtrl);

    //Attach Observers
    subject->Attach(arrowKeyObserver);
    subject->Attach(backspaceObserver);
    subject->Attach(enterObserver);
    subject->Attach(insertObserver);



    //Shouldn't be necessary???
    // _subject = subject;
    // _docCtrl = docCtrl;
    // _subject->Attach(this);
    
}

void ECEditorView :: Update(){
    //Send input to controller
    // int keyLastPressed = _subject->GetPressedKey();
    // _docCtrl->HandleInput(keyLastPressed, (char)keyLastPressed);

    //Get document from controller and update the view
    _subject->InitRows();
    _subject->ClearColor();
    vector<string> document = _docCtrl->GetDocument();
    for(int i = 0; i < document.size(); i++){
        _subject->AddRow(document[i]);
    }
    _subject->SetCursorX(_docCtrl->GetCursorX());
    _subject->SetCursorY(_docCtrl->GetCursorY());
}