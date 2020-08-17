// AllPrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KS.h"
#include "AllPrDlg.h"
#include "KSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAllPrDlg dialog


CAllPrDlg::CAllPrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAllPrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAllPrDlg)
	m_Action = _T("");
	m_NumFaults = _T("");
	m_NumPat = _T("");
	//}}AFX_DATA_INIT
}


void CAllPrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAllPrDlg)
	DDX_Control(pDX, IDOK, m_Close);
	DDX_Control(pDX, IDC_PROGRESS1, m_Bar);
	DDX_Control(pDX, IDC_INFO, m_Info);
	DDX_Text(pDX, IDC_ACTION, m_Action);
	DDX_Text(pDX, IDC_NUMFAULTS, m_NumFaults);
	DDX_Text(pDX, IDC_NUMPAT, m_NumPat);
	//}}AFX_DATA_MAP
}

UINT WM_ALLPRMYUPDATE=RegisterWindowMessage("MESSAGE_ALLPRMYUPDATE");

BEGIN_MESSAGE_MAP(CAllPrDlg, CDialog)
	//{{AFX_MSG_MAP(CAllPrDlg)
	ON_WM_CANCELMODE()
	ON_REGISTERED_MESSAGE(WM_ALLPRMYUPDATE,OnMyUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAllPrDlg message handlers

BOOL CAllPrDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    
	switch (Flag){
	case 0:
		SetWindowText("Ввод теста из файла");
		m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_NORMFACE));
		m_Bar.SetStep(1);
        m_Action="Обработка теста из файла "+m_FileName;
		m_MPStruct.hw=m_hWnd;
		m_MPStruct.st=m_FileName;
		m_MPStruct.M.Add(WM_ALLPRMYUPDATE);
		m_Thread=AfxBeginThread(FromFile,&m_MPStruct);
		m_Close.EnableWindow(false);
		break;
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAllPrDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
	
}

void CAllPrDlg::OnMyUpdate(WPARAM wParam, LPARAM lParam)
{
   extern int *tst, nn;
   char t[10];

	switch((int)wParam){
	case 0:
		m_Action="Ошибка чтения файла";
		break;
	case 1:
		m_Bar.SetRange(0,(int)lParam);
		break;
	case 2:
		m_NumPat="Входная последовательность состоит из "+CString(itoa(tst[0],t,10))+" наборов";
        m_NumFaults="Входная последовательность обнаруживает "+CString(itoa(nn,t,10))+" неисправностей";
		m_Bar.SetPos(m_Bar.GetPos()+1);
		break;
	case 3:
        m_Action="Процесс завершен";
		m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_OKFACE));
		m_Close.EnableWindow(true);
		break;
	case 4:
        m_Action="Не верная длина входного набора";
		m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_ABORTFACE));
		m_Close.EnableWindow(true);
		break;
	}
 UpdateData(false);
}
