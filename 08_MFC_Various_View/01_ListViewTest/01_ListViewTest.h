
// 01_ListViewTest.h : main header file for the 01_ListViewTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy01ListViewTestApp:
// See 01_ListViewTest.cpp for the implementation of this class
//

class CMy01ListViewTestApp : public CWinApp
{
public:
	CMy01ListViewTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy01ListViewTestApp theApp;
