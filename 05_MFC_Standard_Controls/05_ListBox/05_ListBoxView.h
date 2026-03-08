
// 05_ListBoxView.h : interface of the CMy05ListBoxView class
//

#pragma once


class CMy05ListBoxView : public CFormView
{
protected: // create from serialization only
	CMy05ListBoxView() noexcept;
	DECLARE_DYNCREATE(CMy05ListBoxView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY05_LISTBOX_FORM };
#endif

// Attributes
public:
	CMy05ListBoxDoc* GetDocument() const;

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
	virtual ~CMy05ListBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list1;
	CListBox m_list2;
	CButton m_right;
	CButton m_left;
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedLeft();
};

#ifndef _DEBUG  // debug version in 05_ListBoxView.cpp
inline CMy05ListBoxDoc* CMy05ListBoxView::GetDocument() const
   { return reinterpret_cast<CMy05ListBoxDoc*>(m_pDocument); }
#endif

