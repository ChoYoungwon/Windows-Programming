// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "03_ModalDialog3.h"
#include "afxdialogex.h"
#include "CMyDialog.h"


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
	DDV_MaxChars(pDX, m_str, 10);
	DDX_CBIndex(pDX, IDC_FONT, m_font);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDC_CLEAR, &CMyDialog::OnBnClickedClear)
END_MESSAGE_MAP()


// CMyDialog message handlers

void CMyDialog::OnBnClickedClear()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDC_CLEAR);
}
