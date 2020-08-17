#if !defined(AFX_ALLPRDLG_H__34374D20_3780_11D7_9C16_C4E15D56564A__INCLUDED_)
#define AFX_ALLPRDLG_H__34374D20_3780_11D7_9C16_C4E15D56564A__INCLUDED_

#include "KSDoc.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AllPrDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAllPrDlg dialog

class CAllPrDlg : public CDialog
{
// Construction
public:
	MPStruct m_MPStruct;
	CString m_FileName;
	int m_NumStrings;
	int Flag;
	CAllPrDlg(CWnd* pParent = NULL);   // standard constructor
	void OnMyUpdate(WPARAM wParam,LPARAM lParam);

// Dialog Data
	//{{AFX_DATA(CAllPrDlg)
	enum { IDD = IDD_ALLPRDLG };
	CButton	m_Close;
	CProgressCtrl	m_Bar;
	CButton	m_Info;
	CString	m_Action;
	CString	m_NumFaults;
	CString	m_NumPat;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAllPrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:


	// Generated message map functions
	//{{AFX_MSG(CAllPrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	CWinThread *m_Thread;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLPRDLG_H__34374D20_3780_11D7_9C16_C4E15D56564A__INCLUDED_)
