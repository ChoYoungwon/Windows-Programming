
// 01_ListViewTestDoc.cpp : implementation of the CMy01ListViewTestDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "01_ListViewTest.h"
#endif

#include "01_ListViewTestDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy01ListViewTestDoc

IMPLEMENT_DYNCREATE(CMy01ListViewTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy01ListViewTestDoc, CDocument)
END_MESSAGE_MAP()


// CMy01ListViewTestDoc construction/destruction

CMy01ListViewTestDoc::CMy01ListViewTestDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMy01ListViewTestDoc::~CMy01ListViewTestDoc()
{
}

BOOL CMy01ListViewTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	for (int i = 0; i < NUMITEM; i++) {
		m_item[i].name.Format(_T("»óÇ° #%d"), i);
		m_item[i].price = 1000 + i;
		m_item[i].quantity = 10000 + i;
	}

	return TRUE;
}




// CMy01ListViewTestDoc serialization

void CMy01ListViewTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMy01ListViewTestDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy01ListViewTestDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy01ListViewTestDoc::SetSearchContent(const CString& value)
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

// CMy01ListViewTestDoc diagnostics

#ifdef _DEBUG
void CMy01ListViewTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy01ListViewTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy01ListViewTestDoc commands
