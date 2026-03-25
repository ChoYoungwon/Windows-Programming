
// 01_SplitterView.cpp : implementation of the CMy01SplitterView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "01_Splitter.h"
#endif

#include "01_SplitterDoc.h"
#include "01_SplitterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01SplitterView

IMPLEMENT_DYNCREATE(CMy01SplitterView, CView)

BEGIN_MESSAGE_MAP(CMy01SplitterView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy01SplitterView construction/destruction

CMy01SplitterView::CMy01SplitterView() noexcept
{
	// TODO: add construction code here

}

CMy01SplitterView::~CMy01SplitterView()
{
}

BOOL CMy01SplitterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy01SplitterView drawing

void CMy01SplitterView::OnDraw(CDC* pDC)
{
	CMy01SplitterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->SelectStockObject(LTGRAY_BRUSH);
	for (int i = 0; i < pDoc->m_points.GetSize(); i++) {
		pDC->Ellipse(pDoc->m_points[i].x - 20, pDoc->m_points[i].y - 20,
			pDoc->m_points[i].x + 20, pDoc->m_points[i].y + 20);
	}
}


// CMy01SplitterView printing

BOOL CMy01SplitterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy01SplitterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy01SplitterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy01SplitterView diagnostics

#ifdef _DEBUG
void CMy01SplitterView::AssertValid() const
{
	CView::AssertValid();
}

void CMy01SplitterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy01SplitterDoc* CMy01SplitterView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy01SplitterDoc)));
	return (CMy01SplitterDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy01SplitterView message handlers
void CMy01SplitterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMy01SplitterDoc* pDoc = GetDocument();
	pDoc->m_points.Add(point);
	pDoc->UpdateAllViews(NULL);

	CView::OnLButtonDown(nFlags, point);
}
