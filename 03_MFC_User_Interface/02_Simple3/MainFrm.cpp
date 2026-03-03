
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "02_Simple3.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(nullptr, nullptr, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, nullptr))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	CMenu menuMain;				// 메뉴 객체 생성
	menuMain.CreateMenu();		// 최상위 메뉴 생성

	CMenu menuPopup;				// 메뉴 객체 생성
	menuPopup.CreatePopupMenu();	// 팝업 메뉴 생성

	// 팝업 메뉴에 메뉴 항목 세 개 추가
	menuPopup.AppendMenuW(MF_STRING, 201, _T("빨간색(&R)"));
	menuPopup.AppendMenuW(MF_STRING, 202, _T("초록색(&G)"));
	menuPopup.AppendMenuW(MF_STRING, 203, _T("파란색(&B)"));

	// 최상위 메뉴에 팝업 메뉴 추가
	menuMain.AppendMenuW(MF_POPUP, (UINT)menuPopup.Detach(), _T("색상(&C)"));

	SetMenu(&menuMain);								// 메뉴를 윈도우에 붙임
	menuMain.Detach();								// 메뉴 객체와 메뉴를 분리

	// '항목2'의 하위 메뉴를 생성한다.
	CMenu Popup1;									// 메뉴 객체 생성
	Popup1.CreatePopupMenu();						// 팝업 메뉴 생성
	Popup1.AppendMenuW(MF_STRING, 301, _T("1"));
	Popup1.AppendMenuW(MF_STRING, 302, _T("2"));
	Popup1.AppendMenuW(MF_STRING, 303, _T("3"));
	Popup1.AppendMenuW(MF_STRING, 304, _T("4"));

	// '테스트' 메뉴를  생성한다.
	CMenu Popup2;
	Popup2.CreatePopupMenu();	// 팝업 메뉴 생성
	Popup2.AppendMenuW(MF_STRING | MF_CHECKED, 201, _T("항목&1"));
	Popup2.AppendMenuW(MF_POPUP, (UINT)Popup1.Detach(), _T("항목&2"));
	Popup2.AppendMenuW(MF_STRING, 203, _T("항목&3"));

	// '테스트' 메뉴를 체상위 메뉴에 붙인다.
	CMenu* pTopLevel = GetMenu();
	pTopLevel->AppendMenuW(MF_POPUP, (UINT)Popup2.Detach(), _T("테스트(&T)"));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

