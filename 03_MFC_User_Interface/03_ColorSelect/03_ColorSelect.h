
// 03_ColorSelect.h : main header file for the 03_ColorSelect application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy03ColorSelectApp:
// See 03_ColorSelect.cpp for the implementation of this class
//

class CMy03ColorSelectApp : public CWinApp
{
public:
	CMy03ColorSelectApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03ColorSelectApp theApp;
