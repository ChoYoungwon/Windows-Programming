
// 02_TreeViewTest.h : main header file for the 02_TreeViewTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy02TreeViewTestApp:
// See 02_TreeViewTest.cpp for the implementation of this class
//

class CMy02TreeViewTestApp : public CWinApp
{
public:
	CMy02TreeViewTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy02TreeViewTestApp theApp;
