
// 05_ListBoxView.cpp : implementation of the CMy05ListBoxView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "05_ListBox.h"
#endif

#include "05_ListBoxDoc.h"
#include "05_ListBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy05ListBoxView

IMPLEMENT_DYNCREATE(CMy05ListBoxView, CFormView)

BEGIN_MESSAGE_MAP(CMy05ListBoxView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_RIGHT, &CMy05ListBoxView::OnBnClickedRight)
	ON_BN_CLICKED(IDC_LEFT, &CMy05ListBoxView::OnBnClickedLeft)
END_MESSAGE_MAP()

// CMy05ListBoxView construction/destruction

CMy05ListBoxView::CMy05ListBoxView() noexcept
	: CFormView(IDD_MY05_LISTBOX_FORM)
{
	// TODO: add construction code here

}

CMy05ListBoxView::~CMy05ListBoxView()
{
}

void CMy05ListBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_RIGHT, m_right);
	DDX_Control(pDX, IDC_LEFT, m_left);
}

BOOL CMy05ListBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy05ListBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_list1.AddString(_T("사과"));
	m_list1.AddString(_T("딸기"));
	m_list1.AddString(_T("파인애플"));
	m_list1.AddString(_T("복숭아"));
}


// CMy05ListBoxView printing

BOOL CMy05ListBoxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy05ListBoxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy05ListBoxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy05ListBoxView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy05ListBoxView diagnostics

#ifdef _DEBUG
void CMy05ListBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy05ListBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy05ListBoxDoc* CMy05ListBoxView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy05ListBoxDoc)));
	return (CMy05ListBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy05ListBoxView message handlers

void CMy05ListBoxView::OnBnClickedRight()
{
	int nIndex = m_list1.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_list1.GetText(nIndex, str);
		m_list1.DeleteString(nIndex);
		m_list1.SetCurSel(nIndex);		// 삭제된 다음 위치의 항목이 자동 선택됨
		m_list2.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("왼쪽에서 오른쪽으로..."));
	}
}

void CMy05ListBoxView::OnBnClickedLeft()
{
	int nIndex = m_list2.GetCurSel();
	if (nIndex != LB_ERR) {
		CString str;
		m_list2.GetText(nIndex, str);
		m_list2.DeleteString(nIndex);
		m_list2.SetCurSel(nIndex);		// 삭제된 다음 위치의 항목이 자동 선택됨
		m_list1.AddString(str);
		AfxGetMainWnd()->SetWindowText(_T("오른쪽에서 왼쪽으로..."));
	}
}
