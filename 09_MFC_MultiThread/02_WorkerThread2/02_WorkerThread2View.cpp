
// 02_WorkerThread2View.cpp : implementation of the CMy02WorkerThread2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_WorkerThread2.h"
#endif

#include "02_WorkerThread2Doc.h"
#include "02_WorkerThread2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02WorkerThread2View

IMPLEMENT_DYNCREATE(CMy02WorkerThread2View, CView)

BEGIN_MESSAGE_MAP(CMy02WorkerThread2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy02WorkerThread2View construction/destruction

CMy02WorkerThread2View::CMy02WorkerThread2View() noexcept
{
	// TODO: add construction code here

}

CMy02WorkerThread2View::~CMy02WorkerThread2View()
{
}

BOOL CMy02WorkerThread2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy02WorkerThread2View drawing

void CMy02WorkerThread2View::OnDraw(CDC* /*pDC*/)
{
	CMy02WorkerThread2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy02WorkerThread2View printing

BOOL CMy02WorkerThread2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy02WorkerThread2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy02WorkerThread2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy02WorkerThread2View diagnostics

#ifdef _DEBUG
void CMy02WorkerThread2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy02WorkerThread2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02WorkerThread2Doc* CMy02WorkerThread2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02WorkerThread2Doc)));
	return (CMy02WorkerThread2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy02WorkerThread2View message handlers
#define LOOPCNT (200000)
#define DIVCNT (LOOPCNT / 500)

UINT MyDraw(LPVOID arg) {
	ThreadArg* pArg = (ThreadArg*)arg;
	CClientDC dc(pArg->pWnd);
	int x, y, i;
	CBrush brush1(RGB(255, 0, 0));
	CBrush brush2(RGB(0, 0, 255));

	// 서로 다른 위치에 느린 속도로 막대를  출력한다.
	switch (pArg->pos) {
	case 1:
		dc.SelectObject(&brush1);
		x = 50; y = 50;
		for (i = 0; i < LOOPCNT; i++) {
			int inc = i / DIVCNT;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	case 2:
		dc.SelectObject(&brush2);
		x = 50; y = 100;
		for (i = 0; i < LOOPCNT; i++) {
			int inc = i / DIVCNT;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	}

	return 0;
}


void CMy02WorkerThread2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 화면을 지운다.
	CClientDC dc(this);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(&rect);

	// 첫 번째 스레드를 중지 상태로 생성한다.
	arg1.pWnd = this;	// 뷰 객체의 주소
	arg1.pos = 1;		// 출력 위치(1: 위쪽)
	pThread1 = AfxBeginThread(MyDraw, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	// 두 번째 스레드를 중지 상태로 생성한다.
	arg2.pWnd = this;	// 뷰 객체의 주소
	arg2.pos = 2;		// 출력 위치(2: 아래쪽)
	pThread2 = AfxBeginThread(MyDraw, &arg2, THREAD_PRIORITY_ABOVE_NORMAL, 0, CREATE_SUSPENDED);

	// 두 스레드의 실행을 재개한다.
	pThread1->ResumeThread();
	pThread2->ResumeThread();
}
