
// 01_FileIOTestView.cpp : implementation of the CMy01FileIOTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "01_FileIOTest.h"
#endif

#include "01_FileIOTestDoc.h"
#include "01_FileIOTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01FileIOTestView

IMPLEMENT_DYNCREATE(CMy01FileIOTestView, CView)

BEGIN_MESSAGE_MAP(CMy01FileIOTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy01FileIOTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy01FileIOTestView construction/destruction

CMy01FileIOTestView::CMy01FileIOTestView() noexcept
{
	// TODO: add construction code here

}

CMy01FileIOTestView::~CMy01FileIOTestView()
{
}

BOOL CMy01FileIOTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy01FileIOTestView drawing

void CMy01FileIOTestView::OnDraw(CDC* pDC)
{
	CMy01FileIOTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->SetMapMode(MM_LOMETRIC);
	pDC->Rectangle(50, -50, 350, -350);
	pDC->Ellipse(500, -50, 800, -350);
}


// CMy01FileIOTestView printing


void CMy01FileIOTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy01FileIOTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy01FileIOTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy01FileIOTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy01FileIOTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy01FileIOTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy01FileIOTestView diagnostics

#ifdef _DEBUG
void CMy01FileIOTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMy01FileIOTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy01FileIOTestDoc* CMy01FileIOTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy01FileIOTestDoc)));
	return (CMy01FileIOTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy01FileIOTestView message handlers
