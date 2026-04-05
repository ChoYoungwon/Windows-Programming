
// 03_TCPServer2Doc.cpp : implementation of the CMy03TCPServer2Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "03_TCPServer2.h"
#endif

#include "03_TCPServer2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CListenSocket.h"
#include "CDataSocket.h"
#include "03_TCPServer2View.h"


// CMy03TCPServer2Doc

IMPLEMENT_DYNCREATE(CMy03TCPServer2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy03TCPServer2Doc, CDocument)
END_MESSAGE_MAP()


// CMy03TCPServer2Doc construction/destruction

CMy03TCPServer2Doc::CMy03TCPServer2Doc() noexcept
{
	// TODO: add one-time construction code here
	m_pListenSocket = NULL;
	m_pDataSocket = NULL;
}

CMy03TCPServer2Doc::~CMy03TCPServer2Doc()
{
	if (m_pListenSocket != NULL)
		delete m_pListenSocket;
	if (m_pDataSocket != NULL)
		delete m_pDataSocket;
}

BOOL CMy03TCPServer2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(nullptr);
	}

	ASSERT(m_pListenSocket == NULL);
	m_pListenSocket = new CListenSocket(this);
	if (m_pListenSocket->Create(8000)) {
		if (m_pListenSocket->Listen()) {
			AfxMessageBox(_T("서버를 시작합니다."), MB_ICONINFORMATION);
			return TRUE;
		}
	}

	AfxMessageBox(_T("이미 실행 중인 서버가 있습니다.")
		_T("\n프로그램을 종료합니다. "), MB_ICONERROR);
	return FALSE;
}




// CMy03TCPServer2Doc serialization

void CMy03TCPServer2Doc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
	}
#ifdef SHARED_HANDLERS

	if (m_viewList.IsEmpty() && ar.IsLoading())
	{
		CFile* pFile = ar.GetFile();
		pFile->Seek(0, FILE_BEGIN);
		ULONGLONG nFileSizeBytes = pFile->GetLength();
		ULONGLONG nFileSizeChars = nFileSizeBytes/sizeof(TCHAR);
		LPTSTR lpszText = (LPTSTR)malloc(((size_t)nFileSizeChars + 1) * sizeof(TCHAR));
		if (lpszText != nullptr)
		{
			ar.Read(lpszText, (UINT)nFileSizeBytes);
			lpszText[nFileSizeChars] = '\0';
			m_strThumbnailContent = lpszText;
			m_strSearchContent = lpszText;
		}
	}
#endif
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMy03TCPServer2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(m_strThumbnailContent, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMy03TCPServer2Doc::InitializeSearchContent()
{
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// Use the entire text file content as the search content.
	SetSearchContent(m_strSearchContent);
}

void CMy03TCPServer2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy03TCPServer2Doc diagnostics

#ifdef _DEBUG
void CMy03TCPServer2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy03TCPServer2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy03TCPServer2Doc commands

void CMy03TCPServer2Doc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class

	if (m_pListenSocket != NULL) {
		delete m_pListenSocket;
		m_pListenSocket = NULL;
	}
	if (m_pDataSocket != NULL) {
		delete m_pDataSocket;
		m_pDataSocket = NULL;
	}

	CDocument::DeleteContents();
}

void CMy03TCPServer2Doc::PrintMessage(LPCTSTR message)
{
	CFrameWnd* pMainWnd = (CFrameWnd*)AfxGetMainWnd();
	CMy03TCPServer2View* pView = (CMy03TCPServer2View*)pMainWnd->GetActiveView();
	pView->AddMessage(message);
}

void CMy03TCPServer2Doc::ProcessAccept(int nErrorCode)
{
	CString PeerAddr;
	UINT PeerPort;
	CString str;

	ASSERT(nErrorCode == 0);
	if (m_pDataSocket == NULL) {
		m_pDataSocket = new CDataSocket(this);
		if (m_pListenSocket->Accept(*m_pDataSocket)) {
			m_pDataSocket->GetPeerName(PeerAddr, PeerPort);
			str.Format(_T("### IP 주소: %s, 포트 번호: %d ###\r\n"),
				PeerAddr, PeerPort);
			PrintMessage(str);
		}
		else {
			delete m_pDataSocket;
			m_pDataSocket = NULL;
		}
	}
}

void CMy03TCPServer2Doc::ProcessReceive(CDataSocket* pSocket, int nErrorCode)
{
	TCHAR buf[256 + 1];
	int nbytes = pSocket->Receive(buf, 256);
	buf[nbytes] = _T('\0');
	PrintMessage(buf);
}

void CMy03TCPServer2Doc::ProcessClose(CDataSocket* pSocket, int nErrorCode)
{
	pSocket->Close();
	delete m_pDataSocket;
	m_pDataSocket = NULL;
	PrintMessage(_T("### 접속 종료 ### \r\n\r\n"));
}