
// 04_Progress.h : main header file for the 04_Progress application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy04ProgressApp:
// See 04_Progress.cpp for the implementation of this class
//

class CMy04ProgressApp : public CWinApp
{
public:
	CMy04ProgressApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy04ProgressApp theApp;
