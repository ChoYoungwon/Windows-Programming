
// 01_ModalDialog1View.cpp : implementation of the CMy01ModalDialog1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "01_ModalDialog1.h"
#endif

#include "01_ModalDialog1Doc.h"
#include "01_ModalDialog1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01ModalDialog1View

IMPLEMENT_DYNCREATE(CMy01ModalDialog1View, CView)

BEGIN_MESSAGE_MAP(CMy01ModalDialog1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy01ModalDialog1View construction/destruction

CMy01ModalDialog1View::CMy01ModalDialog1View() noexcept
{
	// TODO: add construction code here

}

CMy01ModalDialog1View::~CMy01ModalDialog1View()
{
}

BOOL CMy01ModalDialog1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy01ModalDialog1View drawing

void CMy01ModalDialog1View::OnDraw(CDC* /*pDC*/)
{
	CMy01ModalDialog1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy01ModalDialog1View printing

BOOL CMy01ModalDialog1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy01ModalDialog1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy01ModalDialog1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy01ModalDialog1View diagnostics

#ifdef _DEBUG
void CMy01ModalDialog1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy01ModalDialog1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy01ModalDialog1Doc* CMy01ModalDialog1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy01ModalDialog1Doc)));
	return (CMy01ModalDialog1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy01ModalDialog1View message handlers

void CMy01ModalDialog1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDialog dlg(IDD_DIALOG1);
	if (dlg.DoModal() == IDOK)
		MessageBox(_T("확인 버튼 누름"));
	else
		MessageBox(_T("취소 버튼 누름"));

	CView::OnLButtonDown(nFlags, point);
}
