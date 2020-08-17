// KSView.h : interface of the CKSView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KSVIEW_H__B9D7934C_1449_11D7_9C16_C41715B34A51__INCLUDED_)
#define AFX_KSVIEW_H__B9D7934C_1449_11D7_9C16_C41715B34A51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Afxcview.h"

class CKSView : public CTreeView
{
protected: // create from serialization only
	CKSView();
	DECLARE_DYNCREATE(CKSView)

// Attributes
public:
	CKSDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKSView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKSView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in KSView.cpp
inline CKSDoc* CKSView::GetDocument()
   { return (CKSDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KSVIEW_H__B9D7934C_1449_11D7_9C16_C41715B34A51__INCLUDED_)
