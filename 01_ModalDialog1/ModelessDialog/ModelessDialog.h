
// ModelessDialog.h : main header file for the ModelessDialog application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CModelessDialogApp:
// See ModelessDialog.cpp for the implementation of this class
//

class CModelessDialogApp : public CWinApp
{
public:
	CModelessDialogApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CModelessDialogApp theApp;
