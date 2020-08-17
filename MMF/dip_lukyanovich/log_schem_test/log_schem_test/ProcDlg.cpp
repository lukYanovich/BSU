// ProcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KS.h"
#include "ProcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcDlg dialog


CProcDlg::CProcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcDlg)
	m_T1 = _T("");
	//}}AFX_DATA_INIT
}


void CProcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_ProgErr);
	DDX_Text(pDX, IDC_T1, m_T1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcDlg, CDialog)
	//{{AFX_MSG_MAP(CProcDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcDlg message handlers

BOOL CProcDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_T1="ppwprdkqwpfpqwj";
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
