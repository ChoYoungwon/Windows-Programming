
// 07_SubclassView.cpp : implementation of the CMy07SubclassView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "07_Subclass.h"
#endif

#include "07_SubclassDoc.h"
#include "07_SubclassView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy07SubclassView

IMPLEMENT_DYNCREATE(CMy07SubclassView, CFormView)

BEGIN_MESSAGE_MAP(CMy07SubclassView, CFormView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy07SubclassView construction/destruction

CMy07SubclassView::CMy07SubclassView() noexcept
	: CFormView(IDD_MY07_SUBCLASS_FORM)
{
	// TODO: add construction code here

}

CMy07SubclassView::~CMy07SubclassView()
{
}

void CMy07SubclassView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
}

BOOL CMy07SubclassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMy07SubclassView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_edit2.SubclassDlgItem(IDC_EDIT2, this);
}


// CMy07SubclassView printing

BOOL CMy07SubclassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy07SubclassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy07SubclassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy07SubclassView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}


// CMy07SubclassView diagnostics

#ifdef _DEBUG
void CMy07SubclassView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy07SubclassView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy07SubclassDoc* CMy07SubclassView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy07SubclassDoc)));
	return (CMy07SubclassDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy07SubclassView message handlers
