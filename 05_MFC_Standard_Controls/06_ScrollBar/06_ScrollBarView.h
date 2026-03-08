
// 06_ScrollBarView.h : interface of the CMy06ScrollBarView class
//

#pragma once


class CMy06ScrollBarView : public CFormView
{
protected: // create from serialization only
	CMy06ScrollBarView() noexcept;
	DECLARE_DYNCREATE(CMy06ScrollBarView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY06_SCROLLBAR_FORM };
#endif

// Attributes
public:
	CMy06ScrollBarDoc* GetDocument() const;

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
	virtual ~CMy06ScrollBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMThemeChangedScrollbar2(NMHDR* pNMHDR, LRESULT* pResult);
	CStatic m_status;
	CScrollBar m_hsb;
	CScrollBar m_vsb;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // debug version in 06_ScrollBarView.cpp
inline CMy06ScrollBarDoc* CMy06ScrollBarView::GetDocument() const
   { return reinterpret_cast<CMy06ScrollBarDoc*>(m_pDocument); }
#endif

