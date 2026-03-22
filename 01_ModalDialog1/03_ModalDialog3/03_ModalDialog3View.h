
// 03_ModalDialog3View.h : interface of the CMy03ModalDialog3View class
//

#pragma once


class CMy03ModalDialog3View : public CFormView
{
protected: // create from serialization only
	CMy03ModalDialog3View() noexcept;
	DECLARE_DYNCREATE(CMy03ModalDialog3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY03_MODALDIALOG3_FORM };
#endif

// Attributes
public:
	CMy03ModalDialog3Doc* GetDocument() const;
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
	virtual ~CMy03ModalDialog3View();
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

#ifndef _DEBUG  // debug version in 03_ModalDialog3View.cpp
inline CMy03ModalDialog3Doc* CMy03ModalDialog3View::GetDocument() const
   { return reinterpret_cast<CMy03ModalDialog3Doc*>(m_pDocument); }
#endif

