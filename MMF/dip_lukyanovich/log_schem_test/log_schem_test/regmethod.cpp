// Построение модели исходной схемы, ориентированной на решение
// основных задач, возникающих при вычислении проверяющих
// наборов теста на основе регулярного метода
//////////////////////
#include "stdafx.h"
#include "regmethod.h"
#include "KSDoc.h"
#include "elements.h"
#include "anal.h"
#include "opacf.h"
//////////////////////
extern int g_NumFaults;
extern char *LpName;
extern int *m11,*m12,*m2,*sm,*ml,*mn,*mh,*nvx,*svx,*nvix,*svix,
           *nvixc,*cf,l,n,ns,nt,nhcf,nhcf1,*tst,*nct1,*ctn,*nct;

int *ba,*ma,*nlin,*bd;
int w,im,c,f1,v,s,nn;
extern FILE *fptr;
int *cn,*nc,*cokb;
int *mne,*okb,*vi,pc[25],*oid,*coid;
char *f,*fd;
extern char *fa;
int d;
int c1[32]={  0x80000000,0x40000000,0x20000000,0x10000000
	         ,0x08000000,0x04000000,0x02000000,0x01000000
	         ,0x00800000,0x00400000,0x00200000,0x00100000
	         ,0x00080000,0x00040000,0x00020000,0x00010000
		     ,0x00008000,0x00004000,0x00002000,0x00001000
	         ,0x00000800,0x00000400,0x00000200,0x00000100
	         ,0x00000080,0x00000040,0x00000020,0x00000010
	         ,0x00000008,0x00000004,0x00000002,0x00000001};
int modcx(HWND hWnd)
{
    int nipla[64], nppla[48], nct[48], iokb, neb, is, npla, ioid, ioid1;
    int s, q, t, i, i1, j1, k/*,k1,i2,i5,i11*/, j;

    i1 = l + 1;
    for (i = 0; i < ns; i++)
        i1 += mn[i];

    if ((cn = new int[i1]) == NULL)	  return 4;
    if ((nc = new int[9000]) == NULL)   return 4;
    if ((cokb = new int[9000]) == NULL) return 4;
    if ((okb = new int[20000]) == NULL) return 4;
    if ((vi = new int[300]) == NULL)    return 4;
    if ((oid = new int[20000]) == NULL) return 4;
    if ((coid = new int[9000]) == NULL) return 4;
    if ((mne = new int[9000]) == NULL)  return 4;

    for (i = 0; i < i1; i++)
        cn[i] = 0;
    for (i = 0; i < 9000; i++)
        nc[i] = cokb[i] = coid[i] = mne[i] = 0;
    for (i = 0; i < 20000; i++)
        okb[i] = oid[i] = 0;
    for (i = 0; i < 300; i++)
        vi[i] = 0;
    // запись в файл
    strcat(LpName, ".pte");
    if ((fptr = fopen(LpName, "a")) == NULL) return 13;//файл отчёта
    LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
    fprintf(fptr, "РЕЗУЛЬТАТЫ ПОСТРОЕНИЯ ТЕСТА ДЛЯ СХЕМЫ\n");
    fprintf(fptr, "РЕГУЛЯРНЫМ МЕТОДОМ\n\n");
    for (int I = 0; I < l + 20; I++) fprintf(fptr, "*");
    fprintf(fptr, "*\n");
    fprintf(fptr, "l= %d, n= %d, ns= %d\n", l, n, ns);
    fclose(fptr);
    ///////
    //В данном месте кода программы должно находится описания 
    //сообщений о процессе генерации теста
    //
    ///////

    for (i = 0; i < 9000; i++)
        nc[i] = 0;
    // Построение массивов okb, cokb, mne, vi, pc, oid, coid, задающих 
    // описание логической сети, эквивалентной исходной схеме          
    for (i = 0; i <= l; i++)
    {
        cokb[i] = 0;
        nc[i] = i;
        cn[i] = i;
    }
    neb = l + 1;
    iokb = 0;

    for (npla = 0; npla < ns; npla++)
    {
        s = ml[npla];
        q = mh[npla];
        t = mn[npla];

        for (i = 0; i < s; i++)
        {
            nipla[2 * i] = cn[nvx[svx[npla] + i]];

            for (j = 0; j < q; j++)
            {
                if ((m12[sm[npla] + j] & c1[i]) != 0x00000000)
                {
                    okb[iokb] = neb;
                    okb[iokb + 1] = 3;
                    okb[iokb + 2] = 1;
                    okb[iokb + 3] = cn[nvx[svx[npla] + i]];
                    cokb[neb] = iokb;
                    iokb = iokb + 4;
                    nipla[2 * i + 1] = neb;
                    neb++;
                    j = q;
                }
            }
        }

        for (i = 0; i < q; i++)
        {
            is = 0;
            for (j = 0; j < s; j++)
            {
                if ((m11[sm[npla] + i] & c1[j]) != 0x00000000)
                {
                    nct[is] = nipla[2 * j];
                    is++;
                }
                if ((m12[sm[npla] + i] & c1[j]) != 0x00000000)
                {
                    nct[is] = nipla[2 * j + 1];
                    is++;
                }
            }
            if (is < 2)
                nppla[i] = nct[0];
            else
            {
                for (j = 0; j < is - 1; j++)
                {
                    okb[iokb] = neb;
                    okb[iokb + 1] = 1;
                    okb[iokb + 2] = 2;
                    okb[iokb + 3] = nct[j];
                    okb[iokb + 4] = nct[j + 1];
                    cokb[neb] = iokb;
                    iokb = iokb + 5;
                    nct[j + 1] = neb;
                    neb++;
                }
                nppla[i] = neb - 1;
            }
        }

        for (j = 0; j < t; j++)
        {
            is = 0;
            for (i = 0; i < q; i++)
            {
                if ((m2[sm[npla] + i] & c1[j]) != 0x00000000)
                {
                    nct[is] = nppla[i];
                    is++;
                }
            }

            if (is < 2)
            {
                cn[nvix[svix[npla] + j]] = nct[0];
                nc[nct[0]] = nvix[svix[npla] + j];

            }
            else
            {

                for (i = 0; i < is - 1; i++)
                {
                    okb[iokb] = neb;
                    okb[iokb + 1] = 2;
                    okb[iokb + 2] = 2;
                    okb[iokb + 3] = nct[i];
                    okb[iokb + 4] = nct[i + 1];
                    cokb[neb] = iokb;
                    iokb = iokb + 5;
                    nct[i + 1] = neb;
                    neb++;
                }
                cn[nvix[svix[npla] + j]] = neb - 1;
                nc[neb - 1] = nvix[svix[npla] + j];

            }

        }
    }

    neb--;

    pc[0] = nt;
    pc[5] = n;
    pc[6] = neb - l;
    pc[14] = l;
    for (i = 0; i < n; i++)
        vi[i] = cn[nvixc[i]];
    ioid = 0;
    for (i = 1; i <= neb; i++)
    {
        ioid1 = ioid + 2;
        coid[i] = ioid;
        oid[ioid] = i;
        oid[ioid + 1] = 0;
        if (i != neb)
        {
            if (i > l)
                i1 = i + 1;
            else
                i1 = l + 1;
            for (j = i1; j <= neb; j++)
            {
                k = okb[cokb[j] + 2];
                for (j1 = 0; j1 < k; j1++)
                {
                    if (i == okb[cokb[j] + 3 + j1])
                    {
                        oid[ioid + 1]++;
                        oid[ioid1] = j;
                        ioid1++;
                        j1 = k;
                    }
                }
            }
            ioid = ioid1;
        }
    }

    coid[neb + 1] = ioid1;


    // Построение списка неисправностей модели схемы соответствующего
    // списку неисправностей исходной схемы
    kodne();

    // Построение теста для заданного списка неисправностей
    regme(hWnd);

    // Вывод списка необнаруженных неисправностей
    /*
      strcat( LpName, ".pte");
      if((fptr=fopen(LpName,"a"))==NULL) return 18;//файл протокола
      LpName[strlen(LpName)-4] = 0x00;  // Удаление расширения
      k1=l;
      fprintf(fptr,"Необнаруженные неисправности\n");
      for(i1=1;i1<=l;i1=i1+10){
        if((i1+9)<=k1)
        i2=i1+9;
        else
        i2=k1;
        for(i5=i1;i5<=i2;i5++)
        fprintf(fptr,"%2d    ",i5);
        fprintf(fptr,"\n");
        for(i5=i1;i5<=i2;i5++)
        fprintf(fptr,"%4x  ",cf[i5-1]);
        fprintf(fptr,"\n");
        }
      k1=l+ns;
      for(i1=l+1;i1<=l+ns;i1=i1+10){
        if((i1+9)<=k1)
        i2=i1+9;
        else
        i2=k1;
        for(i5=i1;i5<=i2;i5++)
        fprintf(fptr,"%2d    ",nct1[i5]);
        fprintf(fptr,"\n");
        for(i=0;i<2;i++){
          i11=l+(i1-1-l)*4+2;
          for(i5=i1;i5<=i2;i5++){
        fprintf(fptr,"%4x  ",cf[i11+i]);
        i11=i11+4;
        }
          fprintf(fptr,"\n");

          }
        }   */
    delete[] mne;
    delete[] coid;
    delete[] oid;
    delete[] vi;
    delete[] okb;
    delete[] cokb;
    delete[] nc;
    delete[] cn;
    return 14;//тест построен
}

// Реализация направленного метода построения теста для заданного
// списка неисправностей логической сети 
int regme(HWND hWnd)
{
    int kc, i, r,/*d,*/p, iot, pr/*,j*/;
    static int con1[6] = { 0x00000001,0x00000002,0x00000004,0x00000008,0x00000010,0x00000020 };

    if ((ba = new int[pc[6] + l + 1]) == NULL)   return 4;
    if ((ma = new int[pc[6] + l + 1]) == NULL)   return 4;
    if ((nlin = new int[pc[6] + l + 1]) == NULL)   return 4;
    if ((bd = new int[pc[6] + l + 1]) == NULL)   return 4;
    if ((f = new char[pc[6] + l + 1]) == NULL)  return 4;
    if ((fa = new char[pc[6] + l + 1]) == NULL)  return 4;
    if ((fd = new char[pc[6] + l + 1]) == NULL)  return 4;
    for (i = 0; i <= (pc[6] + l); i++)
        ba[i] = ma[i] = nlin[i] = bd[i] = 0;

    strcat(LpName, ".pte");
    if ((fptr = fopen(LpName, "a")) == NULL) return 13;//файл отчёта
    LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
    iot = nn = 0;
    kc = l;
    for (i = 0; i < ns; i++)
        kc += mn[i];
    // Выбор очередной неисправности из масссива неисправностей
    im = 1;
me2:   if (im > (pc[6] + pc[14])) goto me28; // список исчерпан
    r = 0;
    if (im <= pc[14]) goto me25;  // неисправность на входе схемы
// выбирается неисправность логического элемента
    c = 1;
me3:   if ((mne[im - 1] & con1[c - 1]) == 0x00000000) goto me22;
    d = 1;
    if (okb[cokb[im] + 1] == 1) goto me11; // элемент типа И
    if (okb[cokb[im] + 1] == 2) goto me12; // элемент типа ИЛИ
    dknne();  // элемент типа НЕ
me4:   fprintf(fptr, "Связь %d, неисправность %d;\n", nct[nc[im]], c);
    /* Выход элемента является выходом логической сети ? */
    for (i = 0; i < pc[5]; i++)
    {
        if (im == vi[i]) goto me10;
    }
me6:   if (r == 1) goto me7; /* r=1 --> путь уже построен */
    p = 0;
    clput(); /* построение пути к выходам схемы */
    /* printf("Сложный путь \n"); */
    /* printf("%d %d %d %d %d %d %d %d %d %d \n",nc[nlin[0]],nc[nlin[1]], */
    /* nc[nlin[2]],nc[nlin[3]],nc[nlin[4]],nc[nlin[5]],nc[nlin[6]],        */
    /* nc[nlin[7]],nc[nlin[8]],nc[nlin[9]]);                              */
/* Вычисление условий образования активизированного пути */
me7:   r = 1;
    for (i = 0; i < (pc[6] + l + 1); i++) ma[i] = 0;
me8:   ucltr();
    iot++;
    if (s == 0) goto me13; /* ограничение перебора */
    if (iot == 100)
    {
        fprintf(fptr, "Ограничение перебора\n");
        goto me13;
    }
    if (v == 0) goto me16;  /* список для доопределения пуст */
/* Обеспечение условий образования активизированного пути */
me9:   opacf();
    if (s == 0) goto me19; /* возврат к поиску других условий акт. пути */
/* Вывод построенного теста */
me60:  fprintf(fptr, "Тест\n");
    /* for(i=1;i<=kc;i++)
       fprintf(fptr,"%c",fd[cn[ctn[i]]]);
       fprintf(fptr,"\n"); */
    iot = 0;
    pr = 0;
me46:  for (i = 1; i <= pc[14]; i++)
{
    if (fd[i] == '0') goto me91;
    if (fd[i] == '1') goto me92;
    if (fd[i] == 'D') goto me95;
    if (pr == 0) goto me91;
me92:    fa[i] = '1';
    continue;
me91:    fa[i] = '0';
    continue;
me95:    if (pr == 0) goto me92;
    goto me91;
}
fclose(fptr);
/* Вычисление множества неисправностей, проверяемых построенным */
/* тестом, и удаление их из списка неисправностей               */
anal(hWnd);
strcat(LpName, ".pte");
if ((fptr = fopen(LpName, "a")) == NULL) return 13;//файл отчёта
LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
kodne();
if ((im > pc[14]) || (pr == 1)) goto me74; /* выбор очередной неисправности */
pr = 1;
goto me46;
me74:  if (im <= pc[14]) goto me83;
goto me22;
/* Выход элемента является выходом сети --> путь активизирован */
me10:  p = 1;
for (i = 0; i <= (pc[6] + pc[14]); i++)
fa[i] = f[i];
v = w;
goto me9;
/* Построение D-куба неисправности для элемента типа И */
me11:  dkni();
goto me4;
/* Построение D-куба неисправности для элемента типа ИЛИ */
me12:  dknili();
goto me4;
me13:  fprintf(fptr, "Необнаружимая неисправность\n");
/* Переход к выбору очередной неисправности */
iot = 0;
if (im > pc[14]) goto me67;
im++;
goto me2;
me67:  if (okb[cokb[im] + 1] == 1) goto me15;
if (okb[cokb[im] + 1] == 3) goto me23;
if ((c > 1) || (d == 2)) goto me22;
d++;
goto me12;
me15:  if ((c != 2) || (d == 2)) goto me22;
d++;
goto me11;
me16:  if (p > 0) goto me18;
for (i = 0; i <= (pc[6] + pc[14]); i++)
fd[i] = fa[i];
goto me60;
/* me18:  for(i=1;i<=kc;i++)
       fprintf(fptr,"%c",f[cn[ctn[i]]]);
       fprintf(fptr,"\n"); */
me18:  goto me22;
me19:  if (p > 0) goto me13;
for (i = l + pc[6]; i > 0; i--)
{
    if (ma[i] == 1) goto me21;
    ma[i] = 0;
    continue;
me21:    ma[i] = 2;
    goto me8;
}
goto me13;
me22:  if (okb[cokb[im] + 1] == 3) goto me23;
if (c == 6) goto me24;
me79:  c++;
goto me3;
me23:  if (c < 4) goto me79;
me24:  im++;
goto me2;
me25:  if (((mne[im - 1] & con1[0]) != 0x00000000) || ((mne[im - 1] & con1[1]) != 0x00000000))
goto me82;
me83:  im++;
goto me2;
me82:  w = 0;
for (i = 1; i <= (pc[6] + pc[14]); i++)
f[i] = 'X';
f[im] = 'D';
fprintf(fptr, "Неисправность на %d входе\n", im);
goto me6;
me28:  fprintf(fptr, "Тест построен\n");
fclose(fptr);

delete[] fd;
delete[] fa;
delete[] f;
delete[] bd;
delete[] nlin;
delete[] ma;
delete[] ba;
return 14;
}

/* Построение списка неисправностей модели схемы, соответствующего */
/* списку неисправностей исходной схемы                            */
void kodne()
{
    int i, j;
    for (i = 0; i < 9000; i++)
        mne[i] = 0x00000000;
    /* Построение списка неисправностей на входах схемы */
    for (i = 0; i < l; i++)
    {
        if ((cf[i] & c1[0]) != 0x00000000)//0x0000
            mne[i] = mne[i] | c1[31];
        if ((cf[i] & c1[1]) != 0x00000000)
            mne[i] = mne[i] | c1[30];
    }
    /* Построение списка неисправностей логических элементов */
    for (i = 0; i < ns; i++)
    {
        for (j = 0; j < mn[i]; j++)
        {
            if ((cf[l + 4 * i + 2] & c1[j]) != 0x00000000)
                mne[cn[nvix[svix[i] + j]] - 1] = c1[31];
            if ((cf[l + 4 * i + 3] & c1[j]) != 0x0000)
                mne[cn[nvix[svix[i] + j]] - 1] = mne[cn[nvix[svix[i] + j]] - 1] | c1[30];
        }
    }
    /* printf("mne: %x %x %x %x %x %x %x %x %x %x %x %x\n",mne[0],mne[1], */
    /* mne[2],mne[3],mne[4],mne[5],mne[6],mne[7],mne[8],mne[9],mne[10],   */
    /* mne[11]); */
}

/* Построение сложного пути от места неисправности до выходов сети */
void clput()
{
  int i,j,k,n;
  nlin[0]=im;
  n=0;
  for(i=0;i<=n;i++)
  {
   if(oid[coid[nlin[i]]+1]!=0)
   {
    for(j=0;j<oid[coid[nlin[i]]+1];j++)
	{
	 for(k=0;k<=n;k++)
	 {
	  if(nlin[k]==oid[coid[nlin[i]]+2+j])
	  k=n+2;
	 }
	 if(k==(n+1))
	 nlin[++n]=oid[coid[nlin[i]]+2+j];
	}
   }
  }
  if(n>0)
  {
/* Упорядочение элементов пути в порядке возрастания номеров */
    for(i=0;i<n;i++)
	{
      for(j=i+1;j<=n;j++)
	  {
	   if(nlin[j]<nlin[i])
	   {
	    k=nlin[i];
	    nlin[i]=nlin[j];
	    nlin[j]=k;
	   }
	  }
	}
  }
}


/* Вычисление условий проявления неисправностей для элемента типа НЕ */
void dknne()
{
  int i;
  for(i=0;i<=(pc[14]+pc[6]);i++)
  f[i]='X';
/* Какая неисправность рассматривается */
  if((c==1)||(c==4))
/* Неисправность типа "константа 1" на входе или "константа 0" на выходе */
  {
   f[okb[cokb[im]+3]]='0';
   bd[0]=okb[cokb[im]+3];
   w=1;
   f[im]='D';
   return;
  }
 if((c==2)||(c==3))
/* Неисправность типа "константа 0" на входе или "константа 1" на выходе */
 {
  f[okb[cokb[im]+3]]='1';
  bd[0]=okb[cokb[im]+3];
  w=1;
  f[im]='B';
  return;
 }
  //printf("В программе dknne c!=1,2,3,4 \n");
}


/* Вычисление условий проявления неисправностей для элемента типа ИЛИ */
void dknili()
{
  int i;
  for(i=0;i<=(pc[14]+pc[6]);i++)
   f[i]='X';
  if(c==1)
/* Неисправность типа "константа 0" на выходе элемента */
  {
   if(d==1)
/* Выбор первого варианта условий проявления неисправности */
   {
    f[okb[cokb[im]+4]]='1';
    bd[0]=okb[cokb[im]+4];
    w=1;
    f[im]='D';
    return;
   }
   if(d==2)
/* Выбор второго варианта условий проявления неисправности */
   {
    f[okb[cokb[im]+3]]='1';
    bd[0]=okb[cokb[im]+3];
    w=1;
    f[im]='D';
    return;
   }
// printf("В программе dknili d != 1 и d != 2 \n");
   return;
  }
  if((c==2)||(c==4)||(c==6))
/* Неисправность типа "константа 1" на входах и выходе элемента */
  {
   f[okb[cokb[im]+3]]='0';
   f[okb[cokb[im]+4]]='0';
   bd[0]=okb[cokb[im]+3];
   bd[1]=okb[cokb[im]+4];
   w=2;
   f[im]='B';
   return;
  }
  if(c==3)
/* Неисправность типа "константа 0" на первом входе элемента */
  {
   f[okb[cokb[im]+3]]='1';
   f[okb[cokb[im]+4]]='0';
   bd[0]=okb[cokb[im]+3];
   bd[1]=okb[cokb[im]+4];
   w=2;
   f[im]='D';
   return;
  }
  if(c==5)
/* Неисправность типа "константа 0" на втором входе элемента */
  {
   f[okb[cokb[im]+3]]='0';
   f[okb[cokb[im]+4]]='1';
   bd[0]=okb[cokb[im]+3];
   bd[1]=okb[cokb[im]+4];
   w=2;
   f[im]='D';
   return;
  }
//  printf("В программе dknili c!=1,2,3,4,5,6 \n");
}


/* Вычисление условий проявления неисправностей для элемента типа И */
void dkni()
{
 int i;
 for(i=0;i<=(pc[14]+pc[6]);i++)
  f[i]='X';
/* Какая неисправность рассматривается ? */
 if((c==1)||(c==3)||(c==5))
/* Неисправность типа "константа 0" на входах или выходе элемента */
 {
  f[okb[cokb[im]+3]]='1';
  f[okb[cokb[im]+4]]='1';
  bd[0]=okb[cokb[im]+3];
  bd[1]=okb[cokb[im]+4];
  w=2;
  f[im]='D';
  return;
 }
 if(c==2)
/* Неисправность типа "константа 1" на выходе элемента */
 {
/* Выбор первого варианта условий проявления неисправности */
  if(d==1)
  {
   f[okb[cokb[im]+3]]='0';
   bd[0]=okb[cokb[im]+3];
   w=1;
   f[im]='B';
   return;
  }
  if(d==2)
/* Выбор второго варианта условий проявления неисправности */
  {
   f[okb[cokb[im]+4]]='0';
   bd[0]=okb[cokb[im]+4];
   w=1;
   f[im]='B';
   return;
  }
//    printf("In the programm DKNI d!=1 and d!=2 \n");
  return;
 }
 if(c==4)
/* Неисправность типа "константа 1" на первом входе элемента */
 {
  f[okb[cokb[im]+3]]='0';
  f[okb[cokb[im]+4]]='1';
  bd[0]=okb[cokb[im]+3];
  bd[1]=okb[cokb[im]+4];
  w=2;
  f[im]='B';
  return;
 }
 if(c==6)
/* Неисправность типа "константа 1" на втором входе элемента */
 {
  f[okb[cokb[im]+3]]='1';
  f[okb[cokb[im]+4]]='0';
  bd[0]=okb[cokb[im]+3];
  bd[1]=okb[cokb[im]+4];
  w=2;
  f[im]='B';
  return;
 }
//  printf("In the programm DKNI c!= 1,2,3,4,5,6 \n");
}













