
// 07_Subclass.h : main header file for the 07_Subclass application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy07SubclassApp:
// See 07_Subclass.cpp for the implementation of this class
//

class CMy07SubclassApp : public CWinApp
{
public:
	CMy07SubclassApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy07SubclassApp theApp;
