
// 07_Semaphore.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy07SemaphoreApp:
// See 07_Semaphore.cpp for the implementation of this class
//

class CMy07SemaphoreApp : public CWinApp
{
public:
	CMy07SemaphoreApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy07SemaphoreApp theApp;
