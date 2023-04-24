// Test code for editor
#include "ECTextViewImp.h"
#include "ECCommand.h"
#include "Document.h"
#include <iostream>

using namespace  std;


int main(int argc, char *argv[])
{
    //
    ECTextDocument doc;
    

    string str1 = "CSE 3150";
    string str2 = "Jonathan Ameri";

    doc.InsertRow(0, str1);
    doc.InsertRow(1, str2);

    ECTextDocumentCtrl docCtrl(doc);

    for(int i = 0; i < doc.GetRowLen(0); i++)
    {
        cout << "Char at 0 " << i << ": " << doc.GetCharAt(0, i) << endl;
    }
    // cout << "Char at 0, 0 " << doc.GetCharAt(0, 0) << endl;

    docCtrl.InsertCharAt(0, 0, 'Z');
    cout << endl << " AFTER INSERTING Z" << endl; 

    for(int i = 0; i < doc.GetRowLen(0); i++)
    {
        cout << "Char at 0 " << i << ": " << doc.GetCharAt(0, i) << endl;
    }

    cout << "DELETING 3" << endl;

    docCtrl.RemoveCharAt(0, 5);

    for(int i = 0; i < doc.GetRowLen(0); i++)
    {
        cout << "Char at 0 " << i << ": " << doc.GetCharAt(0, i) << endl;
    }





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
