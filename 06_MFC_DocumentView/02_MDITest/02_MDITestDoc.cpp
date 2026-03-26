
// 02_MDITestDoc.cpp : implementation of the CMy02MDITestDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_MDITest.h"
#endif

#include "02_MDITestDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy02MDITestDoc

IMPLEMENT_DYNCREATE(CMy02MDITestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy02MDITestDoc, CDocument)
END_MESSAGE_MAP()


// CMy02MDITestDoc construction/destruction

CMy02MDITestDoc::CMy02MDITestDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMy02MDITestDoc::~CMy02MDITestDoc()
{
}

BOOL CMy02MDITestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_str.RemoveAll();

	return TRUE;
}




// CMy02MDITestDoc serialization

void CMy02MDITestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		m_str.Serialize(ar);
	}
	else
	{
		m_str.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMy02MDITestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMy02MDITestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy02MDITestDoc::SetSearchContent(const CString& value)
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

// CMy02MDITestDoc diagnostics

#ifdef _DEBUG
void CMy02MDITestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy02MDITestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy02MDITestDoc commands
