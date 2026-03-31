
// 05_HtmlViewTestView.h : interface of the CMy05HtmlViewTestView class
//

#pragma once


class CMy05HtmlViewTestView : public CHtmlView
{
protected: // create from serialization only
	CMy05HtmlViewTestView() noexcept;
	DECLARE_DYNCREATE(CMy05HtmlViewTestView)

// Attributes
public:
	CMy05HtmlViewTestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CMy05HtmlViewTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 05_HtmlViewTestView.cpp
inline CMy05HtmlViewTestDoc* CMy05HtmlViewTestView::GetDocument() const
   { return reinterpret_cast<CMy05HtmlViewTestDoc*>(m_pDocument); }
#endif

