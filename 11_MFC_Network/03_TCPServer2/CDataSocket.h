#pragma once


// CDataSocket command target

class CMy03TCPServer2Doc;

class CDataSocket : public CSocket
{
public:
	CDataSocket(CMy03TCPServer2Doc* pDoc);
	virtual ~CDataSocket();
	CMy03TCPServer2Doc* m_pDoc;
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


