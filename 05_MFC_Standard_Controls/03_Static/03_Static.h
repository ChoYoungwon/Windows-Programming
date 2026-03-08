
// 03_Static.h : main header file for the 03_Static application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy03StaticApp:
// See 03_Static.cpp for the implementation of this class
//

class CMy03StaticApp : public CWinApp
{
public:
	CMy03StaticApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03StaticApp theApp;
