
// 02_TabCtrlView.cpp : implementation of the CMy02TabCtrlView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_TabCtrl.h"
#endif

#include "02_TabCtrlDoc.h"
#include "02_TabCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02TabCtrlView

IMPLEMENT_DYNCREATE(CMy02TabCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CMy02TabCtrlView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMy02TabCtrlView::OnTcnSelchangeTab1)
END_MESSAGE_MAP()

// CMy02TabCtrlView construction/destruction

CMy02TabCtrlView::CMy02TabCtrlView() noexcept
	: CFormView(IDD_MY02_TABCTRL_FORM)
{
	// TODO: add construction code here

}

CMy02TabCtrlView::~CMy02TabCtrlView()
{
}

void CMy02TabCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BOOL CMy02TabCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy02TabCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	// 탭 컨트롤에 사용할 이미지 리스트를 설정한다.
	CImageList m_il;
	m_il.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));
	m_tab.SetImageList(&m_il);
	m_il.Detach();

	// 탭을 세 개 추가한다.
	m_tab.InsertItem(0, _T("Tab #0"), 0);
	m_tab.InsertItem(1, _T("Tab #1"), 0);
	m_tab.InsertItem(2, _T("Tab #2"), 0);

	// 두 번째 탭이 선택된 상태로 시작한다.
	m_tab.SetCurSel(1);
	m_edit.SetWindowTextW(_T("Tab #1 선택됨"));
}


// CMy02TabCtrlView printing

BOOL CMy02TabCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy02TabCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy02TabCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy02TabCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy02TabCtrlView diagnostics

#ifdef _DEBUG
void CMy02TabCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy02TabCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy02TabCtrlDoc* CMy02TabCtrlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02TabCtrlDoc)));
	return (CMy02TabCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy02TabCtrlView message handlers

void CMy02TabCtrlView::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	int nIndex = m_tab.GetCurSel();
	CString str;
	str.Format(_T("Tab #%d 선택됨"), nIndex);
	m_edit.SetWindowTextW(str);

	*pResult = 0;
}
