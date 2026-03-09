
// 08_Reflection.h : main header file for the 08_Reflection application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy08ReflectionApp:
// See 08_Reflection.cpp for the implementation of this class
//

class CMy08ReflectionApp : public CWinApp
{
public:
	CMy08ReflectionApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy08ReflectionApp theApp;
