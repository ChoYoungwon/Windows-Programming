
// 06_ScrollBarView.cpp : implementation of the CMy06ScrollBarView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "06_ScrollBar.h"
#endif

#include "06_ScrollBarDoc.h"
#include "06_ScrollBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy06ScrollBarView

IMPLEMENT_DYNCREATE(CMy06ScrollBarView, CFormView)

BEGIN_MESSAGE_MAP(CMy06ScrollBarView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &CMy06ScrollBarView::OnNMThemeChangedScrollbar1)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR2, &CMy06ScrollBarView::OnNMThemeChangedScrollbar2)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()

// CMy06ScrollBarView construction/destruction

CMy06ScrollBarView::CMy06ScrollBarView() noexcept
	: CFormView(IDD_MY06_SCROLLBAR_FORM)
{
	// TODO: add construction code here

}

CMy06ScrollBarView::~CMy06ScrollBarView()
{
}

void CMy06ScrollBarView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATUS, m_status);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_hsb);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_vsb);
}

BOOL CMy06ScrollBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy06ScrollBarView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_hsb.SetScrollRange(0, 360, FALSE);		// 0~360 범위 설정
	m_hsb.SetScrollPos(0);
	m_vsb.SetScrollRange(0, 255, FALSE);		// 0~255 범위 설정
	m_vsb.SetScrollPos(128);
}


// CMy06ScrollBarView printing

BOOL CMy06ScrollBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy06ScrollBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy06ScrollBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy06ScrollBarView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy06ScrollBarView diagnostics

#ifdef _DEBUG
void CMy06ScrollBarView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy06ScrollBarView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy06ScrollBarDoc* CMy06ScrollBarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy06ScrollBarDoc)));
	return (CMy06ScrollBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy06ScrollBarView message handlers

void CMy06ScrollBarView::OnNMThemeChangedScrollbar1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// This feature requires Windows XP or greater.
	// The symbol _WIN32_WINNT must be >= 0x0501.
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CMy06ScrollBarView::OnNMThemeChangedScrollbar2(NMHDR* pNMHDR, LRESULT* pResult)
{
	// This feature requires Windows XP or greater.
	// The symbol _WIN32_WINNT must be >= 0x0501.
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CMy06ScrollBarView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	if (pScrollBar != NULL) {	// 스크롤바 컨트롤에서 발생한 메시지이면
		if (pScrollBar->GetSafeHwnd() == m_hsb.GetSafeHwnd()) {
			switch (nSBCode) {
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			}
			Invalidate();
		}
	}
	else	// 윈도우 스크롤바에서 발생한 메시지이면
		CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMy06ScrollBarView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int pos;
	int delta = 0;

	if (pScrollBar != NULL) {	// 스크롤바 컨트롤에서 발생한 메시지이면
		if (pScrollBar->GetSafeHwnd() == m_vsb.GetSafeHwnd()) {
			switch (nSBCode) {
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			case SB_LINEUP:
				delta = -4;
				break;
			case SB_LINEDOWN:
				delta = 4;
				break;
			case SB_PAGEUP:
				delta = -20;
				break;
			case SB_PAGEDOWN:
				delta = 20;
				break;
			}
			if (delta != 0) {
				pos = pScrollBar->GetScrollPos();
				pScrollBar->SetScrollPos(pos + delta);
			}
			Invalidate();
		}
	}
	else	// 윈도우 스크롤바에서 발생한 메시지이면
		CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CMy06ScrollBarView::OnDraw(CDC* pDC)
{
	// 스크롤바의 현재 위치를 얻는다.
	int hpos = m_hsb.GetScrollPos();
	int vpos = m_vsb.GetScrollPos();

	CFont font;
	LOGFONT lf = { 0 };				// 구조체를 0으로 초기화한다.
	lf.lfHeight = vpos / 3 + 1;		// 폰트 크기를 설정한다. vpos==0이면 크기는 1이다.
	lf.lfEscapement = 10 * hpos;	// 폰트 회전각을 설정한다.
	font.CreateFontIndirectW(&lf);	// 폰트를 생성한다.
	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(0, vpos, 0));					// 폰트 색상을 설정한다.
	pDC->TextOut(50, 100, CString(_T("안녕하세요")));

	CString str;
	str.Format(_T("글자 크기: %d, 회전각: %d, 초록색 농도: %d"), lf.lfHeight, hpos, vpos);
	m_status.SetWindowTextW(str);	// 스태틱 텍스트 컨트롤에 출력한다.
}
