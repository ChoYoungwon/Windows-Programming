// CMyDialog.cpp : implementation file
//

#include "pch.h"
#include "02_ModalDialog2.h"
#include "afxdialogex.h"
#include "CMyDialog.h"


// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FONT, m_combo);
	DDX_Text(pDX, IDC_STR, m_str);
	DDV_MaxChars(pDX, m_str, 10);
	DDX_CBIndex(pDX, IDC_FONT, m_font);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDC_CLEAR, &CMyDialog::OnBnClickedClear)
END_MESSAGE_MAP()


// CMyDialog message handlers

BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetDlgItemText(IDC_STR, m_str);
	m_combo.SetCurSel(m_font);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CMyDialog::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	GetDlgItemText(IDC_STR, m_str);
	m_font = m_combo.GetCurSel();
	CDialog::OnOK();
}

void CMyDialog::OnBnClickedClear()
{
	// TODO: Add your control notification handler code here
	EndDialog(IDC_CLEAR);
}
