#pragma once
#include <afxtempl.h>

// CMyWnd frame

class CMyWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CMyWnd)
protected:
	CMyWnd();           // protected constructor used by dynamic creation
	virtual ~CMyWnd();
	CArray<TCHAR, TCHAR> m_str;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
};


