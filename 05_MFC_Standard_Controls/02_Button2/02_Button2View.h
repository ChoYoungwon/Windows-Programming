
// 02_Button2View.h : interface of the CMy02Button2View class
//

#pragma once


class CMy02Button2View : public CFormView
{
protected: // create from serialization only
	CMy02Button2View() noexcept;
	DECLARE_DYNCREATE(CMy02Button2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY02_BUTTON2_FORM };
#endif

// Attributes
public:
	CMy02Button2Doc* GetDocument() const;

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
	virtual ~CMy02Button2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_checkbox;
	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // debug version in 02_Button2View.cpp
inline CMy02Button2Doc* CMy02Button2View::GetDocument() const
   { return reinterpret_cast<CMy02Button2Doc*>(m_pDocument); }
#endif

