
// 01_ListViewTestView.cpp : implementation of the CMy01ListViewTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "01_ListViewTest.h"
#endif

#include "01_ListViewTestDoc.h"
#include "01_ListViewTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01ListViewTestView

IMPLEMENT_DYNCREATE(CMy01ListViewTestView, CListView)

BEGIN_MESSAGE_MAP(CMy01ListViewTestView, CListView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CListView::OnFilePrintPreview)
	ON_COMMAND(ID_VIEW_LARGEICON, &CMy01ListViewTestView::OnViewLargeicon)
	ON_COMMAND(ID_VIEW_SMALLICON, &CMy01ListViewTestView::OnViewSmallicon)
	ON_COMMAND(ID_VIEW_LIST, &CMy01ListViewTestView::OnViewList)
	ON_COMMAND(ID_VIEW_DETAILS, &CMy01ListViewTestView::OnViewDetails)
END_MESSAGE_MAP()

// CMy01ListViewTestView construction/destruction

CMy01ListViewTestView::CMy01ListViewTestView() noexcept
{
	// TODO: add construction code here

}

CMy01ListViewTestView::~CMy01ListViewTestView()
{
}

BOOL CMy01ListViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style &= ~LVS_TYPEMASK;		// 네 개의 보기 스타일을 모두 제거한다.
	cs.dwExStyle |= LVS_REPORT;		// 보고서 보기 스타일을 추가한다.

	return CListView::PreCreateWindow(cs);
}


void CMy01ListViewTestView::OnDraw(CDC* /*pDC*/)
{
	CMy01ListViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


void CMy01ListViewTestView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// 이미지 리스트 생성과 초기화
	CImageList ilLarge, ilSmall;
	ilLarge.Create(32, 32, ILC_COLOR4, 1, 1);
	ilSmall.Create(16, 16, ILC_COLOR4, 1, 1);
	ilLarge.Add(AfxGetApp()->LoadIconW(IDI_ICON1));
	ilSmall.Add(AfxGetApp()->LoadIconW(IDI_ICON1));

	// 이미지 리스트 설정
	CListCtrl& list = GetListCtrl();
	list.SetImageList(&ilLarge, LVSIL_NORMAL);
	list.SetImageList(&ilSmall, LVSIL_SMALL);
	ilLarge.Detach();
	ilSmall.Detach();

	// 헤더 초기화
	list.InsertColumn(0, _T("상품명"), LVCFMT_LEFT, 100, 0);
	list.InsertColumn(0, _T("가격"), LVCFMT_LEFT, 100, 2);
	list.InsertColumn(0, _T("수량"), LVCFMT_LEFT, 100, 1);

	CMy01ListViewTestDoc* pDoc = GetDocument();
	CString str;
	for (int i = 0; i < NUMITEM; i++) {
		// 항목 추가
		list.InsertItem(i, pDoc->m_item[i].name, 0);
		// 하위 항목 추가
		str.Format(_T("%d"), pDoc->m_item[i].price);
		list.SetItemText(i, 1, str);
		str.Format(_T("%d"), pDoc->m_item[i].quantity);
		list.SetItemText(i, 2, str);
	}
}


// CMy01ListViewTestView printing

BOOL CMy01ListViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy01ListViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy01ListViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy01ListViewTestView diagnostics

#ifdef _DEBUG
void CMy01ListViewTestView::AssertValid() const
{
	CListView::AssertValid();
}

void CMy01ListViewTestView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CMy01ListViewTestDoc* CMy01ListViewTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy01ListViewTestDoc)));
	return (CMy01ListViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy01ListViewTestView message handlers

void CMy01ListViewTestView::OnViewLargeicon()
{
	ModifyStyle(LVS_TYPEMASK, LVS_ICON);
}

void CMy01ListViewTestView::OnViewSmallicon()
{
	ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
}

void CMy01ListViewTestView::OnViewList()
{
	ModifyStyle(LVS_TYPEMASK, LVS_LIST);
}

void CMy01ListViewTestView::OnViewDetails()
{
	ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
}
