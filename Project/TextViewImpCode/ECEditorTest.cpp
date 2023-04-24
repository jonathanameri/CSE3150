// Test code for editor
#include "ECTextViewImp.h"
#include "ECCommand.h"
#include "Document.h"
#include <iostream>

using namespace  std;

int myCounter = 0;


class View : public ECObserver{
    public:
        View(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl)
        {
            _docCtrl = docCtrl;
            _subject = subject;
            _subject->Attach(this);
        }
        virtual void Update() {

            cout << "View " << ++myCounter << " updated" << endl;
        }
    private:
        ECTextViewImp *_subject;
        ECTextDocumentCtrl *_docCtrl;
};

class Document{
    public:
        Document(ECTextDocumentCtrl *docCtrl)
        {
            _docCtrl = docCtrl;
        }
        void Update()
        {
            cout << "Document " << ++myCounter << " updated" << endl;
        }
    private:
        ECTextDocumentCtrl *_docCtrl;
};




class ECObserverESCAPE : public ECObserver{
    public:
        ECObserverESCAPE(ECTextViewImp *subject)
        {
            _subject = subject;
            _subject->Attach(this);
        }
        virtual void Update() {
            if(_subject->GetPressedKey() == 27) //ESCAPE KEY IS 27
            {
                _subject->InitRows();
                _subject->ClearColor();
                _subject->AddRow("Jonathan Ameri");
            }
        }
    private:
        ECTextViewImp *_subject;
};


int main(int argc, char *argv[])
{
    //
    


    ECTextViewImp wndTest;
    wndTest.AddRow("CSE 3150");
    wndTest.SetColor(0, 0, 0, TEXT_COLOR_RED);
    wndTest.SetColor(0, 1, 1, TEXT_COLOR_GREEN);
    wndTest.SetColor(0, 2, 2, TEXT_COLOR_BLUE);
    wndTest.SetColor(0, 4, 4, TEXT_COLOR_RED);
    wndTest.SetColor(0, 5, 5, TEXT_COLOR_GREEN);
    wndTest.SetColor(0, 6, 6, TEXT_COLOR_BLUE);
    wndTest.SetColor(0, 7, 7, TEXT_COLOR_MAGENTA);
    wndTest.AddRow("This is a very simple demo of the ECTextViewImp functionalities.");
    wndTest.SetColor(1, 10, 13, TEXT_COLOR_GREEN);
    wndTest.AddRow("Press ctrl-q to quit");
    wndTest.SetColor(2, 0, 1, TEXT_COLOR_GREEN);
    wndTest.SetColor(2, 0, 1, TEXT_COLOR_DEF);      //TEXT_COLOR_DEF removes color

    //my code
    //when escape key is pressed, the text will clear
    ECObserverESCAPE *observer = new ECObserverESCAPE(&wndTest);





    // add a status bar
    wndTest.AddStatusRow("Editor", "For demo only", true);
    
    wndTest.Show();
    
    return 0;
}
