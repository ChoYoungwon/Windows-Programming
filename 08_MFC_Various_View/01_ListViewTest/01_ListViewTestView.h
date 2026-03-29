
// 01_ListViewTestView.h : interface of the CMy01ListViewTestView class
//

#pragma once


class CMy01ListViewTestView : public CListView
{
protected: // create from serialization only
	CMy01ListViewTestView() noexcept;
	DECLARE_DYNCREATE(CMy01ListViewTestView)

// Attributes
public:
	CMy01ListViewTestDoc* GetDocument() const;

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
	virtual ~CMy01ListViewTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnViewLargeicon();
	afx_msg void OnViewSmallicon();
	afx_msg void OnViewList();
	afx_msg void OnViewDetails();
};

#ifndef _DEBUG  // debug version in 01_ListViewTestView.cpp
inline CMy01ListViewTestDoc* CMy01ListViewTestView::GetDocument() const
   { return reinterpret_cast<CMy01ListViewTestDoc*>(m_pDocument); }
#endif

