// CKeyInputView.cpp : implementation file
//

#include "pch.h"
#include "01_Splitter.h"
#include "CKeyInputView.h"
#include "01_SplitterDoc.h"

// CKeyInputView

IMPLEMENT_DYNCREATE(CKeyInputView, CView)

CKeyInputView::CKeyInputView()
{

}

CKeyInputView::~CKeyInputView()
{
}

BEGIN_MESSAGE_MAP(CKeyInputView, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()


// CKeyInputView drawing

void CKeyInputView::OnDraw(CDC* pDC)
{	
	// TODO: add draw code here
	CMy01SplitterDoc* pDoc = (CMy01SplitterDoc*)GetDocument();

	// 화면 출력용 폰트를 선택한다.
	CFont font;
	font.CreatePointFont(150, _T("궁서"));
	pDC->SelectObject(&font);

	// 현재까지 입력된 글자들을 화면에 출력한다.
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(pDoc->m_str.GetData(),
		pDoc->m_str.GetSize(), &rect, DT_LEFT);
}


// CKeyInputView diagnostics

#ifdef _DEBUG
void CKeyInputView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CKeyInputView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CKeyInputView message handlers

void CKeyInputView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CMy01SplitterDoc* pDoc = (CMy01SplitterDoc*)GetDocument();

	// [Backspace] 입력 시 맨 마지막 글자를 삭제한다.
	if (nChar == _T('\b')) {
		if (pDoc->m_str.GetSize() > 0)
			pDoc->m_str.RemoveAt(pDoc->m_str.GetSize() - 1);
	}
	// 그 밖의 경우에는 동적 배열에 글자를 추가한다.
	else {
		pDoc->m_str.Add(nChar);
	}

	// 화면을 갱신한다.
	Invalidate();


	CView::OnChar(nChar, nRepCnt, nFlags);
}
