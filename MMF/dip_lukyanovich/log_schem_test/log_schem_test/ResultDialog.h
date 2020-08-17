#if !defined(AFX_RESULTDIALOG_H__5CCE6DC0_145F_11D7_9C16_9F324FC63451__INCLUDED_)
#define AFX_RESULTDIALOG_H__5CCE6DC0_145F_11D7_9C16_9F324FC63451__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResultDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResultDialog dialog

class CResultDialog : public CDialog
{
// Construction
public:
	LPCSTR lpFileName;
	CResultDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CResultDialog)
	enum { IDD = IDD_RESULT };
	CRichEditCtrl	m_text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResultDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CResultDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULTDIALOG_H__5CCE6DC0_145F_11D7_9C16_9F324FC63451__INCLUDED_)
