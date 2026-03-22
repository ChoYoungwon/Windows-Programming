
// 02_ModalDialog2View.h : interface of the CMy02ModalDialog2View class
//

#pragma once


class CMy02ModalDialog2View : public CFormView
{
protected: // create from serialization only
	CMy02ModalDialog2View() noexcept;
	DECLARE_DYNCREATE(CMy02ModalDialog2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY02_MODALDIALOG2_FORM };
#endif

// Attributes
public:
	CMy02ModalDialog2Doc* GetDocument() const;
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
	virtual ~CMy02ModalDialog2View();
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

#ifndef _DEBUG  // debug version in 02_ModalDialog2View.cpp
inline CMy02ModalDialog2Doc* CMy02ModalDialog2View::GetDocument() const
   { return reinterpret_cast<CMy02ModalDialog2Doc*>(m_pDocument); }
#endif

