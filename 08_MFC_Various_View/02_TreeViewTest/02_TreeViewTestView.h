
// 02_TreeViewTestView.h : interface of the CMy02TreeViewTestView class
//

#pragma once


class CMy02TreeViewTestView : public CTreeView
{
protected: // create from serialization only
	CMy02TreeViewTestView() noexcept;
	DECLARE_DYNCREATE(CMy02TreeViewTestView)

// Attributes
public:
	CMy02TreeViewTestDoc* GetDocument() const;

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
	virtual ~CMy02TreeViewTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestDeleteselected();
	afx_msg void OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
};

#ifndef _DEBUG  // debug version in 02_TreeViewTestView.cpp
inline CMy02TreeViewTestDoc* CMy02TreeViewTestView::GetDocument() const
   { return reinterpret_cast<CMy02TreeViewTestDoc*>(m_pDocument); }
#endif

