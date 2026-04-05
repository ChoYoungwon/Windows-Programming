#pragma once

// CListenSocket command target

class CMy03TCPServer2Doc;

class CListenSocket : public CSocket
{
public:
	CListenSocket(CMy03TCPServer2Doc* pDoc);
	virtual ~CListenSocket();
	CMy03TCPServer2Doc* m_pDoc;
	virtual void OnAccept(int nErrorCode);
};


