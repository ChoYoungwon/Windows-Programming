
// 03_TCPServer2View.h : interface of the CMy03TCPServer2View class
//

#pragma once


class CMy03TCPServer2View : public CEditView
{
protected: // create from serialization only
	CMy03TCPServer2View() noexcept;
	DECLARE_DYNCREATE(CMy03TCPServer2View)

// Attributes
public:
	CMy03TCPServer2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy03TCPServer2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	void AddMessage(LPCTSTR message);
};

#ifndef _DEBUG  // debug version in 03_TCPServer2View.cpp
inline CMy03TCPServer2Doc* CMy03TCPServer2View::GetDocument() const
   { return reinterpret_cast<CMy03TCPServer2Doc*>(m_pDocument); }
#endif

