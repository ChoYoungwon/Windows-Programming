
// 01_Splitter.h : main header file for the 01_Splitter application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy01SplitterApp:
// See 01_Splitter.cpp for the implementation of this class
//

class CMy01SplitterApp : public CWinApp
{
public:
	CMy01SplitterApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy01SplitterApp theApp;
