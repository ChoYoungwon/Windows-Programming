
// 03_ScrollViewTestView.h : interface of the CMy03ScrollViewTestView class
//

#pragma once


class CMy03ScrollViewTestView : public CScrollView
{
protected: // create from serialization only
	CMy03ScrollViewTestView() noexcept;
	DECLARE_DYNCREATE(CMy03ScrollViewTestView)

// Attributes
public:
	CMy03ScrollViewTestDoc* GetDocument() const;

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
	virtual ~CMy03ScrollViewTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 03_ScrollViewTestView.cpp
inline CMy03ScrollViewTestDoc* CMy03ScrollViewTestView::GetDocument() const
   { return reinterpret_cast<CMy03ScrollViewTestDoc*>(m_pDocument); }
#endif

