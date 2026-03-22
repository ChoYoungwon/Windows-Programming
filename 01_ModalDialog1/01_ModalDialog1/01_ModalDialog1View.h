
// 01_ModalDialog1View.h : interface of the CMy01ModalDialog1View class
//

#pragma once


class CMy01ModalDialog1View : public CView
{
protected: // create from serialization only
	CMy01ModalDialog1View() noexcept;
	DECLARE_DYNCREATE(CMy01ModalDialog1View)

// Attributes
public:
	CMy01ModalDialog1Doc* GetDocument() const;

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
	virtual ~CMy01ModalDialog1View();
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

#ifndef _DEBUG  // debug version in 01_ModalDialog1View.cpp
inline CMy01ModalDialog1Doc* CMy01ModalDialog1View::GetDocument() const
   { return reinterpret_cast<CMy01ModalDialog1Doc*>(m_pDocument); }
#endif

