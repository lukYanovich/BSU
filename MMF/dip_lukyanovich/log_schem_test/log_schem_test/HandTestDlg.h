#if !defined(AFX_HANDTESTDLG_H__7A429C40_21B2_11D7_9C16_F2040FDEEC57__INCLUDED_)
#define AFX_HANDTESTDLG_H__7A429C40_21B2_11D7_9C16_F2040FDEEC57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HandTestDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHandTestDlg dialog

class CHandTestDlg : public CDialog
{
// Construction
public:
	CStringArray m_PatFaults;//массив хранит сколько неисправностей обнаруживает набор
	CHandTestDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHandTestDlg)
	enum { IDD = IDD_HANDTEST };
	CButton	m_Info;
	CEdit	m_InPatCntr;
	CListBox	m_ListOutPat;
	CListBox	m_ListPat;
	CString	m_OutPat;
	CString	m_curPatLength;
	CString	m_InPat;
	CString	m_L;
	CString	m_sPatFaults;
	CString	m_AllPatFaults;
	CString	m_NumPat;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHandTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHandTestDlg)
	afx_msg void OnModel();
	afx_msg void OnChangeInpat();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeListpat();
	afx_msg void OnSelchangeListout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANDTESTDLG_H__7A429C40_21B2_11D7_9C16_F2040FDEEC57__INCLUDED_)
