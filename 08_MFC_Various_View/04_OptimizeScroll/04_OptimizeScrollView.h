
// 04_OptimizeScrollView.h : interface of the CMy04OptimizeScrollView class
//

#pragma once


class CMy04OptimizeScrollView : public CScrollView
{
protected: // create from serialization only
	CMy04OptimizeScrollView() noexcept;
	DECLARE_DYNCREATE(CMy04OptimizeScrollView)

// Attributes
public:
	CMy04OptimizeScrollDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy04OptimizeScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void MyDraw(CDC* pDC, int x, int y);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // debug version in 04_OptimizeScrollView.cpp
inline CMy04OptimizeScrollDoc* CMy04OptimizeScrollView::GetDocument() const
   { return reinterpret_cast<CMy04OptimizeScrollDoc*>(m_pDocument); }
#endif

