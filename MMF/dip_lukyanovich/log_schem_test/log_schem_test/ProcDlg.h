#if !defined(AFX_PROCDLG_H__C538E1C0_261F_11D7_9C16_BAD51342AF48__INCLUDED_)
#define AFX_PROCDLG_H__C538E1C0_261F_11D7_9C16_BAD51342AF48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProcDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProcDlg dialog

class CProcDlg : public CDialog
{
// Construction
public:
	CProcDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProcDlg)
	enum { IDD = IDD_PROC_DLG };
	CProgressCtrl	m_ProgErr;
	CString	m_T1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCDLG_H__C538E1C0_261F_11D7_9C16_BAD51342AF48__INCLUDED_)
