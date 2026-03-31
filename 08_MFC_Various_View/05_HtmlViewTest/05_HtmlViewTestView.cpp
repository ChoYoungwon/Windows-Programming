
// 05_HtmlViewTestView.cpp : implementation of the CMy05HtmlViewTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "05_HtmlViewTest.h"
#endif

#include "05_HtmlViewTestDoc.h"
#include "05_HtmlViewTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy05HtmlViewTestView

IMPLEMENT_DYNCREATE(CMy05HtmlViewTestView, CHtmlView)

BEGIN_MESSAGE_MAP(CMy05HtmlViewTestView, CHtmlView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

// CMy05HtmlViewTestView construction/destruction

CMy05HtmlViewTestView::CMy05HtmlViewTestView() noexcept
{
	// TODO: add construction code here

}

CMy05HtmlViewTestView::~CMy05HtmlViewTestView()
{
}

BOOL CMy05HtmlViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

void CMy05HtmlViewTestView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	/*Navigate2(_T("http://www.msdn.microsoft.com/visualc/"),nullptr, nullptr);*/
	m_pBrowserApp->put_Silent(VARIANT_TRUE);	// 스크립트 오류 표시 끄기
	Navigate(_T("https://www.hankyung.com/"));
}


// CMy05HtmlViewTestView printing



// CMy05HtmlViewTestView diagnostics

#ifdef _DEBUG
void CMy05HtmlViewTestView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMy05HtmlViewTestView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CMy05HtmlViewTestDoc* CMy05HtmlViewTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy05HtmlViewTestDoc)));
	return (CMy05HtmlViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy05HtmlViewTestView message handlers
