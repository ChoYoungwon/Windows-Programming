
// 02_TabCtrl.h : main header file for the 02_TabCtrl application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy02TabCtrlApp:
// See 02_TabCtrl.cpp for the implementation of this class
//

class CMy02TabCtrlApp : public CWinApp
{
public:
	CMy02TabCtrlApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy02TabCtrlApp theApp;
