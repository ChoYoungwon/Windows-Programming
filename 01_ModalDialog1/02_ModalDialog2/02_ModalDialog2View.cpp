
// 02_ModalDialog2View.cpp : implementation of the CMy02ModalDialog2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_ModalDialog2.h"
#endif

#include "02_ModalDialog2Doc.h"
#include "02_ModalDialog2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CMyDialog.h"

// CMy02ModalDialog2View

IMPLEMENT_DYNCREATE(CMy02ModalDialog2View, CFormView)

BEGIN_MESSAGE_MAP(CMy02ModalDialog2View, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy02ModalDialog2View construction/destruction

CMy02ModalDialog2View::CMy02ModalDialog2View() noexcept
	: CFormView(IDD_MY02_MODALDIALOG2_FORM)
{
	// TODO: add construction code here
	m_str = _T("");
	m_font = 0;
}

CMy02ModalDialog2View::~CMy02ModalDialog2View()
{
}

void CMy02ModalDialog2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMy02ModalDialog2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy02ModalDialog2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}


// CMy02ModalDialog2View printing

BOOL CMy02ModalDialog2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy02ModalDialog2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy02ModalDialog2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy02ModalDialog2View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy02ModalDialog2View diagnostics

#ifdef _DEBUG
void CMy02ModalDialog2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy02ModalDialog2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy02ModalDialog2Doc* CMy02ModalDialog2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02ModalDialog2Doc)));
	return (CMy02ModalDialog2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy02ModalDialog2View message handlers

void CMy02ModalDialog2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CMyDialog dlg;
	dlg.m_str = m_str;
	dlg.m_font = m_font;

	int result = dlg.DoModal();
	if (result == IDOK) {
		m_str = dlg.m_str;
		m_font = dlg.m_font;
		Invalidate();			// ºä È­¸é¿¡ Ãâ·ÂÇÑ´Ù.
	}
	else if (result == IDC_CLEAR) {
		m_str = _T("");
		Invalidate();
	}


	CFormView::OnLButtonDown(nFlags, point);
}

void CMy02ModalDialog2View::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class
	CMy02ModalDialog2Doc* pDoc = GetDocument();
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
