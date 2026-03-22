#pragma once
#include "afxdialogex.h"


// CMyDialog dialog

class CMyDialog : public CDialog
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMyDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	CString m_str;				// 사용자가 입력한 텍스트 저장
	int m_font;					// 사용자가 선택한 폰트 번호 저장
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnBnClickedClear();
};
