
// 01_SplitterView.h : interface of the CMy01SplitterView class
//

#pragma once


class CMy01SplitterView : public CView
{
protected: // create from serialization only
	CMy01SplitterView() noexcept;
	DECLARE_DYNCREATE(CMy01SplitterView)

// Attributes
public:
	CMy01SplitterDoc* GetDocument() const;

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
	virtual ~CMy01SplitterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in 01_SplitterView.cpp
inline CMy01SplitterDoc* CMy01SplitterView::GetDocument() const
   { return reinterpret_cast<CMy01SplitterDoc*>(m_pDocument); }
#endif

