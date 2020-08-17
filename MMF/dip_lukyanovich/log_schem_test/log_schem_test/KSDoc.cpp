// KSDoc.cpp : implementation of the CKSDoc class
//

#include "stdafx.h"
#include "KS.h"
#include "prdlg.h"


#include "KSDoc.h"
#include "handtestdlg.h"
#include "regmethod.h"
#include "print.h"
#include "anal.h"
#include "vermet.h"
#include "vermetdlg.h"
#include "allprdlg.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define HIGH_BIT 0x80000000
//#define INT_SIZE 32

extern char appDir[];
CString CSfilePath="";
int flagFileOpen = 0;
char *LpName; // Путь и имя схемы
char Ident[20000];
int PointIdent[5000];
// CRecentFileList recFList(0,"Recent File List","File%d",4,20);
char *errors[] = {
  "успешно конвертирован.",                                  // 0
  "Ошибка открытия файла BIBLEL.",                           // 1
  "Ошибка открытия файла описания.",                         // 2
  "Ошибка открытия файла неисправностей.",                   // 3
  "Недостаточно памяти.",                                    // 4 
  "Ошибка открытия файла протокола.",                        // 5
  "Ошибка открытия файла идентификаторов линий схемы.",      // 6 
  "Файл неисправностей успешно сохранен.",                   // 7
  "Недопустимое значение на входе схемы.",                   // 8
  "Моделирование успешно завершено.",                        // 9
  "Закончил чтение файла",                                   // 10 
  "Ошибка открытия файла с тестом.",                         // 11 
  "Тест успешно построен."                                   // 12
  "",//13 Ошибка открытия файла протокола
  "",//14 Ошибка открытия файла .pnt
  "",//15
  "",//16
  "00001",//17 Ошибка открытия файла .inf
  "00002",//18
  "00003",//19
  "00004",//20
  "00005",//21
  "00006",//22
  "00007",//23
  "00008",//24
  "Ошибка открытия файла INF - выходного", // 25
  "Ошибка открытия файла CFF - выходного" // 26

};
////////////////////////////////////////////////////////////////////////
//int i1;//?                    
int  *m11, *m12, *m2;
int  *sm,*ml,*mn,*mh,*nvx,*svx,*nvix,*svix,*nvixc,*cf,*nct,*ctn,*ncte,*ctne;
int  ns;   // кол-во элементов в схеме 
int  nl;   // кол-во  узлов в схеме    
int	 l;    // кол-во пеpвичных входов  
int  n;    // кол-во выходов и контp.точек 
int  nt=0, nhcf1,nhcf, *tst;
static int  *m11bib,*m12bib,*m2bib,*sbib;
static int  *mlbib,*mnbib,*mhbib; 

FILE  *stream,*fptr, *fcf, *in_file;

static int el_n;
static int mt_n;

char *fa;
////

/////////////////////////////////////////////////////////////////////////////
// CKSDoc

IMPLEMENT_DYNCREATE(CKSDoc, CDocument)

BEGIN_MESSAGE_MAP(CKSDoc, CDocument)
	//{{AFX_MSG_MAP(CKSDoc)
	ON_COMMAND(ID_TESTING_RM, OnTestingRm)
	ON_COMMAND(ID__TEXNOLOGI, OnTexnologi)
	ON_COMMAND(ID_HAND_TEST, OnHandTest)
	ON_COMMAND(ID_TEST_FROM_FILE, OnTestFromFile)
	ON_COMMAND(ID_VERMET, OnVermet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKSDoc construction/destruction

CKSDoc::CKSDoc()
{
	// TODO: add one-time construction code here

}

CKSDoc::~CKSDoc()
{
}

BOOL CKSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKSDoc serialization

void CKSDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
		int open_tsc_error; // i, j=0;
		CString message;

		if (flagFileOpen)
		{
			delete[] LpName;
			ClearArrays();
			CSfilePath.Empty();
		}

		//ClearArrays();

		LpName = new char[255];
		//if (dlgFOpen.DoModal() == IDOK) {
		//	CSfilePath = dlgFOpen.GetPathName();
		CFile* tscFile = ar.GetFile();
		strcpy(LpName, LPCSTR(tscFile->GetFilePath().Left(tscFile->GetFilePath().GetLength() - 4)));
		DeleteFile(LPCTSTR(CString(LpName) + ".tst"));
		DeleteFile(LPCTSTR(CString(LpName) + ".tsd"));
		DeleteFile(LPCTSTR(CString(LpName) + ".pte"));
		DeleteFile(LPCTSTR(CString(LpName) + ".fff"));
		open_tsc_error = Convertor();
		if (open_tsc_error == 0) {
			flagFileOpen = 1;
			ReadData();
			AfxGetApp()->m_pMainWnd->GetMenu()->EnableMenuItem(2, MF_BYPOSITION | MF_ENABLED);
			AfxGetApp()->m_pMainWnd->GetMenu()->EnableMenuItem(3, MF_BYPOSITION | MF_GRAYED);
			AfxGetApp()->m_pMainWnd->DrawMenuBar();

			//AfxGetApp()->m_pMainWnd->m_hWnd
			/*CToolBarCtrl* pToolBar=AfxGetApp()->m_pMainWnd
			//pToolBar->EnableButton(ID_TESTING_RM,false);
			pToolBar->HideButton(ID_TESTING_RM,false);
			pToolBar->HideButton(ID_TEST_FROM_FILE,false);
			pToolBar->HideButton(ID_VERMET,false);
			pToolBar->HideButton(ID_HAND_TEST,false);
			/*pToolBar->HideButton(ID_RESULT_PROTOKOL,true);
			pToolBar->HideButton(ID_RESULT_TEST,true);
			pToolBar->HideButton(ID_RESULT_FAULTS,true);
		*/

			message += "Файл " + tscFile->GetFileName() + " " + CString(errors[0]);
			MessageBox(NULL, message, "Открытие файла", MB_OK | MB_ICONINFORMATION);
		}
		else
			MessageBox(NULL, errors[open_tsc_error], "Ошибка " + CSfilePath, MB_OK | MB_ICONERROR);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CKSDoc diagnostics

#ifdef _DEBUG
void CKSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKSDoc commands

int Convertor()
{
	int boom = 0;
	int* pel, * uzlel, * puzl;
	int  swinf[4];
	int i1;
	int  i, k, i2, t, j, vs, sum = 0, sum1 = 0;
	unsigned short* tt, c14 = 0x7FFF;
	static int c11[32] = { 0x80000000,0xC0000000,0xE0000000,0xF0000000,
						0xF8000000,0xFC000000,0xFE000000,0xFF000000,
						0xFF800000,0xFFC00000,0xFFE00000,0xFFF00000,
						0xFFF80000,0xFFFC0000,0xFFFE0000,0xFFFF0000,
						0xFFFF8000,0xFFFFC000,0xFFFFE000,0xFFFFF000,
						0xFFFFF800,0xFFFFFC00,0xFFFFFE00,0xFFFFFF00,
						0xFFFFFF80,0xFFFFFFC0,0xFFFFFFE0,0xFFFFFFF0,
						0xFFFFFFF8,0xFFFFFFFC,0xFFFFFFFE,0xFFFFFFFF };


	mt_n = 0;

	if ((m11bib = new int[5000]) == NULL) return 4;
	if ((m12bib = new int[5000]) == NULL) return 4;
	if ((m2bib = new int[5000]) == NULL)  return 4;
	if ((sbib = new int[1000]) == NULL)   return 4;
	if ((mlbib = new int[1000]) == NULL)  return 4;
	if ((mnbib = new int[1000]) == NULL)  return 4;
	if ((mhbib = new int[1000]) == NULL)  return 4;
	if ((m11 = new int[9000]) == NULL)    return 4;
	if ((m12 = new int[9000]) == NULL)    return 4;
	if ((m2 = new int[9000]) == NULL)     return 4;

	//  Обнуление элементов массивов
	for (i = 0; i < 5000; i++) m11bib[i] = m12bib[i] = m2bib[i] = 0;
	for (i = 0; i < 9000; i++) m11[i] = m12[i] = m2[i] = 0;
	for (i = 0; i < 1000; i++) sbib[i] = mlbib[i] = mnbib[i] = mhbib[i] = 0;

	// Открываем файл с библиотекой элементов
	strcat(appDir, "\\biblel");
	if ((stream = fopen(appDir, "rt")) == NULL) return 1;
	appDir[strlen(appDir) - 6] = 0x00;
	do { ReadElement(stream); } while (!feof(stream));
	fclose(stream);

	strcat(LpName, ".tsc");
	if ((in_file = fopen(LpName, "rb")) == NULL) return 2;
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 

	fread(swinf, sizeof(int), 4, in_file);
	ns = (int)swinf[0];	// кол-во элементов в схеме
	nl = (int)swinf[1];	// кол-во узлов в схеме
	l = (int)swinf[2];	// кол-во пеpвичных входов
	n = (int)swinf[3];	// кол-во выходов и контp.точек
 // пропускаем 4 числа блока swinf =16 байт
	fseek(in_file, 16, SEEK_CUR);
	// считываем ТТ paзмером ns (ns*2 байт)
	if ((tt = new unsigned short[ns]) == NULL) return 4;
	//     for ( i=0; i<=ns-1; i++) tt[i]=0;// Очистка массива нулями
	fread(tt, 2, ns, in_file);
	for (i = 0; i < ns; i++)
		tt[i] &= c14;

	// считываем Puzl paзмером ns+1 ((ns+1)*4 байт)
	if ((puzl = new int[ns + 1]) == NULL) return 4;
	//     for ( i=0; i<=ns; i++) puzl[i]=0;// Очистка массива нулями
	fread(puzl, 4, ns + 1, in_file);
	if (((uzlel = new int[puzl[ns]])) == NULL) return 4;
	//   for ( i=0; i<=puzl[ns]-1; i++) uzlel[i]=0;// Очистка массива нулями
	fread(uzlel, 4, puzl[ns], in_file);
	for (i = 0; i < puzl[ns]; i++) uzlel[i]--;


	// пропускаем блок pel до последнего элемента
	fseek(in_file, nl * 4, SEEK_CUR);
	if ((pel = new int[4]) == NULL) return 4;
	//   for ( i=0; i<=3; i++) pel[i]=0;// Очистка массива нулями
	fread(pel, 4, 1, in_file);
	fseek(in_file, (*pel) * 4, SEEK_CUR);


	// считываем Nviuzl paзмером n
	if ((nvixc = new int[n]) == NULL) return 4;
	fread(nvixc, 4, n, in_file);
	for (i = 0; i < n; i++) nvixc[i]--;


	fclose(in_file);
	// ФОРМИРОВАНИЕ МАССИВОВ ДЛЯ ЭЛЕМЕНТОВ 1,2,3,4,5
	if ((sm = new int[ns]) == NULL) return 4;
	if ((ml = new int[ns]) == NULL) return 4;
	if ((mn = new int[ns]) == NULL) return 4;
	if ((mh = new int[ns]) == NULL) return 4;
	for (i = 0; i < ns; i++) sm[i] = ml[i] = mn[i] = mh[i] = 0;
	// фоpмиpование массивов m11,m12,m2,ml,mn,mh,sm
	i1 = 0;
	for (i = 0; i < ns; i++)
	{
		switch (tt[i])
		{
		case  1:  m11[i1] = 0;
			ml[i] = puzl[i + 1] - puzl[i] - 1;
			for (j = 0; j <= ml[i] - 1; j++)
				m11[i1] += Pow2(INT_SIZE - 1 - j);
			m12[i1] = 0;
			m2[i1] = HIGH_BIT;
			sm[i] = i1;
			mh[i] = 1;
			mn[i] = 1;
			i1++;
			break;
		case  2:
			ml[i] = puzl[i + 1] - puzl[i] - 1;
			sm[i] = i1;
			for (j = 0; j <= ml[i] - 1; j++)
			{
				m11[i1] = Pow2(INT_SIZE - 1 - j);
				m2[i1] = HIGH_BIT;
				m12[i1] = 0;
				i1++;
			}
			mn[i] = 1;
			mh[i] = ml[i];
			break;
		case 3:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
			ml[i] = 1;
			sm[i] = i1;
			m11[i1] = 0;
			m12[i1] = HIGH_BIT;
			m2[i1] = HIGH_BIT;
			mn[i] = 1;
			mh[i] = 1;
			i1++;
			break;
		case 4:
		case 6:
		case 7:
		case 8:
		case 16:
		case 17:
		case 25:
		case 26:
			ml[i] = puzl[i + 1] - puzl[i] - 1;
			sm[i] = i1;
			for (j = 0; j <= ml[i] - 1; j++)
			{
				m11[i1] = 0;
				m12[i1] = Pow2(INT_SIZE - 1 - j);
				m2[i1] = HIGH_BIT;
				i1++;
			}
			mn[i] = 1;
			mh[i] = ml[i];
			break;
		case 5:
		case 18:
		case 27:
		case 28:
		case 30:
			m12[i1] = 0;
			ml[i] = puzl[i + 1] - puzl[i] - 1;
			sm[i] = i1;
			for (j = 0; j < ml[i]; j++)
				m12[i1] += Pow2(INT_SIZE - 1 - j);
			m11[i1] = 0;
			m2[i1] = HIGH_BIT;
			mh[i] = 1;
			mn[i] = 1;
			i1++;
			break;
			// ДЛЯ ЭЛЕМЕНТОВ ИЗ БИБЛИОТЕКИ
		default:
			t = sbib[tt[i]];
			sm[i] = i1;
			for (j = 0; j < mhbib[tt[i]]; j++)
			{
				m11[i1] = m11bib[t];
				m12[i1] = m12bib[t];
				m2[i1] = m2bib[t];
				t++; i1++;
			}
			ml[i] = mlbib[tt[i]];
			mh[i] = mhbib[tt[i]];
			mn[i] = mnbib[tt[i]];
		} // switch
	};   // for
	// Резервирование памяти nvx,nvix,svx,svix...
	for (i = 0; i < ns; i++) sum += mn[i];
	for (i = 0; i < ns; i++) sum1 += ml[i];
	if ((nvix = new int[sum]) == NULL) return 4;
	if ((nvx = new int[sum1]) == NULL) return 4;
	if ((svx = new int[ns]) == NULL)   return 4;
	if ((svix = new int[ns]) == NULL)  return 4;
	// Обнуление элементов массива
	for (i = 0; i < sum; i++) nvix[i] = 0;
	for (i = 0; i < sum1; i++) nvx[i] = 0;
	for (i = 0; i < ns; i++) svix[i] = svx[i] = 0;
	// фоpмиpование svx- секционир. для nvx
	svx[0] = 0;
	for (i = 1; i < ns; i++) svx[i] = svx[i - 1] + ml[i - 1];
	// фоpмиpование масива svix- секционир. для nvix
	i1 = 0;
	for (i = 0; i < ns; i++)
	{
		svix[i] = i1;
		i1 += mn[i];// для многовыдных элементов
	}
	// фоpмиpование массива nvx-входы элементов nvix-выходы элементов
	j = t = i1 = vs = 0;
	for (i = 0; i < ns; i++)
	{
		for (t = 0; t < ml[i]; t++)	nvx[i1++] = uzlel[j++];
		for (t = 0; t < mn[i]; t++)	nvix[vs++] = uzlel[j++];
	}
	// Выполнение правильной нумерации элементов схемы
	sum = 0;
	for (i = 0; i < ns; i++) sum += mn[i];
	if ((nct = new int[sum + l + 1]) == NULL) return 4;
	if ((ctn = new int[sum + l + 1]) == NULL) return 4;
	if ((ncte = new int[ns + 1]) == NULL)   return 4;
	if ((ctne = new int[ns + 1]) == NULL)   return 4;
	//Обнуление элементов массива
	for (i = 0; i <= sum + l; i++) nct[i] = ctn[i] = 0;
	for (i = 0; i <= ns; i++) ctne[i] = ncte[i] = 0;
	for (i = 1; i <= l; i++) nct[i] = ctn[i] = i;
	for (i = l + 1; i <= (l + sum); i++) ctn[i] = 0;
	i1 = 0; i2 = l;
	while (i1 < ns)
	{
		for (i = 0; i < ns; i++)
		{
			t = 0;
			if (ctne[i + 1] == 0)
			{
				t = 0;
				for (k = 0; k < ml[i]; k++)
				{
					if (ctn[nvx[svx[i] + k]] == 0)
					{
						t = 1;
						break;
					}
				}
				if (t == 0)
				{
					i1++;
					ctne[i + 1] = i1;
					ncte[i1] = i + 1;
					for (j = 0; j < mn[i]; j++)
					{
						if (ctn[nvix[svix[i] + j]] == 0)
						{
							i2++;
							ctn[nvix[svix[i] + j]] = i2;
							nct[i2] = nvix[svix[i] + j];
						}
					}
				}
			}
		}
	}
	// фоpмиpование массива неиспpавностей cf
	if ((cf = new int[l + ns * 4]) == NULL)	return 4;
	nhcf = 0;

	for (i = 0; i < l; i++) cf[i] = c11[1];
	nhcf = 2 * l; //для подсчета к-ва неисправностей

	for (i = 0; i < ns; i++)
	{
		cf[l + i * 4] = cf[l + i * 4 + 1] = c11[ml[ncte[i + 1] - 1] - 1];
		//		   cf[l+i*4]=cf[l+i*4+1]=0;
		cf[l + i * 4 + 2] = cf[l + i * 4 + 3] = c11[mn[ncte[i + 1] - 1] - 1];
		nhcf += mn[ncte[i + 1] - 1] * 2;// подсчет к-ва неисправностей
		nhcf += ml[ncte[i + 1] - 1] * 2;
	}
	// запись выходных данных в файл 
	strcat(LpName, ".inf");
	if ((fptr = fopen(LpName, "w")) == NULL) return 25;
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
	fprintf(fptr, "%3d\n", l);
	fprintf(fptr, "%5d%5d\n", n, ns);
	i1 = 0;
	for (i = 0; i < ns; i++)
	{
		fprintf(fptr, "%4d\n", i1);
		i1 += mh[ncte[i + 1] - 1];
	}
	for (i = 0; i < ns; i++) fprintf(fptr, "%2d\n", ml[ncte[i + 1] - 1]);
	for (i = 0; i < ns; i++) fprintf(fptr, "%2d\n", mn[ncte[i + 1] - 1]);
	for (i = 0; i < ns; i++) fprintf(fptr, "%2d\n", mh[ncte[i + 1] - 1]);
	for (i = 0; i < ns; i++)
	{
		i1 = sm[ncte[i + 1] - 1];
		for (j = 0; j < mh[ncte[i + 1] - 1]; j++)
			fprintf(fptr, "%8x\n", m11[i1++]);
	}
	for (i = 0; i < ns; i++)
	{
		i1 = sm[ncte[i + 1] - 1];
		for (j = 0; j < mh[ncte[i + 1] - 1]; j++)
			fprintf(fptr, "%8x\n", m12[i1++]);
	}
	for (i = 0; i < ns; i++)
	{
		i1 = sm[ncte[i + 1] - 1];
		for (j = 0; j < mh[ncte[i + 1] - 1]; j++)
			fprintf(fptr, "%8x\n", m2[i1++]);
	}
	for (i = 0; i < ns; i++)
	{
		i1 = svx[ncte[i + 1] - 1];
		for (j = 0; j < ml[ncte[i + 1] - 1]; j++)
			fprintf(fptr, "%5d\n", ctn[nvx[i1++]]);
	}
	i1 = 0;

	for (i = 0; i < ns; i++)
	{
		fprintf(fptr, "%4d\n", i1);
		i1 += ml[ncte[i + 1] - 1];
	}
	for (i = 0; i < ns; i++)
	{
		i1 = svix[ncte[i + 1] - 1];
		for (j = 0; j < mn[ncte[i + 1] - 1]; j++)
			fprintf(fptr, "%5d\n", ctn[nvix[i1++]]);
	}
	i1 = 0;


	for (i = 0; i < ns; i++)
	{
		fprintf(fptr, "%4d\n", i1);
		i1 += mn[ncte[i + 1] - 1];
	}
	for (i = 0; i < n; i++)       fprintf(fptr, "%5d\n", ctn[nvixc[i]]);
	for (i = 0; i < (l + sum); i++) fprintf(fptr, "%5d\n", nct[i + 1]);
	for (i = 0; i < (l + sum); i++) fprintf(fptr, "%5d\n", ctn[i + 1]);
	for (i = 0; i < ns; i++)      fprintf(fptr, "%5d\n", ncte[i + 1]);
	for (i = 0; i < ns; i++)      fprintf(fptr, "%5d\n", ctne[i + 1]);
	fclose(fptr);
	//запись файла неисправностей 
	strcat(LpName, ".cff");
	if ((fcf = fopen(LpName, "wb")) == NULL) return 26;
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
	fwrite(&nhcf, sizeof(int), 1, fcf);
	fwrite(cf, sizeof(int), l + ns * 4, fcf);
	fclose(fcf);
	delete[] puzl;
	delete[] tt;
	delete[] pel;
	delete[] uzlel;
	delete[] m11bib;
	delete[] m12bib;
	delete[] m2bib;
	delete[] sbib;
	delete[] mhbib;
	delete[] mnbib;
	delete[] mlbib;
	return 0;
}

///////////////////

int Pow2(int st)
{
  return (st) ? 2*Pow2(st-1) : 1;
}
///////////////////////////////////////////////////////////////

void ReadElement(FILE* in_file)

{
	int i, j;
	char aCh[33];
	int n_el, n_in, n_out, n_h;
	int c12[32] = { 0x80000000,0x40000000,0x20000000,0x10000000,
				 0x8000000,0x4000000,0x2000000,0x1000000,
				 0x800000,0x400000,0x200000,0x100000,
				 0x80000,0x40000,0x20000,0x10000,
				 0x8000,0x4000,0x2000,0x1000,
				 0x800,0x400,0x200,0x100,
				 0x80,0x40,0x20,0x10,
				 0x8,0x4,0x2,0x1 };
	if (fscanf(in_file, "%d%d%d", &n_el, &n_in, &n_out) == EOF) return;
	if (fscanf(in_file, "%d", &n_h) == EOF) return;
	sbib[n_el] = mt_n;
	mlbib[n_el] = n_in;
	mnbib[n_el] = n_out;
	mhbib[n_el] = n_h;
	n_el = mt_n;
	///////////////////////////
	for (i = 0; i < n_h; i++)
	{
		if (fscanf(in_file, "%s", aCh) == EOF) return;
		for (j = 0; j < n_in; j++)
		{
			switch (aCh[j])
			{
			case '1':  m11bib[mt_n] |= c12[j];
				break;
			case '0':  m12bib[mt_n] |= c12[j];
				break;
			}
		}
		mt_n++;
	}
	////////////////////////////
	for (i = 0; i < n_h; i++)
	{
		if (fscanf(in_file, "%s", aCh) == EOF) return;
		for (j = 0; j < n_out; j++)
		{
			if (aCh[j] == '1')
				m2bib[n_el] |= c12[j];
		}
		n_el++;
	}
}

UINT Mainpr(LPVOID pParam)
{
	HWND hWnd = (HWND)pParam;
	extern UINT WM_MYUPDATE;

	int i1, j;

	/*  strcat(LpName,".inf");
	  if ((fptr = fopen(LpName,"r")) == NULL) return 17;
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	  fscanf(fptr,"%3d",&l);
	  fscanf(fptr,"%5d%5d",&n,&ns);

	  SendMessage(hWnd,WM_MYUPDATE,0,0);

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%4d",&sm[i]);
	  }

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%2d",&ml[i]);
	  }

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%2d",&mn[i]);
	  }

	  if((tst=new int[6000])==NULL) return 4;
	  for(i=0;i<6000;i++) tst[i]=0;
	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%2d",&mh[i]);
	  }

	  alt=0;
	  for(i=0;i<ns;i++)
	   alt+=mh[i];
	  for(i1=0,i=0;i<ns;i++)
	  for(j=0;j<mh[i];j++)
	  {
	   fscanf(fptr,"%8x",&m11[i1]);
	   i1++;
	  }

	  for(i1=0,i=0;i<ns;i++)
	  for(j=0;j<mh[i];j++)
	  {
	   fscanf(fptr,"%8x",&m12[i1]);
	   i1++;
	  }

	  for(i1=0,i=0;i<ns;i++)
	  for(j=0;j<mh[i];j++,i1++)
	  {
	   fscanf(fptr,"%8x",&m2[i1]);
	  }
	  i1=0;
	  for(i=0;i<ns;i++)
	   i1+=ml[i];

	  for(i1=0,i=0;i<ns;i++)
	  for(j=0;j<ml[i];j++,i1++)
	  {
	   fscanf(fptr,"%5d",&nvx[i1]);
	  }

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%4d",&svx[i]);
	  }

	  i1=0;
	  for(i=0;i<ns;i++)
		i1+=mn[i];
	  for(i=i1=0;i<ns;i++)
	  for(j=0;j<mn[i];j++,i1++)
	  {
	   fscanf(fptr,"%5d",&nvix[i1]);
	  }

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%4d",&svix[i]);
	  }

	  for(i=0;i<n;i++)
	  {
	   fscanf(fptr,"%5d",&nvixc[i]);
	  }

	  i1=l+1;
	  for(i=0;i<ns;i++)
		i1+=mn[i];
	  for(i=0;i<i1;i++)
		  nct[i]=0;
	  for(i=0;i<(i1-1);i++)
		fscanf(fptr,"%5d",&nct[i+1]);

	  for(i=0;i<(i1-1);i++)
		fscanf(fptr,"%5d",&ctn[i+1]);

	  for(i=0;i<ns;i++)
		fscanf(fptr,"%5d",&ncte[i+1]);

	  for(i=0;i<ns;i++)
		fscanf(fptr,"%5d",&ctne[i+1]);

	  fclose(fptr);

	 for(i=0;i<6000;i++)
		tst[i]=0;

	   strcat( LpName, ".tst");
	   if ((fptr = fopen(LpName,"rb")) == NULL)
	   {
		tst[0]=nt=0;
	   }
	   else
	   {
		SendMessage(hWnd,WM_MYUPDATE,1,0);
		i1=l/32+n/32;
		if((j=l%32)!=0)i1++;
		if((j=n%32)!=0)i1++;
		fread(tst,sizeof(int),1,fptr);
		nt=tst[0];
		fread(&tst[1],sizeof(int),nt*i1,fptr);
		fclose(fptr);
	   }
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	  // Ввод списка неисправностей cf
	  strcat( LpName, ".cff");
	  if ((fptr = fopen(LpName,"rb")) == NULL) return 13;//Невозможно открыть файл со списком неисправностей
	  SendMessage(hWnd,WM_MYUPDATE,2,0);
	  fread(&nhcf,sizeof(int),1,fptr);
	  fread(cf,sizeof(int),l+ns*4,fptr);
	  fclose(fptr);
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	  nhcf1=nhcf;
	  // Ввод идентификаторов линий схемы
	  strcat( LpName, ".pnt");
	  if ((fptr = fopen(LpName,"rb")) == NULL) return 14;//Невозможно открыть файл типа .pnt
	  SendMessage(hWnd,WM_MYUPDATE,3,0);
	  i1=l+3;
	  for(i=0;i<ns;i++)
		i1+=mn[i];
	  fread(PointIdent,4,i1,fptr);
	  fclose(fptr);
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	  strcat( LpName, ".idn");
	  if ((fptr = fopen(LpName,"rb")) == NULL) return 14;//Невозможно открыть файл типа .idn
	  fread(Ident,sizeof(char),PointIdent[i1-1],fptr);
	  fclose(fptr);
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	  SendMessage(hWnd,WM_MYUPDATE,4,0);*/
	modcx(hWnd);
	strcat(LpName, ".tst");
	if ((in_file = fopen(LpName, "wb")) == NULL)
		MessageBox(NULL, "Невозможно открыть файл с тестом", "Ошибка ", MB_OK | MB_ICONERROR);//файл с тестом
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
	i1 = l / 32 + n / 32;
	if ((j = l % 32) != 0)i1++;
	if ((j = n % 32) != 0)i1++;
	fwrite(tst, sizeof(int), tst[0] * i1 + 1, in_file);
	fclose(in_file);
	strcat(LpName, ".cff");
	if ((in_file = fopen(LpName, "wb")) == NULL)
		MessageBox(NULL, "Невозможно открыть файл .cff", "Ошибка ", MB_OK | MB_ICONERROR);//файл с неисправностями	 
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
	fwrite(&nhcf1, sizeof(int), 2, in_file);
	fwrite(cf, sizeof(int), l + ns * 4, in_file);
	printcf();
	printtst();
	//   delete [] LpName;
   //  delete [] sm;
   //  delete [] mn;
   //	delete [] mh;
   //	delete [] ml;
   //	delete [] nvx;
   //	delete [] svx;
   //	delete [] svix;
   //	delete [] nvixc;
   //	delete [] cf;
   //	delete [] m11;
   //	delete [] m12;
   //	delete [] m2;
   //	delete [] ctn;
   //	delete [] nct;
   //	delete [] ncte;
   //	delete [] ctne;
   //	delete [] tst; 
	SendMessage(hWnd, WM_MYUPDATE, 5, 0);
	return 0;
}

void CKSDoc::OnTestingRm()
{
	// TODO: Add your command handler code here
	CPrDlg mydlg;
	//DeleteFile(LPCTSTR(CString(LpName)+".tst"));
	int extern nn, nh;
	//		nhcf=0;
	//		nhcf1=0;
	//		nn=0;
	//		nh=0;
	 //for(int i=0;i<6000;i++) tst[i]=0;
	// ReadData();
	mydlg.m_nn = nn;
	mydlg.DoModal();
}

void CKSDoc::OnTexnologi()
{
	// TODO: Add your command handler code here
	CVermetDlg VermetDlg;
	if (VermetDlg.DoModal() == IDOK) SaveData();
	//SaveData();
	//vermet(3,4,5);

}

void CKSDoc::OnHandTest()
{
	// TODO: Add your command handler code here
	CStdioFile ProtFile(CString(LpName) + ".pte", CFile::modeWrite | CFile::modeNoTruncate | CFile::modeCreate);
	ProtFile.SeekToEnd();
	ProtFile.WriteString("********************************************************************");
	ProtFile.WriteString("\n ***    Результаты ввода теста вручную    ****");
	ProtFile.WriteString("\n********************************************************************\n");
	ProtFile.Close();

	int i1, j;

	/*  strcat(LpName,".inf");
	  if ((fptr = fopen(LpName,"r")) == NULL) return;
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	  fscanf(fptr,"%3d",&l);
	  fscanf(fptr,"%5d%5d",&n,&ns);

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%4d",&sm[i]);
	  }

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%2d",&ml[i]);
	  }

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%2d",&mn[i]);
	  }

	  if((tst=new int[6000])==NULL) return;
	  for(i=0;i<6000;i++) tst[i]=0;
	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%2d",&mh[i]);
	  }

	  alt=0;
	  for(i=0;i<ns;i++)
	   alt+=mh[i];
	  for(i1=0,i=0;i<ns;i++)
	  for(j=0;j<mh[i];j++)
	  {
	   fscanf(fptr,"%8x",&m11[i1]);
	   i1++;
	  }

	  for(i1=0,i=0;i<ns;i++)
	  for(j=0;j<mh[i];j++)
	  {
	   fscanf(fptr,"%8x",&m12[i1]);
	   i1++;
	  }

	  for(i1=0,i=0;i<ns;i++)
	  for(j=0;j<mh[i];j++,i1++)
	  {
	   fscanf(fptr,"%8x",&m2[i1]);
	  }
	  i1=0;
	  for(i=0;i<ns;i++)
	   i1+=ml[i];

	  for(i1=0,i=0;i<ns;i++)
	  for(j=0;j<ml[i];j++,i1++)
	  {
	   fscanf(fptr,"%5d",&nvx[i1]);
	  }

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%4d",&svx[i]);
	  }

	  i1=0;
	  for(i=0;i<ns;i++)
		i1+=mn[i];
	  for(i=i1=0;i<ns;i++)
	  for(j=0;j<mn[i];j++,i1++)
	  {
	   fscanf(fptr,"%5d",&nvix[i1]);
	  }

	  for(i=0;i<ns;i++)
	  {
	   fscanf(fptr,"%4d",&svix[i]);
	  }

	  for(i=0;i<n;i++)
	  {
	   fscanf(fptr,"%5d",&nvixc[i]);
	  }

	  i1=l+1;
	  for(i=0;i<ns;i++)
		i1+=mn[i];
	  for(i=0;i<i1;i++)
		  nct[i]=0;
	  for(i=0;i<(i1-1);i++)
		fscanf(fptr,"%5d",&nct[i+1]);

	  for(i=0;i<(i1-1);i++)
		fscanf(fptr,"%5d",&ctn[i+1]);

	  for(i=0;i<ns;i++)
		fscanf(fptr,"%5d",&ncte[i+1]);

	  for(i=0;i<ns;i++)
		fscanf(fptr,"%5d",&ctne[i+1]);

	  fclose(fptr);

	 for(i=0;i<6000;i++)
		tst[i]=0;

	   strcat( LpName, ".tst");
	   if ((fptr = fopen(LpName,"rb")) == NULL)
	   {
		tst[0]=nt=0;
	   }
	   else
	   {
		i1=l/32+n/32;
		if((j=l%32)!=0)i1++;
		if((j=n%32)!=0)i1++;
		fread(tst,sizeof(int),1,fptr);
		nt=tst[0];
		fread(&tst[1],sizeof(int),nt*i1,fptr);
		fclose(fptr);
	   }
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	  // Ввод списка неисправностей cf
	  strcat( LpName, ".cff");
	  if ((fptr = fopen(LpName,"rb")) == NULL) return;//Невозможно открыть файл со списком неисправностей
	  fread(&nhcf,sizeof(int),1,fptr);
	  fread(cf,sizeof(int),l+ns*4,fptr);
	  fclose(fptr);
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	  nhcf1=nhcf;
	  // Ввод идентификаторов линий схемы
	  strcat( LpName, ".pnt");
	  if ((fptr = fopen(LpName,"rb")) == NULL) return;//Невозможно открыть файл типа .pnt
	  i1=l+3;
	  for(i=0;i<ns;i++)
		i1+=mn[i];
	  fread(PointIdent,4,i1,fptr);
	  fclose(fptr);
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	  strcat( LpName, ".idn");
	  if ((fptr = fopen(LpName,"rb")) == NULL) return;//Невозможно открыть файл типа .idn
	  fread(Ident,sizeof(char),PointIdent[i1-1],fptr);
	  fclose(fptr);
	  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
	*/
	CHandTestDlg HandTestDlg;
	if (HandTestDlg.DoModal() == IDOK)
	{
		strcat(LpName, ".tst");
		if ((in_file = fopen(LpName, "wb")) == NULL)
			MessageBox(NULL, "Невозможно открыть файл с тестом", "Ошибка ", MB_OK | MB_ICONERROR);//файл с тестом
		LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
		i1 = l / 32 + n / 32;
		if ((j = l % 32) != 0)i1++;
		if ((j = n % 32) != 0)i1++;
		fwrite(tst, sizeof(int), tst[0] * i1 + 1, in_file);
		fclose(in_file);
		strcat(LpName, ".cff");
		if ((in_file = fopen(LpName, "wb")) == NULL)
			MessageBox(NULL, "Невозможно открыть файл .cff", "Ошибка ", MB_OK | MB_ICONERROR);//файл с неисправностями	 
		LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
		fwrite(&nhcf1, sizeof(int), 2, in_file);
		fwrite(cf, sizeof(int), l + ns * 4, in_file);
		printcf();
		printtst();
		CKSApp* pApp = (CKSApp*)AfxGetApp();
		pApp->EnableMenu();
	}

}

void CKSDoc::OnTestFromFile()
{
	// TODO: Add your command handler code here

	CString Pat, fName;
	extern char* fa;
	extern int l;




	TCHAR title[] = "Открыть файл c тестом";

	CFileDialog dlgFOpen(TRUE);
	CString filterStr("Все файлы (*.*)"); filterStr += (TCHAR)NULL;
	filterStr += "*.*"; filterStr += (TCHAR)NULL;
	filterStr += ("Файл теста схемы (*.pat)"); filterStr += (TCHAR)NULL;
	filterStr += "*.pat"; filterStr += (TCHAR)NULL;

	dlgFOpen.m_ofn.lpstrFilter = filterStr;
	dlgFOpen.m_ofn.nFilterIndex = 2;

	TCHAR strFileName[_MAX_PATH];

	strFileName[0] = (TCHAR)NULL;
	dlgFOpen.m_ofn.lpstrFile = strFileName;


	dlgFOpen.m_ofn.lpstrInitialDir = (LPCTSTR)GetPathName();

	dlgFOpen.m_ofn.lpstrTitle = title;

	if (dlgFOpen.DoModal() == IDOK) {
		fName = dlgFOpen.GetPathName();

		int j;
		int i1;


		/*  strcat(LpName,".inf");
		  if ((fptr = fopen(LpName,"r")) == NULL) return;
		  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
		  fscanf(fptr,"%3d",&l);
		  fscanf(fptr,"%5d%5d",&n,&ns);

		  for(i=0;i<ns;i++)
		  {
		   fscanf(fptr,"%4d",&sm[i]);
		  }

		  for(i=0;i<ns;i++)
		  {
		   fscanf(fptr,"%2d",&ml[i]);
		  }

		  for(i=0;i<ns;i++)
		  {
		   fscanf(fptr,"%2d",&mn[i]);
		  }

		  if((tst=new int[6000])==NULL) return;
		  for(i=0;i<6000;i++) tst[i]=0;
		  for(i=0;i<ns;i++)
		  {
		   fscanf(fptr,"%2d",&mh[i]);
		  }

		  alt=0;
		  for(i=0;i<ns;i++)
		   alt+=mh[i];
		  for(i1=0,i=0;i<ns;i++)
		  for(j=0;j<mh[i];j++)
		  {
		   fscanf(fptr,"%8x",&m11[i1]);
		   i1++;
		  }

		  for(i1=0,i=0;i<ns;i++)
		  for(j=0;j<mh[i];j++)
		  {
		   fscanf(fptr,"%8x",&m12[i1]);
		   i1++;
		  }

		  for(i1=0,i=0;i<ns;i++)
		  for(j=0;j<mh[i];j++,i1++)
		  {
		   fscanf(fptr,"%8x",&m2[i1]);
		  }
		  i1=0;
		  for(i=0;i<ns;i++)
		   i1+=ml[i];

		  for(i1=0,i=0;i<ns;i++)
		  for(j=0;j<ml[i];j++,i1++)
		  {
		   fscanf(fptr,"%5d",&nvx[i1]);
		  }

		  for(i=0;i<ns;i++)
		  {
		   fscanf(fptr,"%4d",&svx[i]);
		  }

		  i1=0;
		  for(i=0;i<ns;i++)
			i1+=mn[i];
		  for(i=i1=0;i<ns;i++)
		  for(j=0;j<mn[i];j++,i1++)
		  {
		   fscanf(fptr,"%5d",&nvix[i1]);
		  }

		  for(i=0;i<ns;i++)
		  {
		   fscanf(fptr,"%4d",&svix[i]);
		  }

		  for(i=0;i<n;i++)
		  {
		   fscanf(fptr,"%5d",&nvixc[i]);
		  }

		  i1=l+1;
		  for(i=0;i<ns;i++)
			i1+=mn[i];
		  for(i=0;i<i1;i++)
			  nct[i]=0;
		  for(i=0;i<(i1-1);i++)
			fscanf(fptr,"%5d",&nct[i+1]);

		  for(i=0;i<(i1-1);i++)
			fscanf(fptr,"%5d",&ctn[i+1]);

		  for(i=0;i<ns;i++)
			fscanf(fptr,"%5d",&ncte[i+1]);

		  for(i=0;i<ns;i++)
			fscanf(fptr,"%5d",&ctne[i+1]);

		  fclose(fptr);

		 for(i=0;i<6000;i++)
			tst[i]=0;

		   strcat( LpName, ".tst");
		   if ((fptr = fopen(LpName,"rb")) == NULL)
		   {
			tst[0]=nt=0;
		   }
		   else
		   {
			i1=l/32+n/32;
			if((j=l%32)!=0)i1++;
			if((j=n%32)!=0)i1++;
			fread(tst,sizeof(int),1,fptr);
			nt=tst[0];
			fread(&tst[1],sizeof(int),nt*i1,fptr);
			fclose(fptr);
		   }
		  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
		  // Ввод списка неисправностей cf
		  strcat( LpName, ".cff");
		  if ((fptr = fopen(LpName,"rb")) == NULL) return;//Невозможно открыть файл со списком неисправностей
		  fread(&nhcf,sizeof(int),1,fptr);
		  fread(cf,sizeof(int),l+ns*4,fptr);
		  fclose(fptr);
		  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
		  nhcf1=nhcf;
		  // Ввод идентификаторов линий схемы
		  strcat( LpName, ".pnt");
		  if ((fptr = fopen(LpName,"rb")) == NULL) return;//Невозможно открыть файл типа .pnt
		  i1=l+3;
		  for(i=0;i<ns;i++)
			i1+=mn[i];
		  fread(PointIdent,4,i1,fptr);
		  fclose(fptr);
		  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
		  strcat( LpName, ".idn");
		  if ((fptr = fopen(LpName,"rb")) == NULL) return;//Невозможно открыть файл типа .idn
		  fread(Ident,sizeof(char),PointIdent[i1-1],fptr);
		  fclose(fptr);
		  LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
		*/
		//MPStruct m;
	   // m.st=fName;
	   // FromFile(&m);
		CAllPrDlg dlg;
		dlg.Flag = 0;
		dlg.m_FileName = fName;

		CStdioFile ProtFile(CString(LpName) + ".pte", CFile::modeWrite | CFile::modeNoTruncate | CFile::modeCreate);
		ProtFile.SeekToEnd();
		ProtFile.WriteString("\n********************************************************************");
		ProtFile.WriteString("\n ***    Результаты ввода теста из файла " + fName);
		ProtFile.WriteString("\n********************************************************************\n");
		ProtFile.WriteString("\n");
		ProtFile.Close();

		dlg.DoModal();
		/*fa=new char[l+1];
		CStdioFile PatFile(LPCTSTR(fName),CFile::modeRead);
		while(PatFile.ReadString(Pat)){
			  if(Pat.GetLength()<l)
				  MessageBox(NULL, "Неверная длина набора. Набор будет пропущен.", "Ошибка " , MB_OK | MB_ICONERROR);
			  else {
				 fa[0]='0';
				 fa[1]=0;
				 strcat(fa, (const char*)LPCSTR(Pat));
				 anal(NULL);
			  }
			  }
		  PatFile.Close();*/
		strcat(LpName, ".tst");
		if ((in_file = fopen(LpName, "wb")) == NULL)
			MessageBox(NULL, "Невозможно открыть файл с тестом", "Ошибка ", MB_OK | MB_ICONERROR);//файл с тестом
		LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
		i1 = l / 32 + n / 32;
		if ((j = l % 32) != 0)i1++;
		if ((j = n % 32) != 0)i1++;
		fwrite(tst, sizeof(int), tst[0] * i1 + 1, in_file);
		fclose(in_file);
		strcat(LpName, ".cff");
		if ((in_file = fopen(LpName, "wb")) == NULL)
			MessageBox(NULL, "Невозможно открыть файл .cff", "Ошибка ", MB_OK | MB_ICONERROR);//файл с неисправностями	 
		LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
		fwrite(&nhcf1, sizeof(int), 2, in_file);
		fwrite(cf, sizeof(int), l + ns * 4, in_file);
		printcf();
		printtst();

		CKSApp* pApp = (CKSApp*)AfxGetApp();
		pApp->EnableMenu();
	}
}

void ClearArrays() {
	extern int nn, nh;
	delete[] sm;
	delete[] mn;
	delete[] mh;
	delete[] ml;
	delete[] nvx;
	delete[] svx;
	delete[] svix;
	delete[] nvixc;
	delete[] cf;
	delete[] m11;
	delete[] m12;
	delete[] m2;
	delete[] ctn;
	delete[] nct;
	delete[] ncte;
	delete[] ctne;
	delete[] tst;
	nhcf = 0;
	nhcf1 = 0;
	nn = 0;
	nh = 0;
}


int CKSDoc::ReadData()
{
	int alt;
	int j, i;
	int i1;
	FILE* fptr;

	strcat(LpName, ".inf");
	if ((fptr = fopen(LpName, "r")) == NULL) return 1;
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
	fscanf(fptr, "%3d", &l);
	fscanf(fptr, "%5d%5d", &n, &ns);

	for (i = 0; i < ns; i++)
	{
		fscanf(fptr, "%4d", &sm[i]);
	}

	for (i = 0; i < ns; i++)
	{
		fscanf(fptr, "%2d", &ml[i]);
	}

	for (i = 0; i < ns; i++)
	{
		fscanf(fptr, "%2d", &mn[i]);
	}

	if ((tst = new int[6000]) == NULL) return 1;
	for (i = 0; i < 6000; i++) tst[i] = 0;
	for (i = 0; i < ns; i++)
	{
		fscanf(fptr, "%2d", &mh[i]);
	}

	alt = 0;
	for (i = 0; i < ns; i++)
		alt += mh[i];
	for (i1 = 0, i = 0; i < ns; i++)
		for (j = 0; j < mh[i]; j++)
		{
			fscanf(fptr, "%8x", &m11[i1]);
			i1++;
		}

	for (i1 = 0, i = 0; i < ns; i++)
		for (j = 0; j < mh[i]; j++)
		{
			fscanf(fptr, "%8x", &m12[i1]);
			i1++;
		}

	for (i1 = 0, i = 0; i < ns; i++)
		for (j = 0; j < mh[i]; j++, i1++)
		{
			fscanf(fptr, "%8x", &m2[i1]);
		}
	i1 = 0;
	for (i = 0; i < ns; i++)
		i1 += ml[i];

	for (i1 = 0, i = 0; i < ns; i++)
		for (j = 0; j < ml[i]; j++, i1++)
		{
			fscanf(fptr, "%5d", &nvx[i1]);
		}

	for (i = 0; i < ns; i++)
	{
		fscanf(fptr, "%4d", &svx[i]);
	}

	i1 = 0;
	for (i = 0; i < ns; i++)
		i1 += mn[i];
	for (i = i1 = 0; i < ns; i++)
		for (j = 0; j < mn[i]; j++, i1++)
		{
			fscanf(fptr, "%5d", &nvix[i1]);
		}

	for (i = 0; i < ns; i++)
	{
		fscanf(fptr, "%4d", &svix[i]);
	}

	for (i = 0; i < n; i++)
	{
		fscanf(fptr, "%5d", &nvixc[i]);
	}

	i1 = l + 1;
	for (i = 0; i < ns; i++)
		i1 += mn[i];
	for (i = 0; i < i1; i++)
		nct[i] = 0;
	for (i = 0; i < (i1 - 1); i++)
		fscanf(fptr, "%5d", &nct[i + 1]);

	for (i = 0; i < (i1 - 1); i++)
		fscanf(fptr, "%5d", &ctn[i + 1]);

	for (i = 0; i < ns; i++)
		fscanf(fptr, "%5d", &ncte[i + 1]);

	for (i = 0; i < ns; i++)
		fscanf(fptr, "%5d", &ctne[i + 1]);

	fclose(fptr);

	for (i = 0; i < 6000; i++)
		tst[i] = 0;

	strcat(LpName, ".tst");
	if ((fptr = fopen(LpName, "rb")) == NULL)
	{
		tst[0] = nt = 0;
	}
	else
	{
		i1 = l / 32 + n / 32;
		if ((j = l % 32) != 0)i1++;
		if ((j = n % 32) != 0)i1++;
		fread(tst, sizeof(int), 1, fptr);
		nt = tst[0];
		fread(&tst[1], sizeof(int), nt * i1, fptr);
		fclose(fptr);
	}

	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
	// Ввод списка неисправностей cf 
	strcat(LpName, ".cff");
	if ((fptr = fopen(LpName, "rb")) == NULL) return 1;//Невозможно открыть файл со списком неисправностей
	fread(&nhcf, sizeof(int), 1, fptr);
	fread(cf, sizeof(int), l + ns * 4, fptr);
	fclose(fptr);
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
	nhcf1 = nhcf;
	// Ввод идентификаторов линий схемы 
	strcat(LpName, ".pnt");
	if ((fptr = fopen(LpName, "rb")) == NULL) return 1;//Невозможно открыть файл типа .pnt
	i1 = l + 3;
	for (i = 0; i < ns; i++)
		i1 += mn[i];
	fread(PointIdent, 4, i1, fptr);
	fclose(fptr);
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
	strcat(LpName, ".idn");
	if ((fptr = fopen(LpName, "rb")) == NULL) return 1;//Невозможно открыть файл типа .idn
	fread(Ident, sizeof(char), PointIdent[i1 - 1], fptr);
	fclose(fptr);
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 	
	return 0;
}

void CKSDoc::SaveData()
{
 int i1,j;
 strcat( LpName, ".tst");
 if((in_file=fopen(LpName,"wb"))==NULL) 
 MessageBox(NULL, "Невозможно открыть файл с тестом", "Ошибка " , MB_OK | MB_ICONERROR);//файл с тестом
 LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения 
 i1=l/32+n/32;
 if((j=l%32)!=0)i1++;
 if((j=n%32)!=0)i1++;
 fwrite(tst, sizeof(int),tst[0]*i1+1,in_file);
 fclose(in_file);
 strcat( LpName, ".cff");
 if((in_file=fopen(LpName,"wb"))==NULL)
 MessageBox(NULL, "Невозможно открыть файл .cff", "Ошибка " , MB_OK | MB_ICONERROR);//файл с неисправностями	 
 LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения 
 fwrite(&nhcf1,sizeof(int),2,in_file);
 fwrite(cf,sizeof(int),l+ns*4,in_file);
 printcf(); 
 printtst();
}

void CKSDoc::OnVermet() 
{
	// TODO: Add your command handler code here
  CStdioFile ProtFile(CString(LpName)+".pte",CFile::modeWrite|CFile::modeNoTruncate|CFile::modeCreate);
  ProtFile.SeekToEnd();
  ProtFile.WriteString("\n********************************************************************");
  ProtFile.WriteString("\n ***    Результаты генерации теста вероятностным методом    ****");
  ProtFile.WriteString("\n********************************************************************\n");
  ProtFile.WriteString("\n");
  ProtFile.Close();

 CVermetDlg VermetDlg;
 if(VermetDlg.DoModal()==IDOK) SaveData();
	
}

UINT FromFile(LPVOID pParam){
  extern int l;
  MPStruct *mps=(MPStruct*)pParam;
  
  CStringArray PatArray;
  CString Pat;
  CStdioFile PatFile(mps->st,CFile::modeRead);


  while(PatFile.ReadString(Pat)){
	  if(Pat.GetLength()!=l)
        SendMessage(mps->hw,mps->M.GetAt(0),4,0);
	  else
	    PatArray.Add(Pat);
	}
  PatFile.Close();
  if(PatArray.GetSize()==0){
	  SendMessage(mps->hw,mps->M.GetAt(0),0,0);
	  return 0;
  }
  fa=new char[l+1];
  SendMessage(mps->hw,mps->M.GetAt(0),1,PatArray.GetSize());
  
  for(int i=0;i<PatArray.GetSize();i++)
 	if(PatArray.GetAt(i).GetLength()<l)
			MessageBox(NULL, "Неверная длина набора. Набор будет пропущен.", "Ошибка " , MB_OK | MB_ICONERROR);
		else {
		   fa[0]='0';
		   fa[1]=0;
		   strcat(fa, (const char*)LPCSTR(PatArray.GetAt(i)));
		   anal(NULL);
		   SendMessage(mps->hw,mps->M.GetAt(0),2,0);
		}
 SendMessage(mps->hw,mps->M.GetAt(0),3,0);
 return 1;
}
