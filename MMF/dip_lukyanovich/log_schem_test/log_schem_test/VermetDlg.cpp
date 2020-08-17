// VermetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KS.h"
#include "VermetDlg.h"
#include "vermet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CVermetDlg dialog


CVermetDlg::CVermetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVermetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVermetDlg)
	m_M1 = _T("");
	m_M2 = _T("");
	m_M3 = _T("");
	m_Action = _T("");
	m_NumPat = _T("");
	m_NumFaults = _T("");
	m_NumPatGen = _T("");
	m_TestCount = _T("");
	//}}AFX_DATA_INIT
}


void CVermetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVermetDlg)
	DDX_Control(pDX, IDOK, m_Close);
	DDX_Control(pDX, IDC_GENERATE, m_Start);
	DDX_Control(pDX, IDC_STOP, m_Stop);
	DDX_Control(pDX, IDC_BAR, m_Progress);
	DDX_Control(pDX, IDC_INFO, m_Info);
	DDX_Text(pDX, IDC_EDIT1, m_M1);
	DDX_Text(pDX, IDC_EDIT2, m_M2);
	DDX_Text(pDX, IDC_EDIT3, m_M3);
	DDX_Text(pDX, IDC_ACTION, m_Action);
	DDX_Text(pDX, IDC_NUMPAT, m_NumPat);
	DDX_Text(pDX, IDC_NUMFAULTS, m_NumFaults);
	DDX_Text(pDX, IDC_NUMPATGEN, m_NumPatGen);
	DDX_Text(pDX, IDC_TESTCOUNT, m_TestCount);
	//}}AFX_DATA_MAP
}

UINT WM_VERMETUPDATE=RegisterWindowMessage("MESSAGE_VERMETUPDATE");

BEGIN_MESSAGE_MAP(CVermetDlg, CDialog)
	//{{AFX_MSG_MAP(CVermetDlg)
	ON_BN_CLICKED(IDC_GENERATE, OnGenerate)
	ON_REGISTERED_MESSAGE(WM_VERMETUPDATE,OnVerMetUpdate)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVermetDlg message handlers

BOOL CVermetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	extern int nn, nhcf, * tst;
	char t[10];

	m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_NORMFACE));
	if (nn != 0) {
		m_Progress.SetPos(nn * 100 / nhcf);
		m_NumPat = "Входная последовательность состоит из " + CString(itoa(tst[0], t, 10)) + " наборов";
		m_NumFaults = "Входная последовательность обнаруживает " + CString(itoa(nn, t, 10)) + " неисправностей";
		UpdateData(false);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CVermetDlg::OnGenerate()
{
	// TODO: Add your control notification handler code here

	UpdateData();

	m_MPStruct.M.SetSize(4);
	m_MPStruct.M.SetAt(0, atoi(LPCSTR(m_M1)));
	m_MPStruct.M.SetAt(1, atoi(LPCSTR(m_M2)));
	m_MPStruct.M.SetAt(2, atoi(LPCSTR(m_M3)));
	m_MPStruct.M.SetAt(3, WM_VERMETUPDATE);
	m_MPStruct.hw = m_hWnd;

	if ((m_MPStruct.M.GetAt(0) <= 0) | (m_MPStruct.M.GetAt(2) <= 0) | (m_MPStruct.M.GetAt(1) <= 0))
	{
		m_Action = "Неверно введены параметры M1, M2, M3";
		m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_ABORTFACE));
		UpdateData(false);
		return;
	}

	m_Thread = AfxBeginThread(vermet, &m_MPStruct);
	startTime = clock();
	m_Stop.EnableWindow(true);
	m_Start.EnableWindow(false);
	m_Close.EnableWindow(false);
	m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_WORK));
	CKSApp* pApp = (CKSApp*)AfxGetApp();
	pApp->EnableMenu();

}

void CVermetDlg::OnVerMetUpdate(WPARAM wParam, LPARAM lParam)
{
	extern int* tst, nn, nhcf;
	clock_t time;
	char t[10];

	switch (wParam) {

	case 0: m_Action = "Идет генерация входного набора";
		break;
	case 1:m_Action = "Идет генерация входной последовательности";
		break;
	case 2:
		m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_OKFACE));
		m_Start.EnableWindow(true);
		m_Stop.EnableWindow(false);
		m_Close.EnableWindow(true);
		finishTime = clock();
		int d, s;
		m_Action = "Процесс завершен за " + CString(_gcvt((double)(finishTime - startTime) / CLOCKS_PER_SEC, 4, t)) + " сек.";
		break;
	}
	m_NumPat = "Входная последовательность состоит из " + CString(itoa(tst[0], t, 10)) + " наборов";
	m_NumFaults = "Входная последовательность обнаруживает " + CString(itoa(nn, t, 10)) + " неисправностей";
	m_NumPatGen = "Сгенерировано " + CString(itoa((int)lParam, t, 10)) + " входных наборов";
	m_Progress.SetPos(nn * 100 / nhcf);
	m_TestCount = "Полнота теста " + CString(itoa(m_Progress.GetPos(), t, 10)) + "%";
	UpdateData(false);
}

void CVermetDlg::OnStop()
{
	// TODO: Add your control notification handler code here
	TerminateThread(m_Thread->m_hThread, 0);
	m_Start.EnableWindow(true);
	m_Close.EnableWindow(true);
	m_Action = "Процесс генерации теста прерван";
	m_Info.SetIcon(AfxGetApp()->LoadIcon(IDI_ABORTFACE));
	UpdateData(false);


}
