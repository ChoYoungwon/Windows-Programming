
// 03_ModalDialog3.h : main header file for the 03_ModalDialog3 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy03ModalDialog3App:
// See 03_ModalDialog3.cpp for the implementation of this class
//

class CMy03ModalDialog3App : public CWinApp
{
public:
	CMy03ModalDialog3App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03ModalDialog3App theApp;
