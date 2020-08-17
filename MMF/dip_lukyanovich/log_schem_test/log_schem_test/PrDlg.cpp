// PrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KS.h"
#include "PrDlg.h"
#include "KSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrDlg dialog
char *msg[] = {
  "читаю inf файл", // 25
  "читаю tst файл", // 26
  "Ввод списка неисправностей cff",
  "Ввод идентификаторов линий схемы",
  "Идет генерация теста регулярным методом",
  "Процесс генерации теста завершен"

};


CPrDlg::CPrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrDlg)
	m_Action = _T("");
	m_NumFaults = _T("");
	m_PrCount = _T("");
	m_NumPat = _T("");
	//}}AFX_DATA_INIT
}


void CPrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrDlg)
	DDX_Control(pDX, IDC_INFO, m_Info);
	DDX_Control(pDX, IDC_STOP, m_Stop);
	DDX_Control(pDX, IDC_START, m_Start);
	DDX_Control(pDX, IDC_PROGFAULTS, m_PrFaults);
	DDX_Text(pDX, IDC_ACTION, m_Action);
	DDX_Text(pDX, IDC_NUMFAULTS, m_NumFaults);
	DDX_Text(pDX, IDC_TESTCOUNT, m_PrCount);
	DDX_Text(pDX, IDC_NUMPAT, m_NumPat);
	//}}AFX_DATA_MAP
}


UINT WM_MYUPDATE=RegisterWindowMessage("MESSAGE_MYUPDATE");

BEGIN_MESSAGE_MAP(CPrDlg, CDialog)
	//{{AFX_MSG_MAP(CPrDlg)
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_WM_DESTROY()
	ON_WM_CANCELMODE()
	ON_REGISTERED_MESSAGE(WM_MYUPDATE,OnMyUpdate)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrDlg message handlers

void CPrDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
  startTime=clock();
  m_Thread=AfxBeginThread(Mainpr,m_hWnd);
  m_Action="Идет генерация теста";
  m_Stop.EnableWindow(true);
  m_Start.EnableWindow(false);
  m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_WORK));
}

void CPrDlg::OnMyUpdate(WPARAM wParam,LPARAM lParam)
{
 extern int nn,nhcf,*tst;
 char t[10];
 m_Action=CString(msg[wParam]);
 m_NumFaults="Входная последовательность обнаруживает "+CString(itoa(m_nn+nn,t,10))+" неисправностей";
 if(wParam==4)
	m_NumPat="В тест включено "+CString(itoa(tst[0],t,10))+" наборов";
 if(nhcf!=0) {
	 m_PrFaults.SetPos((m_nn+nn)*100/nhcf);
	 m_PrCount="Полнота теста "+CString(itoa(m_PrFaults.GetPos(),t,10))+"%";
 }
 if(wParam==5) {
	 m_Stop.EnableWindow(false);
	 m_Start.EnableWindow(true);
     m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_OKFACE));
	 CKSApp *pApp=(CKSApp*)AfxGetApp();
	 pApp->EnableMenu();
	 finishTime=clock();
	 m_Action="Процесс завершен за "+CString(_gcvt((double)(finishTime - startTime) / CLOCKS_PER_SEC,5,t))+" сек.";
 }
 UpdateData(false);
}

BOOL CPrDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	extern int nn,nhcf,*tst;
	char t[10];

	m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_NORMFACE));
	m_Stop.EnableWindow(false);
	SetWindowText("Генерация теста регулярным методом");
	m_Action="Регулярный метод";
	m_NumFaults="В данный момент обнаружено "+CString(itoa(m_nn,t,10))+" неисправностей";
	m_NumPat="Входная последовательность состоит из "+CString(itoa(tst[0],t,10))+" наборов";
	m_PrFaults.SetPos(m_nn*100/nhcf);
	m_PrCount="Полнота теста "+CString(itoa(m_PrFaults.GetPos(),t,10))+"%";
	UpdateData(false);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPrDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	extern int nn;
	nn+=m_nn;	
}

void CPrDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
}

void CPrDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
   TerminateThread(m_Thread->m_hThread,0);
   m_Start.EnableWindow(true);
   m_Action="Процесс генерации теста прерван";
   m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_ABORTFACE));
   UpdateData(false);
}
