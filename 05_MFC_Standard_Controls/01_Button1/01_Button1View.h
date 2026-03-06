
// 01_Button1View.h : interface of the CMy01Button1View class
//

#pragma once


class CMy01Button1View : public CView
{
protected: // create from serialization only
	CMy01Button1View() noexcept;
	DECLARE_DYNCREATE(CMy01Button1View)

// Attributes
public:
	CMy01Button1Doc* GetDocument() const;
	CButton m_pushbutton;
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_groupbox;

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
	virtual ~CMy01Button1View();
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
	void OnButtonClicked();
};

#ifndef _DEBUG  // debug version in 01_Button1View.cpp
inline CMy01Button1Doc* CMy01Button1View::GetDocument() const
   { return reinterpret_cast<CMy01Button1Doc*>(m_pDocument); }
#endif

