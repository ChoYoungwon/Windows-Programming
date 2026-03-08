
// 06_ScrollBar.h : main header file for the 06_ScrollBar application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy06ScrollBarApp:
// See 06_ScrollBar.cpp for the implementation of this class
//

class CMy06ScrollBarApp : public CWinApp
{
public:
	CMy06ScrollBarApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy06ScrollBarApp theApp;
