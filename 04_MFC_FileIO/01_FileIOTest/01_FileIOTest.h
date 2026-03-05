
// 01_FileIOTest.h : main header file for the 01_FileIOTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy01FileIOTestApp:
// See 01_FileIOTest.cpp for the implementation of this class
//

class CMy01FileIOTestApp : public CWinAppEx
{
public:
	CMy01FileIOTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy01FileIOTestApp theApp;
