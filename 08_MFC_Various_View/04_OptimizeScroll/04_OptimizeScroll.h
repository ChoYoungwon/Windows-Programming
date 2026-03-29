
// 04_OptimizeScroll.h : main header file for the 04_OptimizeScroll application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy04OptimizeScrollApp:
// See 04_OptimizeScroll.cpp for the implementation of this class
//

class CMy04OptimizeScrollApp : public CWinApp
{
public:
	CMy04OptimizeScrollApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy04OptimizeScrollApp theApp;
