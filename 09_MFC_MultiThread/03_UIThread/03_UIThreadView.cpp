
// 03_UIThreadView.cpp : implementation of the CMy03UIThreadView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "03_UIThread.h"
#endif

#include "03_UIThreadDoc.h"
#include "03_UIThreadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CMythread.h"

// CMy03UIThreadView

IMPLEMENT_DYNCREATE(CMy03UIThreadView, CView)

BEGIN_MESSAGE_MAP(CMy03UIThreadView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMy03UIThreadView construction/destruction

CMy03UIThreadView::CMy03UIThreadView() noexcept
{
	// TODO: add construction code here

}

CMy03UIThreadView::~CMy03UIThreadView()
{
}

BOOL CMy03UIThreadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy03UIThreadView drawing

void CMy03UIThreadView::OnDraw(CDC* /*pDC*/)
{
	CMy03UIThreadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy03UIThreadView printing

BOOL CMy03UIThreadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy03UIThreadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy03UIThreadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy03UIThreadView diagnostics

#ifdef _DEBUG
void CMy03UIThreadView::AssertValid() const
{
	CView::AssertValid();
}

void CMy03UIThreadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03UIThreadDoc* CMy03UIThreadView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03UIThreadDoc)));
	return (CMy03UIThreadDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy03UIThreadView message handlers

void CMy03UIThreadView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	AfxBeginThread(RUNTIME_CLASS(CMyThread));
}
