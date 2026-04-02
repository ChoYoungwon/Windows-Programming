
// 03_UIThreadView.h : interface of the CMy03UIThreadView class
//

#pragma once


class CMy03UIThreadView : public CView
{
protected: // create from serialization only
	CMy03UIThreadView() noexcept;
	DECLARE_DYNCREATE(CMy03UIThreadView)

// Attributes
public:
	CMy03UIThreadDoc* GetDocument() const;

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
	virtual ~CMy03UIThreadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in 03_UIThreadView.cpp
inline CMy03UIThreadDoc* CMy03UIThreadView::GetDocument() const
   { return reinterpret_cast<CMy03UIThreadDoc*>(m_pDocument); }
#endif

