
// 01_WorkerThread1View.h : interface of the CMy01WorkerThread1View class
//

#pragma once


class CMy01WorkerThread1View : public CView
{
protected: // create from serialization only
	CMy01WorkerThread1View() noexcept;
	DECLARE_DYNCREATE(CMy01WorkerThread1View)

// Attributes
public:
	CMy01WorkerThread1Doc* GetDocument() const;

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
	virtual ~CMy01WorkerThread1View();
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

#ifndef _DEBUG  // debug version in 01_WorkerThread1View.cpp
inline CMy01WorkerThread1Doc* CMy01WorkerThread1View::GetDocument() const
   { return reinterpret_cast<CMy01WorkerThread1Doc*>(m_pDocument); }
#endif

