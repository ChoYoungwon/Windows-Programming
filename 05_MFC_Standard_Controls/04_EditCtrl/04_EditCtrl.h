
// 04_EditCtrl.h : main header file for the 04_EditCtrl application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy04EditCtrlApp:
// See 04_EditCtrl.cpp for the implementation of this class
//

class CMy04EditCtrlApp : public CWinApp
{
public:
	CMy04EditCtrlApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy04EditCtrlApp theApp;
