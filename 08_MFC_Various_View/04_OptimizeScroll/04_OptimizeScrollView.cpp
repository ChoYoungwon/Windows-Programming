
// 04_OptimizeScrollView.cpp : implementation of the CMy04OptimizeScrollView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "04_OptimizeScroll.h"
#endif

#include "04_OptimizeScrollDoc.h"
#include "04_OptimizeScrollView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04OptimizeScrollView

IMPLEMENT_DYNCREATE(CMy04OptimizeScrollView, CScrollView)

BEGIN_MESSAGE_MAP(CMy04OptimizeScrollView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMy04OptimizeScrollView construction/destruction

CMy04OptimizeScrollView::CMy04OptimizeScrollView() noexcept
{
	// TODO: add construction code here

}

CMy04OptimizeScrollView::~CMy04OptimizeScrollView()
{
}

BOOL CMy04OptimizeScrollView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CMy04OptimizeScrollView drawing

void CMy04OptimizeScrollView::OnDraw(CDC* pDC)
{
	CMy04OptimizeScrollDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 무효 직사각형을 얻는다.
	CRect rect;
	pDC->GetClipBox(&rect);
	rect.InflateRect(100, 100, 100, 100);

	CString str;
	for (int x = 0; x < 4000; x += 100) {
		for (int y = 0; y < 4000; y += 100) {
			// 무효 직사각형에 포함되지 않으면 출력하지 않는다.
			// 아래 두 줄을 제거하면 스크롤 속도가 매우 느려진다.
			if (!rect.PtInRect(CPoint(x, y)))
				continue;

			// 느린 속도로 정사각형을 그린다.
			MyDraw(pDC, x + 50, y + 50);

			// 정사각형 중심 좌표를 출력한다.
			str.Format(_T("(%d, %d"), x + 50, y + 50);
			pDC->SetBkMode(TRANSPARENT);
			pDC->DrawText(str, CRect(x, y, x + 100, y + 100), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
	}



}

void CMy04OptimizeScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// 주석 처리
	//CSize sizeTotal;
	//// TODO: calculate the total size of this view
	//sizeTotal.cx = sizeTotal.cy = 100;
	//SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMy04OptimizeScrollView printing

BOOL CMy04OptimizeScrollView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy04OptimizeScrollView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy04OptimizeScrollView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy04OptimizeScrollView diagnostics

#ifdef _DEBUG
void CMy04OptimizeScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMy04OptimizeScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMy04OptimizeScrollDoc* CMy04OptimizeScrollView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04OptimizeScrollDoc)));
	return (CMy04OptimizeScrollDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy04OptimizeScrollView message handlers

void CMy04OptimizeScrollView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	CSize sizeTotal(4000, 4000);
	CSize sizePage(cx - 50, cy - 50);
	CSize sizeLine(50, 50);
	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
}

void CMy04OptimizeScrollView::MyDraw(CDC* pDC, int x, int y)
{
	CPen pen(PS_SOLID, 1, RGB(x % 256, y % 256, (x + y) % 128));
	pDC->SelectObject(&pen);
	pDC->SelectStockObject(NULL_BRUSH);
	for (int i = 50; i > 0; i--) {
		// 같은 출력 코드를 두 번 실행하여 속도가 느려지게 한다.
		// 빠른 컴퓨터를 사용할 경우 몇 줄 더 추가해서 실습한다.
		pDC->Rectangle(x - i, y - i, x + i, y + i);
		pDC->Rectangle(x - i, y - i, x + i, y + i);
	}
}

BOOL CMy04OptimizeScrollView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE;
}
