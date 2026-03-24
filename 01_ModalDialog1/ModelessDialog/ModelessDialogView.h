
// ModelessDialogView.h : interface of the CModelessDialogView class
//

#pragma once

class CMyDialog;

class CModelessDialogView : public CFormView
{
protected: // create from serialization only
	CModelessDialogView() noexcept;
	DECLARE_DYNCREATE(CModelessDialogView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MODELESSDIALOG_FORM };
#endif

// Attributes
public:
	CModelessDialogDoc* GetDocument() const;
	CMyDialog* m_pDlg;	// 대화 상자 객체의 주소 저장
	CString m_str;
	int m_font;

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
	virtual ~CModelessDialogView();
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
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // debug version in ModelessDialogView.cpp
inline CModelessDialogDoc* CModelessDialogView::GetDocument() const
   { return reinterpret_cast<CModelessDialogDoc*>(m_pDocument); }
#endif

