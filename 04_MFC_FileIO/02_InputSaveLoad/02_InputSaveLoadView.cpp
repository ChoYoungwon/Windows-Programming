
// 02_InputSaveLoadView.cpp : implementation of the CMy02InputSaveLoadView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_InputSaveLoad.h"
#endif

#include "02_InputSaveLoadDoc.h"
#include "02_InputSaveLoadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02InputSaveLoadView

IMPLEMENT_DYNCREATE(CMy02InputSaveLoadView, CView)

BEGIN_MESSAGE_MAP(CMy02InputSaveLoadView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy02InputSaveLoadView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy02InputSaveLoadView construction/destruction

CMy02InputSaveLoadView::CMy02InputSaveLoadView() noexcept
{
	// TODO: add construction code here

}

CMy02InputSaveLoadView::~CMy02InputSaveLoadView()
{
}

BOOL CMy02InputSaveLoadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy02InputSaveLoadView drawing

void CMy02InputSaveLoadView::OnDraw(CDC* pDC)
{
	CMy02InputSaveLoadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 화면 출력용 폰트를 선택한다.
	CFont font;
	font.CreateFont(30, 0, 0, 0, 0, pDoc->m_bItalic, pDoc->m_bUnderline, 0, 0, 0, 0, 0, 0, _T("궁서"));
	pDC->SelectObject(&font);

	// 현재까지 입력된 글자를 화면에 출력한다.
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(pDoc->m_str.GetData(), 
		pDoc->m_str.GetSize(), &rect, DT_LEFT);
}


// CMy02InputSaveLoadView printing


void CMy02InputSaveLoadView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy02InputSaveLoadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy02InputSaveLoadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy02InputSaveLoadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy02InputSaveLoadView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy02InputSaveLoadView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy02InputSaveLoadView diagnostics

#ifdef _DEBUG
void CMy02InputSaveLoadView::AssertValid() const
{
	CView::AssertValid();
}

void CMy02InputSaveLoadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02InputSaveLoadDoc* CMy02InputSaveLoadView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02InputSaveLoadDoc)));
	return (CMy02InputSaveLoadDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy02InputSaveLoadView message handlers

void CMy02InputSaveLoadView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CMy02InputSaveLoadDoc* pDoc = GetDocument();

	// [Backspace] 입력 시 맨 마지막 글자를 삭제한다.
	if (nChar == _T('\b')) {
		if (pDoc->m_str.GetSize() > 0)
			pDoc->m_str.RemoveAt(pDoc->m_str.GetSize() - 1);
	}
	// 그 밖의 경우에는 동적 배열에 글자를 추가한다.
	else {
		pDoc->m_str.Add(nChar);
	}

	// 데이터가 수정되었음을 도큐먼트 객체에 알린다.
	pDoc->SetModifiedFlag();

	// 뷰의 화면을 갱신한다.
	Invalidate();
}
