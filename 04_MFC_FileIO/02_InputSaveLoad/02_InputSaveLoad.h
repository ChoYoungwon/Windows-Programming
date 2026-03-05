
// 02_InputSaveLoad.h : main header file for the 02_InputSaveLoad application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy02InputSaveLoadApp:
// See 02_InputSaveLoad.cpp for the implementation of this class
//

class CMy02InputSaveLoadApp : public CWinAppEx
{
public:
	CMy02InputSaveLoadApp() noexcept;


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

extern CMy02InputSaveLoadApp theApp;
