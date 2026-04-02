
// 01_WorkerThread1View.cpp : implementation of the CMy01WorkerThread1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "01_WorkerThread1.h"
#endif

#include "01_WorkerThread1Doc.h"
#include "01_WorkerThread1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01WorkerThread1View

IMPLEMENT_DYNCREATE(CMy01WorkerThread1View, CView)

BEGIN_MESSAGE_MAP(CMy01WorkerThread1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy01WorkerThread1View construction/destruction

CMy01WorkerThread1View::CMy01WorkerThread1View() noexcept
{
	// TODO: add construction code here

}

CMy01WorkerThread1View::~CMy01WorkerThread1View()
{
}

BOOL CMy01WorkerThread1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy01WorkerThread1View drawing

void CMy01WorkerThread1View::OnDraw(CDC* /*pDC*/)
{
	CMy01WorkerThread1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy01WorkerThread1View printing

BOOL CMy01WorkerThread1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy01WorkerThread1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy01WorkerThread1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy01WorkerThread1View diagnostics

#ifdef _DEBUG
void CMy01WorkerThread1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy01WorkerThread1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy01WorkerThread1Doc* CMy01WorkerThread1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy01WorkerThread1Doc)));
	return (CMy01WorkerThread1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy01WorkerThread1View message handlers

UINT CalcIt(LPVOID arg) {
	// LPVOID를 int형으로 타입 캐스팅한다.
	int val = (int)arg;

	// 1부터 val까지 1씩 증가하면서 더한다.
	int result = 0;
	for (int i = 1; i < val; i++) {
		result += i;
		Sleep(10);		// 테스트를 위해 계산 속도를 늦춘다.
	}

	CString str;
	str.Format(_T("계산 결과 = %d"), result);
	AfxMessageBox(str);

	return 0;
}

void CMy01WorkerThread1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	int val = 600;
	/* 스레드를 사용하지 않은 경우 */
	// CalcIt((LPVOID)val);

	/*스레드를 사용한 경우 */
	AfxBeginThread(CalcIt, (LPVOID)val);
}
