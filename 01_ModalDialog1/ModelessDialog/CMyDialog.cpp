// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "ModelessDialog.h"
#include "afxdialogex.h"
#include "CMyDialog.h"

#include "ModelessDialogDoc.h"
#include "ModelessDialogView.h"

// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_str(_T(""))
	, m_font(0)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR, m_str);
	DDX_CBIndex(pDX, IDC_FONT, m_font);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDAPPLY, &CMyDialog::OnBnClickedApply)
END_MESSAGE_MAP()


// CMyDialog message handlers

void CMyDialog::OnBnClickedApply()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);				// DDX를 직접 동작시킨다.
	m_pView->m_str = m_str;
	m_pView->m_font = m_font;
	m_pView->Invalidate();			// WM_PAINT 메시지 발생 -> OnDraw() 함수 실행
}

void CMyDialog::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	DestroyWindow();				// 대화 상자를 파괴한다.
}

void CMyDialog::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	m_pView->m_pDlg = NULL;
	delete this;					// 대화 상자 객체를 파괴한다.
	CDialog::PostNcDestroy();
}
