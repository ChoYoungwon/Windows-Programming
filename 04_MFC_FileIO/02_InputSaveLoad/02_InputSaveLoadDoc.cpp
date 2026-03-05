
// 02_InputSaveLoadDoc.cpp : implementation of the CMy02InputSaveLoadDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_InputSaveLoad.h"
#endif

#include "02_InputSaveLoadDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy02InputSaveLoadDoc

IMPLEMENT_DYNCREATE(CMy02InputSaveLoadDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy02InputSaveLoadDoc, CDocument)
	ON_COMMAND(ID_STYLE_ITALIC, &CMy02InputSaveLoadDoc::OnStyleItalic)
	ON_UPDATE_COMMAND_UI(ID_STYLE_ITALIC, &CMy02InputSaveLoadDoc::OnUpdateStyleItalic)
	ON_COMMAND(ID_STYLE_UNDERLINE, &CMy02InputSaveLoadDoc::OnStyleUnderline)
	ON_UPDATE_COMMAND_UI(ID_STYLE_UNDERLINE, &CMy02InputSaveLoadDoc::OnUpdateStyleUnderline)
END_MESSAGE_MAP()


// CMy02InputSaveLoadDoc construction/destruction

CMy02InputSaveLoadDoc::CMy02InputSaveLoadDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMy02InputSaveLoadDoc::~CMy02InputSaveLoadDoc()
{
}

BOOL CMy02InputSaveLoadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	m_str.RemoveAll();
	m_bItalic = m_bUnderline = FALSE;

	return TRUE;
}


// CMy02InputSaveLoadDoc serialization

void CMy02InputSaveLoadDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_bItalic << m_bUnderline;
		m_str.Serialize(ar);
	}
	else
	{
		ar >> m_bItalic >> m_bUnderline;
		m_str.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMy02InputSaveLoadDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CMy02InputSaveLoadDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy02InputSaveLoadDoc::SetSearchContent(const CString& value)
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

// CMy02InputSaveLoadDoc diagnostics

#ifdef _DEBUG
void CMy02InputSaveLoadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy02InputSaveLoadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy02InputSaveLoadDoc commands

void CMy02InputSaveLoadDoc::OnStyleItalic()
{
	m_bItalic = !m_bItalic;
	SetModifiedFlag();
	UpdateAllViews(NULL);	// 뷰의 화면을 갱신한다.
}

void CMy02InputSaveLoadDoc::OnUpdateStyleItalic(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bItalic == TRUE);
}

void CMy02InputSaveLoadDoc::OnStyleUnderline()
{
	m_bUnderline = !m_bUnderline;
	SetModifiedFlag();
	UpdateAllViews(NULL);	// 뷰의 화면을 갱신한다.
}

void CMy02InputSaveLoadDoc::OnUpdateStyleUnderline(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bUnderline == TRUE);
}
