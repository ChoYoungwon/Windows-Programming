
// 03_SpinButton.h : main header file for the 03_SpinButton application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy03SpinButtonApp:
// See 03_SpinButton.cpp for the implementation of this class
//

class CMy03SpinButtonApp : public CWinApp
{
public:
	CMy03SpinButtonApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03SpinButtonApp theApp;
