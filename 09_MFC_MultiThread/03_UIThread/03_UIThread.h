
// 03_UIThread.h : main header file for the 03_UIThread application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy03UIThreadApp:
// See 03_UIThread.cpp for the implementation of this class
//

class CMy03UIThreadApp : public CWinApp
{
public:
	CMy03UIThreadApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03UIThreadApp theApp;
