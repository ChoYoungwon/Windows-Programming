
// 02_MDITestView.cpp : implementation of the CMy02MDITestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_MDITest.h"
#endif

#include "02_MDITestDoc.h"
#include "02_MDITestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02MDITestView

IMPLEMENT_DYNCREATE(CMy02MDITestView, CView)

BEGIN_MESSAGE_MAP(CMy02MDITestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy02MDITestView construction/destruction

CMy02MDITestView::CMy02MDITestView() noexcept
{
	// TODO: add construction code here

}

CMy02MDITestView::~CMy02MDITestView()
{
}

BOOL CMy02MDITestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy02MDITestView drawing

void CMy02MDITestView::OnDraw(CDC* pDC)
{
	CMy02MDITestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 화면 출력용 폰트를 선택한다.
	CFont font;
	font.CreateFont(30, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, _T("궁서"));

	pDC->SelectObject(&font);

	// 현재까지 입력된 글자를 화면에 출력한다.
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(pDoc->m_str.GetData(),
		pDoc->m_str.GetSize(), &rect, DT_LEFT);
}


// CMy02MDITestView printing

BOOL CMy02MDITestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy02MDITestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy02MDITestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy02MDITestView diagnostics

#ifdef _DEBUG
void CMy02MDITestView::AssertValid() const
{
	CView::AssertValid();
}

void CMy02MDITestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02MDITestDoc* CMy02MDITestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02MDITestDoc)));
	return (CMy02MDITestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy02MDITestView message handlers

void CMy02MDITestView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CMy02MDITestDoc* pDoc = GetDocument();

	// [Backspace] 입력 시 맨 마지막 글자를 삭제한다.
	if (nChar == _T('\b')) {
		if (pDoc->m_str.GetSize() > 0)
			pDoc->m_str.RemoveAt(pDoc->m_str.GetSize() - 1);
	}
	// 그 밖의 경우에는 동적 배열에 글자를 추가한다.
	else {
		pDoc->m_str.Add(nChar);
	}

	// 데이터가 수정되었음을 알린다.
	pDoc->SetModifiedFlag();

	// 화면을 갱신한다.
	pDoc->UpdateAllViews(NULL);
}
