
// 04_EditCtrlView.cpp : implementation of the CMy04EditCtrlView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "04_EditCtrl.h"
#endif

#include "04_EditCtrlDoc.h"
#include "04_EditCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04EditCtrlView

IMPLEMENT_DYNCREATE(CMy04EditCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CMy04EditCtrlView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_EN_MAXTEXT(IDC_MYEDIT, &CMy04EditCtrlView::OnEnMaxtextMyedit)
	ON_EN_CHANGE(IDC_MYEDIT, &CMy04EditCtrlView::OnEnChangeMyedit)
END_MESSAGE_MAP()

// CMy04EditCtrlView construction/destruction

CMy04EditCtrlView::CMy04EditCtrlView() noexcept
	: CFormView(IDD_MY04_EDITCTRL_FORM)
{
	// TODO: add construction code here

}

CMy04EditCtrlView::~CMy04EditCtrlView()
{
}

void CMy04EditCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYEDIT, m_edit);
	DDX_Control(pDX, IDC_MYSTATIC, m_static);
}

BOOL CMy04EditCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy04EditCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_edit.SetLimitText(20);
}


// CMy04EditCtrlView printing

BOOL CMy04EditCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy04EditCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy04EditCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy04EditCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy04EditCtrlView diagnostics

#ifdef _DEBUG
void CMy04EditCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy04EditCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy04EditCtrlDoc* CMy04EditCtrlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04EditCtrlDoc)));
	return (CMy04EditCtrlDoc*)m_pDocument;
}
#endif //_DEBUG

void CMy04EditCtrlView::OnEnMaxtextMyedit()
{
	MessageBox(_T("최대 길이 도달!"), _T("오류"), MB_ICONERROR);
}

void CMy04EditCtrlView::OnEnChangeMyedit()
{
	CString str;
	m_edit.GetWindowText(str);
	m_static.SetWindowTextW(str);
}
