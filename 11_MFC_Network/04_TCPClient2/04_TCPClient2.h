
// 04_TCPClient2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy04TCPClient2App:
// See 04_TCPClient2.cpp for the implementation of this class
//

class CMy04TCPClient2App : public CWinApp
{
public:
	CMy04TCPClient2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy04TCPClient2App theApp;
