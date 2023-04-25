#include "ECEditorView.h"
#include <iostream>

class ECTextDocumentCtrl;
class ECTextViewImp;
class ECTextDocument;

using namespace std;

//***********************************************************
ECEditorView :: ECEditorView(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl){
    _subject = subject;
    _docCtrl = docCtrl;
    _subject->Attach(this);
}


void ECEditorView :: Update(){
    //Send input to controller
    int keyLastPressed = _subject->GetPressedKey();
    _docCtrl->HandleInput(keyLastPressed, (char)keyLastPressed);

    //Get document from controller and update the view
    _subject->InitRows();
    _subject->ClearColor();
    vector<string> document = _docCtrl->GetDocument(*this);
    for(int i = 0; i < document.size(); i++){
        _subject->AddRow(document[i]);
    }
    _subject->SetCursorX(_docCtrl->GetCursorX());
    _subject->SetCursorY(_docCtrl->GetCursorY());


}