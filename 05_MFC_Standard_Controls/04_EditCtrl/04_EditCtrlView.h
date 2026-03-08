
// 04_EditCtrlView.h : interface of the CMy04EditCtrlView class
//

#pragma once


class CMy04EditCtrlView : public CFormView
{
protected: // create from serialization only
	CMy04EditCtrlView() noexcept;
	DECLARE_DYNCREATE(CMy04EditCtrlView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY04_EDITCTRL_FORM };
#endif

// Attributes
public:
	CMy04EditCtrlDoc* GetDocument() const;

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
	virtual ~CMy04EditCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CStatic m_static;
	afx_msg void OnEnMaxtextMyedit();
	afx_msg void OnEnChangeMyedit();
};

#ifndef _DEBUG  // debug version in 04_EditCtrlView.cpp
inline CMy04EditCtrlDoc* CMy04EditCtrlView::GetDocument() const
   { return reinterpret_cast<CMy04EditCtrlDoc*>(m_pDocument); }
#endif

