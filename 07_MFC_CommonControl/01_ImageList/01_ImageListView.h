
// 01_ImageListView.h : interface of the CMy01ImageListView class
//

#pragma once


class CMy01ImageListView : public CView
{
protected: // create from serialization only
	CMy01ImageListView() noexcept;
	DECLARE_DYNCREATE(CMy01ImageListView)

// Attributes
public:
	CMy01ImageListDoc* GetDocument() const;
	CImageList m_il;

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
	virtual ~CMy01ImageListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // debug version in 01_ImageListView.cpp
inline CMy01ImageListDoc* CMy01ImageListView::GetDocument() const
   { return reinterpret_cast<CMy01ImageListDoc*>(m_pDocument); }
#endif

