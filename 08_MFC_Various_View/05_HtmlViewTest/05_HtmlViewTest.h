
// 05_HtmlViewTest.h : main header file for the 05_HtmlViewTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy05HtmlViewTestApp:
// See 05_HtmlViewTest.cpp for the implementation of this class
//

class CMy05HtmlViewTestApp : public CWinApp
{
public:
	CMy05HtmlViewTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy05HtmlViewTestApp theApp;
