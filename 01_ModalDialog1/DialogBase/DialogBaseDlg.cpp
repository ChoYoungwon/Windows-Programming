
// DialogBaseDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DialogBase.h"
#include "DialogBaseDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogBaseDlg dialog



CDialogBaseDlg::CDialogBaseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGBASE_DIALOG, pParent)
	, m_num1(1)
	, m_num2(45)
	, m_count(6)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDV_MinMaxInt(pDX, m_num1, 1, 99);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDV_MinMaxInt(pDX, m_num2, 1, 99);
	DDX_Text(pDX, IDC_EDIT3, m_count);
	DDV_MinMaxInt(pDX, m_count, 1, 99);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CDialogBaseDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CDialogBaseDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// CDialogBaseDlg message handlers

BOOL CDialogBaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDialogBaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDialogBaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDialogBaseDlg::OnBnClickedStart()
{
	if (UpdateData(TRUE) == 0)		// DDX/DDV를 직접 동작시킨다.
		return;

	if (m_num1 >= m_num2) {
		MessageBox(_T("숫자1 >= 숫자2"), _T("오류!"), MB_ICONERROR);
		return;
	}

	m_list.ResetContent();			// 리스트 박스 내용을 지운다.
	srand((unsigned)time(NULL));	// 난수 발생기를 초기화한다.

	for (int i = 0; i < m_count; i++) {
		CString str;
		str.Format(_T("%02d"), 1 + rand() % (m_num2 - m_num1 + 1));
		m_list.AddString(str);		// 생성된 난수를 리스트 박스에 추가한다.
	}
}
