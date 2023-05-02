// Test code for editor
#include "ECTextViewImp.h"
#include "ECCommand.h"
#include "Document.h"
#include "Observers.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    // check input for filename
    if (argc != 2){
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    string filename = argv[1];

    //Initialize document and controller
    //Model in MVC
    ECTextDocument doc;

    //View in MVC
    ECTextViewImp wndTest;
    //Controller in MVC
    ECTextDocumentCtrl docCtrl(doc, &wndTest, filename);

    //Doc controller is initialized with reference to document and view, controller is the one making changes to both

    //EditorView is in charge of creating and attaching all observers
    ECEditorView *editorView = new ECEditorView(&wndTest, &docCtrl);

    wndTest.AddStatusRow("Command Mode", filename , true);
    wndTest.Show();
    
    return 0;


    // cout << "START" << endl;
    // doc.Dump();

    // docCtrl.HandleInput(0, 'Z');
    // cout << "AFTER INSERTING Z" << endl; 
    // doc.Dump();

    // // cout << "DELETING 3" << endl;
    // // docCtrl.RemoveCharAt(0, 5);
    // // doc.Dump();

    // cout << "Insert using Cursor" << endl;
    // docCtrl.HandleInput(0, 'A');
    // docCtrl.HandleInput(0, 'B');
    // docCtrl.HandleInput(0, 'C');
    // doc.Dump();

    // cout<< "Setting cursor to end of line 0" << endl;
    // doc.SetCursorX(doc.GetRowLen(0));
    // doc.SetCursorY(0);
    // doc.Dump();
    // cout<<"Hitting enter" << endl;
    // docCtrl.HandleInput(13, '0');
    // doc.Dump();

    // cout<<"Same thing but setting cursor at location 0, 3"<<endl;
    // doc.SetCursorX(3);
    // doc.SetCursorY(0);
    // doc.Dump();
    // docCtrl.HandleInput(13, '0');
    // doc.Dump();

    // cout<<"Move cursor to the right"<<endl;
    // docCtrl.HandleInput(ARROW_RIGHT, '0');
    // docCtrl.HandleInput(ARROW_RIGHT, '0');
    // docCtrl.HandleInput(ARROW_RIGHT, '0');
    // docCtrl.HandleInput(ARROW_RIGHT, '0');
    // docCtrl.HandleInput(ARROW_RIGHT, '0');
    // doc.Dump();
    // cout<<"Move cursor up"<<endl;
    // docCtrl.HandleInput(ARROW_UP, '0');
    // doc.Dump();
    // cout<<"Move cursor up"<<endl;
    // docCtrl.HandleInput(ARROW_UP, '0');
    // doc.Dump();
    // cout<<"Move cursor down"<<endl;
    // docCtrl.HandleInput(ARROW_DOWN, '0');
    // doc.Dump();
    // cout<<"Move cursor down"<<endl;
    // docCtrl.HandleInput(ARROW_DOWN, '0');
    // doc.Dump();
    // cout<<"Move cursor down"<<endl;
    // docCtrl.HandleInput(ARROW_DOWN, '0');
    // doc.Dump();
    // cout<<"Delete"<<endl;
    // docCtrl.HandleInput(127, '0');
    // doc.Dump();
    // cout<<"Delete"<<endl;
    // docCtrl.HandleInput(127, '0');
    // doc.Dump();
    // cout<<"Delete"<<endl;
    // docCtrl.HandleInput(127, '0');
    // doc.Dump();
    // cout<<"Delete"<<endl;
    // docCtrl.HandleInput(127, '0');
    // doc.Dump();
    





    // ECTextViewImp wndTest;
    // wndTest.AddRow("CSE 3150");
    // wndTest.SetColor(0, 0, 0, TEXT_COLOR_RED);
    // wndTest.SetColor(0, 1, 1, TEXT_COLOR_GREEN);
    // wndTest.SetColor(0, 2, 2, TEXT_COLOR_BLUE);
    // wndTest.SetColor(0, 4, 4, TEXT_COLOR_RED);
    // wndTest.SetColor(0, 5, 5, TEXT_COLOR_GREEN);
    // wndTest.SetColor(0, 6, 6, TEXT_COLOR_BLUE);
    // wndTest.SetColor(0, 7, 7, TEXT_COLOR_MAGENTA);
    // wndTest.AddRow("This is a very simple demo of the ECTextViewImp functionalities.");
    // wndTest.SetColor(1, 10, 13, TEXT_COLOR_GREEN);
    // wndTest.AddRow("Press ctrl-q to quit");
    // wndTest.SetColor(2, 0, 1, TEXT_COLOR_GREEN);
    // wndTest.SetColor(2, 0, 1, TEXT_COLOR_DEF);      //TEXT_COLOR_DEF removes color

    // //my code
    // //when escape key is pressed, the text will clear
    // ECObserverESCAPE *observer = new ECObserverESCAPE(&wndTest);





    // // add a status bar
    // wndTest.AddStatusRow("Editor", "For demo only", true);
    
    // wndTest.Show();
    
    return 0;
}
