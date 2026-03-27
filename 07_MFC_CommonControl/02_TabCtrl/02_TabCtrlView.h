
// 02_TabCtrlView.h : interface of the CMy02TabCtrlView class
//

#pragma once


class CMy02TabCtrlView : public CFormView
{
protected: // create from serialization only
	CMy02TabCtrlView() noexcept;
	DECLARE_DYNCREATE(CMy02TabCtrlView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY02_TABCTRL_FORM };
#endif

// Attributes
public:
	CMy02TabCtrlDoc* GetDocument() const;

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
	virtual ~CMy02TabCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CEdit m_edit;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};

#ifndef _DEBUG  // debug version in 02_TabCtrlView.cpp
inline CMy02TabCtrlDoc* CMy02TabCtrlView::GetDocument() const
   { return reinterpret_cast<CMy02TabCtrlDoc*>(m_pDocument); }
#endif

