
// 01_ImageList.h : main header file for the 01_ImageList application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy01ImageListApp:
// See 01_ImageList.cpp for the implementation of this class
//

class CMy01ImageListApp : public CWinApp
{
public:
	CMy01ImageListApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy01ImageListApp theApp;
