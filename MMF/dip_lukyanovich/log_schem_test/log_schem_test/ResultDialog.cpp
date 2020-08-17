// ResultDialog.cpp : implementation file
//

#include "stdafx.h"
#include "KS.h"
#include "ResultDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResultDialog dialog


CResultDialog::CResultDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CResultDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CResultDialog)
	//}}AFX_DATA_INIT
}


void CResultDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CResultDialog)
	DDX_Control(pDX, IDC_RICHEDIT1, m_text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CResultDialog, CDialog)
	//{{AFX_MSG_MAP(CResultDialog)
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_BUTTON, OnButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResultDialog message handlers

BOOL CResultDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

    // TODO: Add extra initialization here
	this->SetWindowText(lpFileName);
//устанавливаем шрифт фиксированной ширины.
	CFont font;
    LOGFONT lf = { 
    24, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, 
    OUT_TT_ONLY_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
    VARIABLE_PITCH | FF_DONTCARE, "Fixedsys" 
  };
	font.CreateFontIndirect(&lf);
	m_text.SetFont(&font,TRUE);

// читаем текст из файла
	HANDLE hFile;
	DWORD dwFileSize;
	HGLOBAL hBuffer;
	LPSTR lpBuffer;

	hFile=CreateFile(lpFileName,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	dwFileSize=GetFileSize(hFile,NULL);

	hBuffer=GlobalAlloc(GHND,dwFileSize+1);
	lpBuffer=(LPSTR)GlobalLock(hBuffer);

	ReadFile(hFile,lpBuffer,dwFileSize,&dwFileSize,NULL);
	lpBuffer[dwFileSize]='\0';

	CloseHandle(hFile);

// отображаем текст в RichEdit
	m_text.SendMessage(WM_SETTEXT,0,(LPARAM)lpBuffer);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}




void CResultDialog::OnButton() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL, NULL, "NOTEPAD.EXE", lpFileName, NULL, SW_SHOWNORMAL);
	
}
