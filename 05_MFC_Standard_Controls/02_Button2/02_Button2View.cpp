
// 02_Button2View.cpp : implementation of the CMy02Button2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_Button2.h"
#endif

#include "02_Button2Doc.h"
#include "02_Button2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02Button2View

IMPLEMENT_DYNCREATE(CMy02Button2View, CFormView)

BEGIN_MESSAGE_MAP(CMy02Button2View, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy02Button2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMy02Button2View construction/destruction

CMy02Button2View::CMy02Button2View() noexcept
	: CFormView(IDD_MY02_BUTTON2_FORM)
{
	// TODO: add construction code here

}

CMy02Button2View::~CMy02Button2View()
{
}

void CMy02Button2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_checkbox);
	DDX_Control(pDX, IDC_CHECK2, m_3state);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
}

BOOL CMy02Button2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy02Button2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_checkbox.SetCheck(1);
	m_3state.SetCheck(2);
	m_radio2.SetCheck(1);
}


// CMy02Button2View printing

BOOL CMy02Button2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy02Button2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy02Button2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy02Button2View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy02Button2View diagnostics

#ifdef _DEBUG
void CMy02Button2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy02Button2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy02Button2Doc* CMy02Button2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02Button2Doc)));
	return (CMy02Button2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy02Button2View message handlers

void CMy02Button2View::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	int state_checkbox = m_checkbox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio1.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("버튼 상태: %d, %d, %d, %d"), state_checkbox, state_3state, state_radio1, state_radio2);
	MessageBox(str, _T("Button2 예제"), MB_ICONINFORMATION);
}
