
// 08_ReflectionView.cpp : implementation of the CMy08ReflectionView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "08_Reflection.h"
#endif

#include "08_ReflectionDoc.h"
#include "08_ReflectionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy08ReflectionView

IMPLEMENT_DYNCREATE(CMy08ReflectionView, CFormView)

BEGIN_MESSAGE_MAP(CMy08ReflectionView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy08ReflectionView construction/destruction

CMy08ReflectionView::CMy08ReflectionView() noexcept
	: CFormView(IDD_MY08_REFLECTION_FORM)
{
	// TODO: add construction code here

}

CMy08ReflectionView::~CMy08ReflectionView()
{
}

void CMy08ReflectionView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BOOL CMy08ReflectionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy08ReflectionView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_list.AddString(_T("사과"));
	m_list.AddString(_T("포도"));
	m_list.AddString(_T("참외"));
	m_list.AddString(_T("수박"));
}


// CMy08ReflectionView printing

BOOL CMy08ReflectionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy08ReflectionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy08ReflectionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy08ReflectionView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy08ReflectionView diagnostics

#ifdef _DEBUG
void CMy08ReflectionView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy08ReflectionView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy08ReflectionDoc* CMy08ReflectionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy08ReflectionDoc)));
	return (CMy08ReflectionDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy08ReflectionView message handlers
