
// 01_ImageListView.cpp : implementation of the CMy01ImageListView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "01_ImageList.h"
#endif

#include "01_ImageListDoc.h"
#include "01_ImageListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01ImageListView

IMPLEMENT_DYNCREATE(CMy01ImageListView, CView)

BEGIN_MESSAGE_MAP(CMy01ImageListView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMy01ImageListView construction/destruction

CMy01ImageListView::CMy01ImageListView() noexcept
{
	// TODO: add construction code here

}

CMy01ImageListView::~CMy01ImageListView()
{
}

BOOL CMy01ImageListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy01ImageListView drawing

void CMy01ImageListView::OnDraw(CDC* pDC)
{
	CMy01ImageListDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 클라이언트 영역을 패턴 브러시로 칠한다.
	CBrush brush(HS_DIAGCROSS, RGB(255, 0, 0));
	pDC->SelectObject(&brush);
	pDC->SelectStockObject(NULL_PEN);
	CRect rect;
	GetClientRect(&rect);
	pDC->Rectangle(&rect);

	// 배경을 투명색으로 설정하고 출력한다. 
	m_il.SetBkColor(CLR_NONE);
	m_il.Draw(pDC, 0, CPoint(50, 50), ILD_NORMAL);
	m_il.Draw(pDC, 0, CPoint(150, 50), ILD_TRANSPARENT);
	m_il.Draw(pDC, 0, CPoint(250, 50), ILD_BLEND25);
	m_il.Draw(pDC, 0, CPoint(350, 50), ILD_BLEND50);
	m_il.Draw(pDC, 0, CPoint(450, 50), ILD_MASK);

	// 배경을 검은색으로 설정하고 출력한다.
	m_il.SetBkColor(RGB(0, 0, 0));
	m_il.Draw(pDC, 1, CPoint(50, 150), ILD_NORMAL);
	m_il.Draw(pDC, 1, CPoint(150, 150), ILD_TRANSPARENT);
	m_il.Draw(pDC, 1, CPoint(250, 150), ILD_BLEND25);
	m_il.Draw(pDC, 1, CPoint(350, 150), ILD_BLEND50);
	m_il.Draw(pDC, 1, CPoint(450, 150), ILD_MASK);
}


// CMy01ImageListView printing

BOOL CMy01ImageListView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy01ImageListView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy01ImageListView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy01ImageListView diagnostics

#ifdef _DEBUG
void CMy01ImageListView::AssertValid() const
{
	CView::AssertValid();
}

void CMy01ImageListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy01ImageListDoc* CMy01ImageListView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy01ImageListDoc)));
	return (CMy01ImageListDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy01ImageListView message handlers

int CMy01ImageListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_il.Create(IDB_BITMAP1, 48, 1, RGB(255, 255, 255));

	return 0;
}
