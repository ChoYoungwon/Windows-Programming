
// 07_SubclassView.h : interface of the CMy07SubclassView class
//

#pragma once
#include "CMyEdit.h"

class CMy07SubclassView : public CFormView
{
protected: // create from serialization only
	CMy07SubclassView() noexcept;
	DECLARE_DYNCREATE(CMy07SubclassView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY07_SUBCLASS_FORM };
#endif

// Attributes
public:
	CMy07SubclassDoc* GetDocument() const;
	CMyEdit m_edit2;

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
	virtual ~CMy07SubclassView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CMyEdit m_edit1;
};

#ifndef _DEBUG  // debug version in 07_SubclassView.cpp
inline CMy07SubclassDoc* CMy07SubclassView::GetDocument() const
   { return reinterpret_cast<CMy07SubclassDoc*>(m_pDocument); }
#endif

