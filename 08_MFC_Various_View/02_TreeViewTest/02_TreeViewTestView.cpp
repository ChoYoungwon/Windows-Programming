
// 02_TreeViewTestView.cpp : implementation of the CMy02TreeViewTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "02_TreeViewTest.h"
#endif

#include "02_TreeViewTestDoc.h"
#include "02_TreeViewTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02TreeViewTestView

IMPLEMENT_DYNCREATE(CMy02TreeViewTestView, CTreeView)

BEGIN_MESSAGE_MAP(CMy02TreeViewTestView, CTreeView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTreeView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST_DELETESELECTED, &CMy02TreeViewTestView::OnTestDeleteselected)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CMy02TreeViewTestView::OnTvnSelchanged)
END_MESSAGE_MAP()

// CMy02TreeViewTestView construction/destruction

CMy02TreeViewTestView::CMy02TreeViewTestView() noexcept
{
	// TODO: add construction code here

}

CMy02TreeViewTestView::~CMy02TreeViewTestView()
{
}

BOOL CMy02TreeViewTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= TVS_HASBUTTONS;
	cs.style |= TVS_HASLINES;
	cs.style |= TVS_LINESATROOT;
	cs.style |= TVS_TRACKSELECT;

	return CTreeView::PreCreateWindow(cs);
}


void CMy02TreeViewTestView::OnDraw(CDC* /*pDC*/)
{
	CMy02TreeViewTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


void CMy02TreeViewTestView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// 이미지 리스트 생성과 초기화
	CImageList il;
	il.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));

	// 이미지 리스트 설정
	CTreeCtrl& tree = GetTreeCtrl();
	tree.SetImageList(&il, TVSIL_NORMAL);
	il.Detach();

	// 항목 추가
	/* 1st 레벨 초기화 */
	HTREEITEM hSun = tree.InsertItem(_T("태양"), 0, 0, TVI_ROOT, TVI_LAST);

	/* 2st 레벨 초기화 */
	HTREEITEM hPlanet[8];
	CString planet[] = {
		_T("수성"), _T("금성"), _T("지구"), _T("화성"), _T("목성"),
		_T("토성"), _T("천왕성"), _T("해왕성")
	};
	for (int i = 0; i < 8; i++)
		hPlanet[i] = tree.InsertItem(planet[i], 1, 1, hSun, TVI_LAST);

	/* 3rd 레벨 초기화 */
	tree.InsertItem(_T("달"), 2, 2, hPlanet[2], TVI_LAST);
	tree.InsertItem(_T("포보스"), 2, 2, hPlanet[3], TVI_LAST);
	tree.InsertItem(_T("데이모스"), 2, 2, hPlanet[3], TVI_LAST);
	tree.InsertItem(_T("이오"), 2, 2, hPlanet[4], TVI_LAST);
	tree.InsertItem(_T("에우로파"), 2, 2, hPlanet[4], TVI_LAST);
	tree.InsertItem(_T("가니메데"), 2, 2, hPlanet[4], TVI_LAST);
	tree.InsertItem(_T("칼리스토"), 2, 2, hPlanet[4], TVI_LAST);
}


// CMy02TreeViewTestView printing

BOOL CMy02TreeViewTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy02TreeViewTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy02TreeViewTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMy02TreeViewTestView diagnostics

#ifdef _DEBUG
void CMy02TreeViewTestView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CMy02TreeViewTestView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CMy02TreeViewTestDoc* CMy02TreeViewTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02TreeViewTestDoc)));
	return (CMy02TreeViewTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy02TreeViewTestView message handlers

void CMy02TreeViewTestView::OnTestDeleteselected()
{
	CTreeCtrl& tree = GetTreeCtrl();
	HTREEITEM hItem = tree.GetSelectedItem();
	if (hItem != NULL) {
		tree.DeleteItem(hItem);
	}
}

void CMy02TreeViewTestView::OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	TVITEM tvi = pNMTreeView->itemNew;
	CTreeCtrl& tree = GetTreeCtrl();
	CString str = tree.GetItemText(tvi.hItem);
	AfxGetMainWnd()->SetWindowTextW(str);
	*pResult = 0;
}
