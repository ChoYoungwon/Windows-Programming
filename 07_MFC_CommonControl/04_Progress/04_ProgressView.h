
// 04_ProgressView.h : interface of the CMy04ProgressView class
//

#pragma once


class CMy04ProgressView : public CFormView
{
protected: // create from serialization only
	CMy04ProgressView() noexcept;
	DECLARE_DYNCREATE(CMy04ProgressView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY04_PROGRESS_FORM };
#endif

// Attributes
public:
	CMy04ProgressDoc* GetDocument() const;
	BOOL bNowProgress;

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
	virtual ~CMy04ProgressView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_progress;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // debug version in 04_ProgressView.cpp
inline CMy04ProgressDoc* CMy04ProgressView::GetDocument() const
   { return reinterpret_cast<CMy04ProgressDoc*>(m_pDocument); }
#endif

