
// 02_WorkerThread2.h : main header file for the 02_WorkerThread2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy02WorkerThread2App:
// See 02_WorkerThread2.cpp for the implementation of this class
//

class CMy02WorkerThread2App : public CWinApp
{
public:
	CMy02WorkerThread2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy02WorkerThread2App theApp;
