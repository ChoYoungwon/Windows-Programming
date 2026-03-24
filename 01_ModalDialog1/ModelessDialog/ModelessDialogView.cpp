
// ModelessDialogView.cpp : implementation of the CModelessDialogView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ModelessDialog.h"
#endif

#include "ModelessDialogDoc.h"
#include "ModelessDialogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CMyDialog.h"

// CModelessDialogView

IMPLEMENT_DYNCREATE(CModelessDialogView, CFormView)

BEGIN_MESSAGE_MAP(CModelessDialogView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModelessDialogView construction/destruction

CModelessDialogView::CModelessDialogView() noexcept
	: CFormView(IDD_MODELESSDIALOG_FORM)
{
	// TODO: add construction code here
	m_pDlg = NULL;
	m_str = _T("");
	m_font = 0;
}

CModelessDialogView::~CModelessDialogView()
{
}

void CModelessDialogView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CModelessDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CModelessDialogView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CModelessDialogView printing

BOOL CModelessDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CModelessDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CModelessDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CModelessDialogView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CModelessDialogView diagnostics

#ifdef _DEBUG
void CModelessDialogView::AssertValid() const
{
	CFormView::AssertValid();
}

void CModelessDialogView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CModelessDialogDoc* CModelessDialogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModelessDialogDoc)));
	return (CModelessDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CModelessDialogView message handlers

void CModelessDialogView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_pDlg != NULL)
		m_pDlg->SetFocus();	// 키보드 포커스를 대화 상자로 옮긴다.
	else {
		m_pDlg = new CMyDialog();		// 대화 상자 객체를 생성한다.
		m_pDlg->m_pView = this;			// 뷰 객체의 주소를 넘겨준다.
		m_pDlg->m_str = m_str;			// IDC_STR 컨트롤의 초기 값
		m_pDlg->m_font = m_font;		// IDC_FONT 컨트롤의 초기 값
		m_pDlg->Create(IDD_DIALOG1);	// 대화 상자를 생성한다.
		m_pDlg->ShowWindow(SW_SHOW);	// 대화 상자가 나타낸다.
	}


	CFormView::OnLButtonDown(nFlags, point);
}

void CModelessDialogView::OnDraw(CDC* pDC)
{
	CModelessDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont font;
	CString fontname;

	if (m_font == 0) fontname = _T("굴림");
	else if (m_font == 1) fontname = _T("궁서");
	else if (m_font == 2) fontname = _T("바탕");
	font.CreatePointFont(400, fontname);

	pDC->SelectObject(&font);
	pDC->TextOut(10, 10, m_str);
}
