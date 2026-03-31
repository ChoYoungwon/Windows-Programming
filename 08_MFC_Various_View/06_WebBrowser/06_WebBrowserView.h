
// 06_WebBrowserView.h : interface of the CMy06WebBrowserView class
//

#pragma once


class CMy06WebBrowserView : public CHtmlView
{
protected: // create from serialization only
	CMy06WebBrowserView() noexcept;
	DECLARE_DYNCREATE(CMy06WebBrowserView)

// Attributes
public:
	CMy06WebBrowserDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CMy06WebBrowserView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnWebsearchOpen();
	afx_msg void OnWebsearchBack();
	afx_msg void OnWebsearchForward();
};

#ifndef _DEBUG  // debug version in 06_WebBrowserView.cpp
inline CMy06WebBrowserDoc* CMy06WebBrowserView::GetDocument() const
   { return reinterpret_cast<CMy06WebBrowserDoc*>(m_pDocument); }
#endif

