
// 02_MDITestView.h : interface of the CMy02MDITestView class
//

#pragma once


class CMy02MDITestView : public CView
{
protected: // create from serialization only
	CMy02MDITestView() noexcept;
	DECLARE_DYNCREATE(CMy02MDITestView)

// Attributes
public:
	CMy02MDITestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy02MDITestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in 02_MDITestView.cpp
inline CMy02MDITestDoc* CMy02MDITestView::GetDocument() const
   { return reinterpret_cast<CMy02MDITestDoc*>(m_pDocument); }
#endif

