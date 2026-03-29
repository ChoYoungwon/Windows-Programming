
// 03_ScrollViewTest.h : main header file for the 03_ScrollViewTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy03ScrollViewTestApp:
// See 03_ScrollViewTest.cpp for the implementation of this class
//

class CMy03ScrollViewTestApp : public CWinApp
{
public:
	CMy03ScrollViewTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03ScrollViewTestApp theApp;
