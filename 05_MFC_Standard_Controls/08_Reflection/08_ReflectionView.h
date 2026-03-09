
// 08_ReflectionView.h : interface of the CMy08ReflectionView class
//

#pragma once
#include "CMyListBox.h"

class CMy08ReflectionView : public CFormView
{
protected: // create from serialization only
	CMy08ReflectionView() noexcept;
	DECLARE_DYNCREATE(CMy08ReflectionView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY08_REFLECTION_FORM };
#endif

// Attributes
public:
	CMy08ReflectionDoc* GetDocument() const;

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
	virtual ~CMy08ReflectionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CMyListBox m_list;
};

#ifndef _DEBUG  // debug version in 08_ReflectionView.cpp
inline CMy08ReflectionDoc* CMy08ReflectionView::GetDocument() const
   { return reinterpret_cast<CMy08ReflectionDoc*>(m_pDocument); }
#endif

