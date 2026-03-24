
// DialogBaseDlg.h : header file
//

#pragma once


// CDialogBaseDlg dialog
class CDialogBaseDlg : public CDialogEx
{
// Construction
public:
	CDialogBaseDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGBASE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_num1;
	int m_num2;
	int m_count;
	CListBox m_list;
	afx_msg void OnBnClickedStart();
};
