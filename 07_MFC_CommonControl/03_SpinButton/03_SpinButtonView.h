
// 03_SpinButtonView.h : interface of the CMy03SpinButtonView class
//

#pragma once


class CMy03SpinButtonView : public CFormView
{
protected: // create from serialization only
	CMy03SpinButtonView() noexcept;
	DECLARE_DYNCREATE(CMy03SpinButtonView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY03_SPINBUTTON_FORM };
#endif

// Attributes
public:
	CMy03SpinButtonDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy03SpinButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_spin;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};

#ifndef _DEBUG  // debug version in 03_SpinButtonView.cpp
inline CMy03SpinButtonDoc* CMy03SpinButtonView::GetDocument() const
   { return reinterpret_cast<CMy03SpinButtonDoc*>(m_pDocument); }
#endif

