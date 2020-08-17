// KS.h : main header file for the KS application
//

#if !defined(AFX_KS_H__B9D79344_1449_11D7_9C16_C41715B34A51__INCLUDED_)
#define AFX_KS_H__B9D79344_1449_11D7_9C16_C41715B34A51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKSApp:
// See KS.cpp for the implementation of this class
//

class CKSApp : public CWinApp
{
public:
	void EnableMenu();
	CKSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKSApp)
	afx_msg void OnAppAbout();
	afx_msg void OnResultTest(UINT nType);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KS_H__B9D79344_1449_11D7_9C16_C41715B34A51__INCLUDED_)
