
// 01_Button1View.cpp : implementation of the CMy01Button1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "01_Button1.h"
#endif

#include "01_Button1Doc.h"
#include "01_Button1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01Button1View

IMPLEMENT_DYNCREATE(CMy01Button1View, CView)

BEGIN_MESSAGE_MAP(CMy01Button1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_BN_CLICKED(101, OnButtonClicked)
END_MESSAGE_MAP()

// CMy01Button1View construction/destruction

CMy01Button1View::CMy01Button1View() noexcept
{
	// TODO: add construction code here

}

CMy01Button1View::~CMy01Button1View()
{
}

BOOL CMy01Button1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy01Button1View drawing

void CMy01Button1View::OnDraw(CDC* pDC)
{
	CMy01Button1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMy01Button1View printing

BOOL CMy01Button1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy01Button1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy01Button1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy01Button1View diagnostics

#ifdef _DEBUG
void CMy01Button1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy01Button1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy01Button1Doc* CMy01Button1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy01Button1Doc)));
	return (CMy01Button1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy01Button1View message handlers

int CMy01Button1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 버튼 컨트롤을  생성한다.
	m_pushbutton.Create(_T("푸시 버튼"), 
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, CRect(20, 20, 160, 50), this, 101);
	m_checkbox.Create(_T("체크 박스"), 
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, CRect(20, 60, 160, 90), this, 102);
	m_3state.Create(_T("3상태 체크 박스"),
		WS_CHILD | WS_VISIBLE | BS_AUTO3STATE, CRect(20, 100, 160, 130), this, 103);
	m_radio1.Create(_T("라디오 버튼 1"),
		WS_CHILD | WS_VISIBLE | WS_GROUP | BS_AUTORADIOBUTTON, CRect(20, 170, 160, 200), this, 104);
	m_radio2.Create(_T("라디오 버튼 2"),
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, CRect(20, 210, 160, 240), this, 105);
	m_groupbox.Create(_T("그룹 박스"),
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX, CRect(10, 140, 170, 250), this, 106);

	// 버튼 컨트롤을 초기화한다.
	m_checkbox.SetCheck(1);
	m_3state.SetCheck(2);
	m_radio2.SetCheck(1);

	return 0;
}

void CMy01Button1View::OnButtonClicked()
{
	int state_checkbox = m_checkbox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio1.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("버튼 상태: %d, %d, %d, %d"), state_checkbox, state_3state, state_radio1, state_radio2);
	MessageBox(str, _T("Button1 예제"), MB_ICONINFORMATION);
}
