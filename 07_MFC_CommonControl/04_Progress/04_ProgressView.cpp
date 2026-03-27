
// 04_ProgressView.cpp : implementation of the CMy04ProgressView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "04_Progress.h"
#endif

#include "04_ProgressDoc.h"
#include "04_ProgressView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04ProgressView

IMPLEMENT_DYNCREATE(CMy04ProgressView, CFormView)

BEGIN_MESSAGE_MAP(CMy04ProgressView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy04ProgressView construction/destruction

CMy04ProgressView::CMy04ProgressView() noexcept
	: CFormView(IDD_MY04_PROGRESS_FORM)
{
	// TODO: add construction code here
	bNowProgress = FALSE;
}

CMy04ProgressView::~CMy04ProgressView()
{
}

void CMy04ProgressView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
}

BOOL CMy04ProgressView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy04ProgressView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMy04ProgressView printing

BOOL CMy04ProgressView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy04ProgressView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy04ProgressView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy04ProgressView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy04ProgressView diagnostics

#ifdef _DEBUG
void CMy04ProgressView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy04ProgressView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy04ProgressDoc* CMy04ProgressView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04ProgressDoc)));
	return (CMy04ProgressDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy04ProgressView message handlers

void CMy04ProgressView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (bNowProgress == FALSE) {
		bNowProgress = TRUE;
		m_progress.SetRange(0, 30);		// 값의 범위를 설정한다.
		m_progress.SetPos(0);			// 현재 위치를 설정한다.
		SetTimer(100, 50, NULL);		// ID가 100인 타이머를 생성한다.
	}
}

void CMy04ProgressView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 100) {
		if (m_progress.GetPos() < 30)
			m_progress.OffsetPos(1);
		else {
			KillTimer(nIDEvent);
			bNowProgress = FALSE;
		}
	}
}
