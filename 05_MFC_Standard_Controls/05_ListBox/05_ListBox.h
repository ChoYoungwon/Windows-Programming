
// 05_ListBox.h : main header file for the 05_ListBox application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy05ListBoxApp:
// See 05_ListBox.cpp for the implementation of this class
//

class CMy05ListBoxApp : public CWinApp
{
public:
	CMy05ListBoxApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy05ListBoxApp theApp;
