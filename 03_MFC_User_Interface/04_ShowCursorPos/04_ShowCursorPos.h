
// 04_ShowCursorPos.h : main header file for the 04_ShowCursorPos application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy04ShowCursorPosApp:
// See 04_ShowCursorPos.cpp for the implementation of this class
//

class CMy04ShowCursorPosApp : public CWinApp
{
public:
	CMy04ShowCursorPosApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy04ShowCursorPosApp theApp;
