// KSView.cpp : implementation of the CKSView class
//

#include "stdafx.h"
#include "KS.h"

#include "KSDoc.h"
#include "KSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKSView

IMPLEMENT_DYNCREATE(CKSView, CView)

BEGIN_MESSAGE_MAP(CKSView, CView)
	//{{AFX_MSG_MAP(CKSView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKSView construction/destruction

CKSView::CKSView()
{
	// TODO: add construction code here

}

CKSView::~CKSView()
{
}

BOOL CKSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CKSView drawing

void CKSView::OnDraw(CDC* pDC)
{
	CKSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CKSView diagnostics

#ifdef _DEBUG
void CKSView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CKSView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CKSDoc* CKSView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKSDoc)));
	return (CKSDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKSView message handlers
