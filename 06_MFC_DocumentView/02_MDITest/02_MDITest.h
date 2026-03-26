
// 02_MDITest.h : main header file for the 02_MDITest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy02MDITestApp:
// See 02_MDITest.cpp for the implementation of this class
//

class CMy02MDITestApp : public CWinApp
{
public:
	CMy02MDITestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy02MDITestApp theApp;
