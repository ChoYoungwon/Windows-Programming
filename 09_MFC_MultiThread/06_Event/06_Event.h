
// 06_Event.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy06EventApp:
// See 06_Event.cpp for the implementation of this class
//

class CMy06EventApp : public CWinApp
{
public:
	CMy06EventApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy06EventApp theApp;
