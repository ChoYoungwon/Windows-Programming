
// 03_TCPServer2.h : main header file for the 03_TCPServer2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy03TCPServer2App:
// See 03_TCPServer2.cpp for the implementation of this class
//

class CMy03TCPServer2App : public CWinApp
{
public:
	CMy03TCPServer2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03TCPServer2App theApp;
