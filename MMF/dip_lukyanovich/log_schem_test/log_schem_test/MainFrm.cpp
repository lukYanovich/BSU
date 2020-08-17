// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "KS.h"

#include "MainFrm.h"
#include "KSDoc.h"
#include "anal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_RESULT_CLEAR, OnResultClear)
	//}}AFX_MSG_MAP
	// Global help commands
	ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	
	// status line indicator
	ID_SEPARATOR,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	
	GetMenu()->EnableMenuItem(2,MF_BYPOSITION|MF_GRAYED);
	GetMenu()->EnableMenuItem(3,MF_BYPOSITION|MF_GRAYED);
	CToolBarCtrl* pToolBar=&m_wndToolBar.GetToolBarCtrl();
	//pToolBar->EnableButton(ID_TESTING_RM,false);
/*	pToolBar->HideButton(ID_TESTING_RM,true);
	pToolBar->HideButton(ID_TEST_FROM_FILE,true);
	pToolBar->HideButton(ID_VERMET,true);
	pToolBar->HideButton(ID_HAND_TEST,true);
	pToolBar->HideButton(ID_RESULT_PROTOKOL,true);
	pToolBar->HideButton(ID_RESULT_TEST,true);
	pToolBar->HideButton(ID_RESULT_FAULTS,true);
*/		
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    
	cs.cy = ::GetSystemMetrics(SM_CYSCREEN) / 1.4; 
    cs.cx = ::GetSystemMetrics(SM_CXSCREEN) / 1.4; 
    cs.y = ((cs.cy * 1.4) - cs.cy) / 2; 
    cs.x = ((cs.cx * 1.4) - cs.cx) / 2;


	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnResultClear() 
{
	// TODO: Add your command handler code here
/*	CString fName;
	extern char *LpName;
	fName=CString(LpName);
	if(!DeleteFile(LPCTSTR(fName+".tsd")))
		 MessageBox("Файл "+fName+".tsd"+" удалить не удалось", MB_OK);
	if(!DeleteFile(LPCTSTR(fName+".tst")))
		 MessageBox("Файл "+fName+".tst"+" удалить не удалось", MB_OK);
	if(!DeleteFile(LPCTSTR(fName+".fff")))
		 MessageBox("Файл "+fName+".fff"+" удалить не удалось", MB_OK);
	if(!DeleteFile(LPCTSTR(fName+".pte")))
		 MessageBox("Файл "+fName+".pte"+" удалить не удалось", MB_OK);
	/*extern int *tst,nhcf,nn,nh,nhcf1;
	for(int i=0;i<6000;i++) tst[i]=0;
	nhcf=0;
		nhcf1=0;
		nn=0;
		nh=0;*/
}






//DEL void CMainFrame::OnFileOpen() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 
//DEL 	CFrameWnd::o
//DEL }

//DEL void CMainFrame::OnFileOpen() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	AfxGetApp()->OnFileOpen();
//DEL }

void CMainFrame::EnableBandM()
{
GetMenu()->EnableMenuItem(2,MF_BYPOSITION|MF_GRAYED);
	GetMenu()->EnableMenuItem(3,MF_BYPOSITION|MF_GRAYED);
	CToolBarCtrl* pToolBar=&m_wndToolBar.GetToolBarCtrl();
	//pToolBar->EnableButton(ID_TESTING_RM,false);
	pToolBar->HideButton(ID_TESTING_RM,false);
	pToolBar->HideButton(ID_TEST_FROM_FILE,true);
	pToolBar->HideButton(ID_VERMET,true);
	pToolBar->HideButton(ID_HAND_TEST,true);
	pToolBar->HideButton(ID_RESULT_PROTOKOL,true);
	pToolBar->HideButton(ID_RESULT_TEST,true);
	pToolBar->HideButton(ID_RESULT_FAULTS,true);
}
