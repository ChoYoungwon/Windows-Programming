// CMyListBox.cpp : implementation file
//

#include "pch.h"
#include "08_Reflection.h"
#include "CMyListBox.h"


// CMyListBox

IMPLEMENT_DYNAMIC(CMyListBox, CListBox)

CMyListBox::CMyListBox()
{

}

CMyListBox::~CMyListBox()
{
}


BEGIN_MESSAGE_MAP(CMyListBox, CListBox)
	ON_CONTROL_REFLECT(LBN_DBLCLK, &CMyListBox::OnLbnDblclk)
END_MESSAGE_MAP()



// CMyListBox message handlers



void CMyListBox::OnLbnDblclk()
{
	CString str;
	int nIndex = GetCurSel();
	GetText(nIndex, str);
	MessageBox(str);
}
