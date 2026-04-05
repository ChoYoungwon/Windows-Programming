// CListenSocket.cpp : implementation file
//

#include "pch.h"
#include "03_TCPServer2.h"
#include "CListenSocket.h"
#include "03_TCPServer2Doc.h"

// CListenSocket

CListenSocket::CListenSocket(CMy03TCPServer2Doc* pDoc)
{
	m_pDoc = pDoc;
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket member functions

void CListenSocket::OnAccept(int nErrorCode)
{
	CSocket::OnAccept(nErrorCode);
	m_pDoc->ProcessAccept(nErrorCode);
}
