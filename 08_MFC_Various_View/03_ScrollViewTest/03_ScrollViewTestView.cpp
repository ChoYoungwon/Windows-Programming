
// 03_ScrollViewTestView.cpp : implementation of the CMy03ScrollViewTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "03_ScrollViewTest.h"
#endif

#include "03_ScrollViewTestDoc.h"
#include "03_ScrollViewTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03ScrollViewTestView

IMPLEMENT_DYNCREATE(CMy03ScrollViewTestView, CScrollView)

BEGIN_MESSAGE_MAP(CMy03ScrollViewTestView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy03ScrollViewTestView construction/destruction

CMy03ScrollViewTestView::CMy03ScrollViewTestView() noexcept
{
	// TODO: add construction code here

}

CMy03ScrollViewTestView::~CMy03ScrollViewTestView()
{
}

BOOL CMy03ScrollViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CMy03ScrollViewTestView drawing

void CMy03ScrollViewTestView::OnDraw(CDC* pDC)
{
	CMy03ScrollViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOutW(20, 20, CString(_T("스크롤 뷰를 연습합니다.")));
	pDC->Ellipse(1930, 1930, 1980, 1980);
}

void CMy03ScrollViewTestView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 2000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMy03ScrollViewTestView printing

BOOL CMy03ScrollViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy03ScrollViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy03ScrollViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy03ScrollViewTestView diagnostics

#ifdef _DEBUG
void CMy03ScrollViewTestView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy03ScrollViewTestView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy03ScrollViewTestDoc* CMy03ScrollViewTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03ScrollViewTestDoc)));
	return (CMy03ScrollViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy03ScrollViewTestView message handlers
