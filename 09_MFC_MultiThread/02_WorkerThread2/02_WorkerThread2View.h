
// 02_WorkerThread2View.h : interface of the CMy02WorkerThread2View class
//

#pragma once
struct ThreadArg
{
	CWnd* pWnd;		// 출력할 대상 윈도우 객체의 주소이다.
	int pos;		// 1이면 위쪽에, 2이면 아래쪽에 출력한다.
};

class CMy02WorkerThread2View : public CView
{
protected: // create from serialization only
	CMy02WorkerThread2View() noexcept;
	DECLARE_DYNCREATE(CMy02WorkerThread2View)

// Attributes
public:
	CMy02WorkerThread2Doc* GetDocument() const;
	CWinThread* pThread1, * pThread2;		// 스레드 객체 주소
	ThreadArg arg1, arg2;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy02WorkerThread2View();
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
};

#ifndef _DEBUG  // debug version in 02_WorkerThread2View.cpp
inline CMy02WorkerThread2Doc* CMy02WorkerThread2View::GetDocument() const
   { return reinterpret_cast<CMy02WorkerThread2Doc*>(m_pDocument); }
#endif

