
// 01_FileIOTestView.h : interface of the CMy01FileIOTestView class
//

#pragma once


class CMy01FileIOTestView : public CView
{
protected: // create from serialization only
	CMy01FileIOTestView() noexcept;
	DECLARE_DYNCREATE(CMy01FileIOTestView)

// Attributes
public:
	CMy01FileIOTestDoc* GetDocument() const;

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
	virtual ~CMy01FileIOTestView();
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
};

#ifndef _DEBUG  // debug version in 01_FileIOTestView.cpp
inline CMy01FileIOTestDoc* CMy01FileIOTestView::GetDocument() const
   { return reinterpret_cast<CMy01FileIOTestDoc*>(m_pDocument); }
#endif

