
// 01_Button1.h : main header file for the 01_Button1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy01Button1App:
// See 01_Button1.cpp for the implementation of this class
//

class CMy01Button1App : public CWinApp
{
public:
	CMy01Button1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy01Button1App theApp;
