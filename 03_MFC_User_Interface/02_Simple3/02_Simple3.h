
// 02_Simple3.h : main header file for the 02_Simple3 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy02Simple3App:
// See 02_Simple3.cpp for the implementation of this class
//

class CMy02Simple3App : public CWinApp
{
public:
	CMy02Simple3App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy02Simple3App theApp;
