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
class ECEditorView : public ECObserver
{
public:
    ECEditorView(ECTextViewImp *subject, ECTextDocumentCtrl *docCtrl);
    void Update();
private:
    ECTextViewImp *_subject;
    ECTextDocumentCtrl *_docCtrl;
};


#endif /* EDITORVIEW_H */