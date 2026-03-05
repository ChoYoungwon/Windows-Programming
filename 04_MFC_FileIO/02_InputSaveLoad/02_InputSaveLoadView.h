
// 02_InputSaveLoadView.h : interface of the CMy02InputSaveLoadView class
//

#pragma once


class CMy02InputSaveLoadView : public CView
{
protected: // create from serialization only
	CMy02InputSaveLoadView() noexcept;
	DECLARE_DYNCREATE(CMy02InputSaveLoadView)

// Attributes
public:
	CMy02InputSaveLoadDoc* GetDocument() const;

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
	virtual ~CMy02InputSaveLoadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in 02_InputSaveLoadView.cpp
inline CMy02InputSaveLoadDoc* CMy02InputSaveLoadView::GetDocument() const
   { return reinterpret_cast<CMy02InputSaveLoadDoc*>(m_pDocument); }
#endif

