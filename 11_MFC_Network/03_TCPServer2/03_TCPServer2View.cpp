
// 03_TCPServer2View.cpp : implementation of the CMy03TCPServer2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "03_TCPServer2.h"
#endif

#include "03_TCPServer2Doc.h"
#include "03_TCPServer2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03TCPServer2View

IMPLEMENT_DYNCREATE(CMy03TCPServer2View, CEditView)

BEGIN_MESSAGE_MAP(CMy03TCPServer2View, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy03TCPServer2View construction/destruction

CMy03TCPServer2View::CMy03TCPServer2View() noexcept
{
	// TODO: add construction code here

}

CMy03TCPServer2View::~CMy03TCPServer2View()
{
}

BOOL CMy03TCPServer2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CMy03TCPServer2View printing

BOOL CMy03TCPServer2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CMy03TCPServer2View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CMy03TCPServer2View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CMy03TCPServer2View diagnostics

#ifdef _DEBUG
void CMy03TCPServer2View::AssertValid() const
{
	CEditView::AssertValid();
}

void CMy03TCPServer2View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CMy03TCPServer2Doc* CMy03TCPServer2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03TCPServer2Doc)));
	return (CMy03TCPServer2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03TCPServer2View message handlers

void CMy03TCPServer2View::AddMessage(LPCTSTR message)
{
	int len = GetWindowTextLength();
	GetEditCtrl().SetSel(len, len);
	GetEditCtrl().ReplaceSel(message);
}
