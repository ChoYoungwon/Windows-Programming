#pragma once

// CDataSocket command target

class CMy04TCPClient2Dlg;

class CDataSocket : public CSocket
{
public:
	CDataSocket(CMy04TCPClient2Dlg* pDlg);
	virtual ~CDataSocket();
	CMy04TCPClient2Dlg* m_pDlg;
};


