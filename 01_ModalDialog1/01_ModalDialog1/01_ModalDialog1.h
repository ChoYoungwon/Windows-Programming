
// 01_ModalDialog1.h : main header file for the 01_ModalDialog1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy01ModalDialog1App:
// See 01_ModalDialog1.cpp for the implementation of this class
//

class CMy01ModalDialog1App : public CWinApp
{
public:
	CMy01ModalDialog1App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy01ModalDialog1App theApp;
