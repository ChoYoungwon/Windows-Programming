
// 04_TCPClient2Dlg.h : header file
//

#pragma once

class CDataSocket;

// CMy04TCPClient2Dlg dialog
class CMy04TCPClient2Dlg : public CDialogEx
{
// Construction
public:
	CMy04TCPClient2Dlg(CWnd* pParent = nullptr);	// standard constructor
	CDataSocket* m_pDataSocket;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY04_TCPCLIENT2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CIPAddressCtrl m_ipaddr;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedDisconnect();
	afx_msg void OnBnClickedSend();
};
