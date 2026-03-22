
// 03_ModalDialog3View.cpp : implementation of the CMy03ModalDialog3View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "03_ModalDialog3.h"
#endif

#include "03_ModalDialog3Doc.h"
#include "03_ModalDialog3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CMyDialog.h"


// CMy03ModalDialog3View

IMPLEMENT_DYNCREATE(CMy03ModalDialog3View, CFormView)

BEGIN_MESSAGE_MAP(CMy03ModalDialog3View, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy03ModalDialog3View construction/destruction

CMy03ModalDialog3View::CMy03ModalDialog3View() noexcept
	: CFormView(IDD_MY03_MODALDIALOG3_FORM)
{
	// TODO: add construction code here
	m_str = _T("");
	m_font = 0;

}

CMy03ModalDialog3View::~CMy03ModalDialog3View()
{
}

void CMy03ModalDialog3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMy03ModalDialog3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy03ModalDialog3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMy03ModalDialog3View printing

BOOL CMy03ModalDialog3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy03ModalDialog3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy03ModalDialog3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy03ModalDialog3View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy03ModalDialog3View diagnostics

#ifdef _DEBUG
void CMy03ModalDialog3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy03ModalDialog3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy03ModalDialog3Doc* CMy03ModalDialog3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03ModalDialog3Doc)));
	return (CMy03ModalDialog3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03ModalDialog3View message handlers

void CMy03ModalDialog3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMyDialog dlg;
	dlg.m_str = m_str;
	dlg.m_font = m_font;

	int result = dlg.DoModal();
	if (result == IDOK) {
		m_str = dlg.m_str;
		m_font = dlg.m_font;
		Invalidate();
	}
	else if (result == IDC_CLEAR) {
		m_str = _T("");
		Invalidate();
	}


	CFormView::OnLButtonDown(nFlags, point);
}

void CMy03ModalDialog3View::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class
	CMy03ModalDialog3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	CString fontname;

	if (m_font == 0) fontname = _T("±¼¸²");
	else if (m_font == 1) fontname = _T("±Ã¼­");
	else if (m_font == 2) fontname = _T("¹ÙÅÁ");
	font.CreatePointFont(400, fontname);

	pDC->SelectObject(&font);
	pDC->TextOut(10, 10, m_str);
}
