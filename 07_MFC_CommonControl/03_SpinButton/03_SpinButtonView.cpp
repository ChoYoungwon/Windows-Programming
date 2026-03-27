
// 03_SpinButtonView.cpp : implementation of the CMy03SpinButtonView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "03_SpinButton.h"
#endif

#include "03_SpinButtonDoc.h"
#include "03_SpinButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03SpinButtonView

IMPLEMENT_DYNCREATE(CMy03SpinButtonView, CFormView)

BEGIN_MESSAGE_MAP(CMy03SpinButtonView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()

// CMy03SpinButtonView construction/destruction

CMy03SpinButtonView::CMy03SpinButtonView() noexcept
	: CFormView(IDD_MY03_SPINBUTTON_FORM)
{
	// TODO: add construction code here

}

CMy03SpinButtonView::~CMy03SpinButtonView()
{
}

void CMy03SpinButtonView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_spin);
}

BOOL CMy03SpinButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy03SpinButtonView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_spin.SetRange(0, 100);
	m_spin.SetPos(0);
}


// CMy03SpinButtonView printing

BOOL CMy03SpinButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy03SpinButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy03SpinButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy03SpinButtonView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy03SpinButtonView diagnostics

#ifdef _DEBUG
void CMy03SpinButtonView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy03SpinButtonView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy03SpinButtonDoc* CMy03SpinButtonView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03SpinButtonDoc)));
	return (CMy03SpinButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy03SpinButtonView message handlers

void CMy03SpinButtonView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	// 스핀 버튼 컨트롤에서 발생한 메시지인지 확인한다
	if (pScrollBar->GetSafeHwnd() == m_spin.GetSafeHwnd()) {
		CString str;
		str.Format(_T("%d"), nPos);
		AfxGetMainWnd()->SetWindowTextW(str);
		return;
	}

	CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
}
