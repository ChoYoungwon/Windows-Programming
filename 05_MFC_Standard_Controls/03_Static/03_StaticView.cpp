
// 03_StaticView.cpp : implementation of the CMy03StaticView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "03_Static.h"
#endif

#include "03_StaticDoc.h"
#include "03_StaticView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03StaticView

IMPLEMENT_DYNCREATE(CMy03StaticView, CFormView)

BEGIN_MESSAGE_MAP(CMy03StaticView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_STN_CLICKED(IDC_METAFILE, &CMy03StaticView::OnStnClickedMetafile)
END_MESSAGE_MAP()

// CMy03StaticView construction/destruction

CMy03StaticView::CMy03StaticView() noexcept
	: CFormView(IDD_MY03_STATIC_FORM)
{
	// TODO: add construction code here

}

CMy03StaticView::~CMy03StaticView()
{
}

void CMy03StaticView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_METAFILE, m_metafile);
}

BOOL CMy03StaticView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy03StaticView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_metafile.SetEnhMetaFile(::GetEnhMetaFile(_T("test.emf")));
}


// CMy03StaticView printing

BOOL CMy03StaticView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy03StaticView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy03StaticView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy03StaticView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy03StaticView diagnostics

#ifdef _DEBUG
void CMy03StaticView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy03StaticView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy03StaticDoc* CMy03StaticView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03StaticDoc)));
	return (CMy03StaticDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy03StaticView message handlers

void CMy03StaticView::OnStnClickedMetafile()
{
	// TODO: Add your control notification handler code here
	MessageBox(_T("확장 메타파일 그림 클릭!"));
}
