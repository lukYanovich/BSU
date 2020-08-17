#if !defined(AFX_VERMETDLG_H__85F8A700_35E4_11D7_9C16_C75B90DF934A__INCLUDED_)
#define AFX_VERMETDLG_H__85F8A700_35E4_11D7_9C16_C75B90DF934A__INCLUDED_

#include "KSDoc.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VermetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVermetDlg dialog

class CVermetDlg : public CDialog
{
// Construction
public:
	clock_t finishTime;
	clock_t startTime;
	CString m_Time;
	MPStruct m_MPStruct;
	void OnVerMetUpdate(WPARAM wParam,LPARAM lParam);
	CVermetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CVermetDlg)
	enum { IDD = IDD_VERMET };
	CButton	m_Close;
	CButton	m_Start;
	CButton	m_Stop;
	CProgressCtrl	m_Progress;
	CButton	m_Info;
	CString	m_M1;
	CString	m_M2;
	CString	m_M3;
	CString	m_Action;
	CString	m_NumPat;
	CString	m_NumFaults;
	CString	m_NumPatGen;
	CString	m_TestCount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVermetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CWinThread *m_Thread;

	// Generated message map functions
	//{{AFX_MSG(CVermetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnGenerate();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VERMETDLG_H__85F8A700_35E4_11D7_9C16_C75B90DF934A__INCLUDED_)
