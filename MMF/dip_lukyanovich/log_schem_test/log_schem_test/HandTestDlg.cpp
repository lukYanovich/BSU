// HandTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KS.h"
#include "HandTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "regmethod.h"
#include "print.h"
#include "anal.h"

/////////////////////////////////////////////////////////////////////////////
// CHandTestDlg dialog


CHandTestDlg::CHandTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHandTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHandTestDlg)
	m_OutPat = _T("");
	m_curPatLength = _T("");
	m_InPat = _T("");
	m_L = _T("");
	m_sPatFaults = _T("");
	m_AllPatFaults = _T("");
	m_NumPat = _T("");
	//}}AFX_DATA_INIT
}


void CHandTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHandTestDlg)
	DDX_Control(pDX, IDC_INFO, m_Info);
	DDX_Control(pDX, IDC_INPAT, m_InPatCntr);
	DDX_Control(pDX, IDC_LISTOUT, m_ListOutPat);
	DDX_Control(pDX, IDC_LISTPAT, m_ListPat);
	DDX_Text(pDX, IDC_OUTPAT, m_OutPat);
	DDX_Text(pDX, IDC_KURPATLENGTH, m_curPatLength);
	DDX_Text(pDX, IDC_INPAT, m_InPat);
	DDX_Text(pDX, IDC_L, m_L);
	DDX_Text(pDX, IDC_PatFaults, m_sPatFaults);
	DDX_Text(pDX, IDC_AllPatFaults, m_AllPatFaults);
	DDX_Text(pDX, IDC_NUMPAT, m_NumPat);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHandTestDlg, CDialog)
	//{{AFX_MSG_MAP(CHandTestDlg)
	ON_BN_CLICKED(IDC_MODEL, OnModel)
	ON_EN_CHANGE(IDC_INPAT, OnChangeInpat)
	ON_LBN_SELCHANGE(IDC_LISTPAT, OnSelchangeListpat)
	ON_LBN_SELCHANGE(IDC_LISTOUT, OnSelchangeListout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHandTestDlg message handlers

void CHandTestDlg::OnModel() 
{
	// TODO: Add your control notification handler code here
	extern int nh,nn;
	extern int l,*tst;
	extern char *fa,OutPat[];
	char temp[10];
    UpdateData(true);
	if(m_InPat.GetLength()!=l){
		m_sPatFaults="Неверная длина входного набора";
		m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_ABORTFACE));
        UpdateData(false); 
		return;
	}
	for(int i=0;i<m_InPat.GetLength();i++)
		if((m_InPat[i]!='0')&(m_InPat[i]!='1')){
			m_sPatFaults="Невернай символ во входном наборе";
			m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_ABORTFACE));
			UpdateData(false); 
		return;
		}
  	fa=new char[l+1];
	fa[0]='0';
	fa[1]=0;
	strcat(fa, (const char*)LPCSTR(m_InPat));
	anal(NULL);
	m_ListPat.AddString(LPCSTR(m_InPat));
	m_OutPat=CString(OutPat);
	m_ListOutPat.AddString(m_OutPat);
	m_PatFaults.Add(CString(itoa(nh,temp,10)));
	m_sPatFaults="Выбранный набор обнаруживает "+m_PatFaults.GetAt(m_PatFaults.GetSize()-1)+" неисправностей";
	m_AllPatFaults="Входная последовательность обнаруживает "+CString(itoa(nn,temp,10))+" неисправностей";
	m_NumPat="Входная последовательность состоит из "+CString(itoa(tst[0],temp,10))+" наборов";
	m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_NORMFACE));
	UpdateData(false);
	//delete [] fa;
	
}



void CHandTestDlg::OnChangeInpat() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	char szCurLength[20];
	extern int l;
 	UpdateData();
	m_curPatLength = "Текущая длина набора: " + CString(itoa(m_InPat.GetLength(), szCurLength, 10));
	//m_out="";
    UpdateData(false);
	// TODO: Add your control notification handler code here
	
}

BOOL CHandTestDlg::OnInitDialog() 
{
 	CDialog::OnInitDialog();
	
 	// TODO: Add extra initialization here
	extern int l,nn,*tst;
	char t[10];

    m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_NORMFACE));
	m_InPatCntr.LimitText(l);
	itoa(l,t,10);
	m_L="Число входов "+CString(t);
	m_AllPatFaults="Входная последовательность обнаруживает "+CString(itoa(nn,t,10))+" неисправностей";
	m_NumPat="Входная последовательность состоит из "+CString(itoa(tst[0],t,10))+" наборов";
	UpdateData(false);
		
	return TRUE;  // return TRUE unless you set the focus to a control
 	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHandTestDlg::OnSelchangeListpat() 
{
	// TODO: Add your control notification handler code here
 
	m_ListPat.GetText(m_ListPat.GetCurSel(),m_InPat);
	m_ListOutPat.SetCurSel(m_ListPat.GetCurSel());
	m_sPatFaults="Выбранный набор обнаруживает "+m_PatFaults.GetAt(m_ListPat.GetCurSel())+" неисправностей";
	m_OutPat.Empty();
	UpdateData(false);
}

void CHandTestDlg::OnSelchangeListout() 
{
	// TODO: Add your control notification handler code here

	m_ListPat.SetCurSel(m_ListOutPat.GetCurSel());
	m_sPatFaults="Выбранный набор обнаруживает "+m_PatFaults.GetAt(m_ListOutPat.GetCurSel())+" неисправностей";
	UpdateData(false);
}
