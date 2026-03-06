
// 02_Button2.h : main header file for the 02_Button2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy02Button2App:
// See 02_Button2.cpp for the implementation of this class
//

class CMy02Button2App : public CWinApp
{
public:
	CMy02Button2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy02Button2App theApp;
