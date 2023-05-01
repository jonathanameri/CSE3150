#ifndef EDITORVIEW_H
#define EDITORVIEW_H

#include <string>
#include <vector>
#include <map>
#include "ECObserver.h"
#include "ECTextViewImp.h"
#include "Document.h"

class ECTextDocumentCtrl;
class ECTextViewImp;

//***********************************************************
class ECEditorView
{
public:
    ECEditorView(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl);
};

//***********************************************************
class GeneralObserver : public ECObserver
{
public:
    GeneralObserver(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl) : _subject(subject), _docCtrl(docCtrl) {};
    // void MakeChanges();
private:
    ECTextViewImp *_subject;
    ECTextDocumentCtrl *_docCtrl;
};

//***********************************************************
//ArrowKeyObserver
class ArrowKeyObserver : public GeneralObserver
{
public:
    ArrowKeyObserver(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl) : _subject(subject), _docCtrl(docCtrl), GeneralObserver(subject, docCtrl) {};
    void Update();
private:
    ECTextViewImp *_subject;
    ECTextDocumentCtrl *_docCtrl;
};


//***********************************************************
//BackspaceObserver
class BackspaceObserver : public GeneralObserver
{
public:
    BackspaceObserver(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl) : _subject(subject), _docCtrl(docCtrl), GeneralObserver(subject, docCtrl) {};
    void Update();
private:
    ECTextViewImp *_subject;
    ECTextDocumentCtrl *_docCtrl;
};

//***********************************************************
//EnterObserver
class EnterObserver : public GeneralObserver

{
public:
    EnterObserver(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl) : _subject(subject), _docCtrl(docCtrl), GeneralObserver(subject, docCtrl) {};
    void Update();
private:
    ECTextViewImp *_subject;
    ECTextDocumentCtrl *_docCtrl;
};

//***********************************************************
//InsertObserver
class InsertObserver : public GeneralObserver
{
public:
    InsertObserver(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl) : _subject(subject), _docCtrl(docCtrl), GeneralObserver(subject, docCtrl) {};
    void Update();
private:
    ECTextViewImp *_subject;
    ECTextDocumentCtrl *_docCtrl;
};

class EscapeObserver : public GeneralObserver
{
public:
    EscapeObserver(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl) : _subject(subject), _docCtrl(docCtrl), GeneralObserver(subject, docCtrl) {};
    void Update();
private:
    ECTextViewImp *_subject;
    ECTextDocumentCtrl *_docCtrl;
};

class UndoRedoObserver : public GeneralObserver
{
public:
    UndoRedoObserver(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl) : _subject(subject), _docCtrl(docCtrl), GeneralObserver(subject, docCtrl) {};
    void Update();
private:
    ECTextViewImp *_subject;
    ECTextDocumentCtrl *_docCtrl;
};


#endif /* EDITORVIEW_H */