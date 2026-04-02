
// 04_CriticalSection.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy04CriticalSectionApp:
// See 04_CriticalSection.cpp for the implementation of this class
//

class CMy04CriticalSectionApp : public CWinApp
{
public:
	CMy04CriticalSectionApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy04CriticalSectionApp theApp;
