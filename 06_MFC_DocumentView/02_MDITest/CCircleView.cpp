// CCircleView.cpp : implementation file
//

#include "pch.h"
#include "02_MDITest.h"
#include "CCircleView.h"
#include "CCircleDoc.h"


// CCircleView

IMPLEMENT_DYNCREATE(CCircleView, CView)

CCircleView::CCircleView()
{

}

CCircleView::~CCircleView()
{
}

BEGIN_MESSAGE_MAP(CCircleView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CCircleView drawing

void CCircleView::OnDraw(CDC* pDC)
{
	CCircleDoc* pDoc = (CCircleDoc*)GetDocument();
	pDC->SelectStockObject(LTGRAY_BRUSH);
	for (int i = 0; i < pDoc->m_points.GetSize(); i++) {
		pDC->Ellipse(pDoc->m_points[i].x - 20, pDoc->m_points[i].y - 20,
			pDoc->m_points[i].x + 20, pDoc->m_points[i].y + 20);
	}
}

// CCircleView diagnostics

#ifdef _DEBUG
void CCircleView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCircleView message handlers

void CCircleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CCircleDoc* pDoc = (CCircleDoc*)GetDocument();
	pDoc->m_points.Add(point);
	pDoc->UpdateAllViews(NULL);
}
