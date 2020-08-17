#if !defined(AFX_PRDLG_H__D7735AE2_2666_11D7_9C16_EACEC6286157__INCLUDED_)
#define AFX_PRDLG_H__D7735AE2_2666_11D7_9C16_EACEC6286157__INCLUDED_

#if _MSC_VER > 1000
#pragma once


#endif // _MSC_VER > 1000

// PrDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrDlg dialog


class CPrDlg : public CDialog
{
// Construction
public:
	int m_nn;
	clock_t finishTime;
	clock_t startTime;

	
	afx_msg void OnMyUpdate(WPARAM wParam,LPARAM lParam);
	CPrDlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CPrDlg)
	enum { IDD = IDD_PRDLG };
	CButton	m_Info;
	CButton	m_Stop;
	CButton	m_Start;
	CProgressCtrl	m_PrFaults;
	CString	m_Action;
	CString	m_NumFaults;
	CString	m_PrCount;
	CString	m_NumPat;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrDlg)
	CWinThread* m_Thread;
	afx_msg void OnStart();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnCancelMode();
	afx_msg void OnStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRDLG_H__D7735AE2_2666_11D7_9C16_EACEC6286157__INCLUDED_)
