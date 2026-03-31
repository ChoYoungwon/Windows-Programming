
// 06_WebBrowserView.cpp : implementation of the CMy06WebBrowserView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "06_WebBrowser.h"
#endif

#include "06_WebBrowserDoc.h"
#include "06_WebBrowserView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CMyDialog.h"


// CMy06WebBrowserView

IMPLEMENT_DYNCREATE(CMy06WebBrowserView, CHtmlView)

BEGIN_MESSAGE_MAP(CMy06WebBrowserView, CHtmlView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_WEBSEARCH_OPEN, &CMy06WebBrowserView::OnWebsearchOpen)
	ON_COMMAND(ID_WEBSEARCH_BACK, &CMy06WebBrowserView::OnWebsearchBack)
	ON_COMMAND(ID_WEBSEARCH_FORWARD, &CMy06WebBrowserView::OnWebsearchForward)
END_MESSAGE_MAP()

// CMy06WebBrowserView construction/destruction

CMy06WebBrowserView::CMy06WebBrowserView() noexcept
{
	// TODO: add construction code here

}

CMy06WebBrowserView::~CMy06WebBrowserView()
{
}

BOOL CMy06WebBrowserView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CMy06WebBrowserView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	/*Navigate2(_T("http://www.msdn.microsoft.com/visualc/"),nullptr, nullptr);*/
	m_pBrowserApp->put_Silent(VARIANT_TRUE);		// 스크립트 오류 표시 끄기
	GoHome();
}


// CMy06WebBrowserView printing



// CMy06WebBrowserView diagnostics

#ifdef _DEBUG
void CMy06WebBrowserView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMy06WebBrowserView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CMy06WebBrowserDoc* CMy06WebBrowserView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy06WebBrowserDoc)));
	return (CMy06WebBrowserDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy06WebBrowserView message handlers

void CMy06WebBrowserView::OnWebsearchOpen()
{
	CMyDialog dlg;
	if (dlg.DoModal() == IDOK)
		Navigate(dlg.m_url);
}

void CMy06WebBrowserView::OnWebsearchBack()
{
	GoBack();
}

void CMy06WebBrowserView::OnWebsearchForward()
{
	GoForward();
}
