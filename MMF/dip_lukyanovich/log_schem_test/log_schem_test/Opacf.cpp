/* ����������� ������� ����������� ������������� ���� */
#include "stdafx.h"
#include "opacf.h"
#include "regmethod.h"

 extern int *okb,*cokb,*bd,pc[],v,s;
 extern char *fa,*fd;
 int md[4000],bdr[4000],bdr1[4000];
  void opacf()
 {
  int i1,j1,pr;
int i,iot;
  iot=0;
  s=0; /* ��������� ��������� �������� ���������� ������� ������ */
  for(i=0;i<=(pc[6]+pc[14]);i++)
  {
   md[i]=0;
   bdr[i]=0;
  }
  for(i=0;i<v;i++)
   bdr[bd[i]]=bd[i];
  for(i=0;i<=(pc[6]+pc[14]);i++)
   bdr1[i]=bdr[i];

  m4: for(i=0;i<=(pc[6]+pc[14]);i++)
       fd[i]=fa[i];
       j1=0;
/* ����������� �������� �������� �� ������� ��������� �� ������ bdr1 */
      for(i1=pc[6]+pc[14];i1>pc[14];)
	  {
	   if(bdr1[i1]!=0) /* ����� �������� �� ������ bdr1 */
	   {
	    pr=0;
	    if(okb[cokb[i1]+1]==1)
/* ����������� ��������� �������� �� ������ �������� ���� � */
	     opfi(&i1,&j1,&pr);
	    else
	     if(okb[cokb[i1]+1]==2)
/* ����������� ��������� �������� �� ������ �������� ���� ��� */
		  opfil(&i1,&j1,&pr);
	     else
/* ����������� ��������� �������� �� ������ �������� ���� �� */
		  opfne(&i1,&j1,&pr);
	     if(pr==1)  /* ������� ����� */
		 {
		  iot++;
		  if(iot==100) return;
		  goto m4;
		 }
	     if(pr>1) return; /* ���������� ������� ����������� ������ */
	   }
	  else
	  i1--; /* ������� � ������ ���������� �������� */
	  }
    s=1; /* ������� ����������� ������������� ���� ���������� */
  }


/* ����������� ��������� �������� �� ������ �������� ���� � */
void opfi( int *i1,int *j1,int *pr)
{
      int i;
      if(fd[*i1]=='1') goto m15; /* �������� 1 �� ������ �������� */
/* ����������� �������� 0 �� ������ �������� */
/* ������ �������� �� ������ �������� */
      if(fd[okb[cokb[*i1]+3]]=='0') goto m6;
      if(fd[okb[cokb[*i1]+3]]=='1') goto m7;
      if(fd[okb[cokb[*i1]+4]]=='0') goto m3;
      if(fd[okb[cokb[*i1]+4]]=='1') goto m4;
      if(md[*j1]==0) goto m5; /* ����� ������� �������� ����������� */
      if(md[*j1]==1) goto m2; /* ����� ������� �������� ����������� */
      fd[okb[cokb[*i1]+4]]='0';
      *j1=*j1+1;
      *i1=*i1-1;
      if(okb[cokb[*i1+1]+4]>pc[14])
      bdr1[okb[cokb[*i1+1]+4]]=okb[cokb[*i1+1]+4];
      return;
  m2: fd[okb[cokb[*i1]+3]]='0';
      *j1=*j1+1;
      *i1=*i1-1;
      if(okb[cokb[*i1+1]+3]>pc[14])
      bdr1[okb[cokb[*i1+1]+3]]=okb[cokb[*i1+1]+3];
      return;
  m3: md[*j1]=2;
      *j1=*j1+1;
      *i1=*i1-1;
      return;
  m4: fd[okb[cokb[*i1]+3]]='0';
      md[*j1]=2;
      *j1=*j1+1;
      *i1=*i1-1;
      if(okb[cokb[*i1+1]+3]>pc[14])
      bdr1[okb[cokb[*i1+1]+3]]=okb[cokb[*i1+1]+3];
      return;
  m5: fd[okb[cokb[*i1]+3]]='0';
      md[*j1]=1;
      *j1=*j1+1;
      *i1=*i1-1;
      if(okb[cokb[*i1+1]+3]>pc[14])
      bdr1[okb[cokb[*i1+1]+3]]=okb[cokb[*i1+1]+3];
      return;
  m6: md[*j1]=2;
      *j1=*j1+1;
      *i1=*i1-1;
      return;
  m7: if(fd[okb[cokb[*i1]+4]]=='0')
	{
	  md[*j1]=2;
	  *j1=*j1+1;
      *i1=*i1-1;
      return;
	}
      if(fd[okb[cokb[*i1]+4]]=='1') goto m9;
      fd[okb[cokb[*i1]+4]]='0';
      md[*j1]=2;
      *j1=*j1+1;
      *i1=*i1-1;
      if(okb[cokb[*i1+1]+4]>pc[14])
      bdr1[okb[cokb[*i1+1]+4]]=okb[cokb[*i1+1]+4];
      return;
  m9: md[*j1]=0;
      if(*j1>0) goto m10;
      *pr=2;
      return;
 m10: *j1=*j1-1;
      if(*j1>=0) goto m11;
      *pr=2;
      return;
 m11: if(md[*j1]==0) goto m10;
      if(md[*j1]==1) goto m12;
      md[*j1]=0;
      goto m10;
 m12: md[*j1]=2;
      for(i=0;i<=(pc[6]+pc[14]);i++)
      bdr1[i]=bdr[i];
      *pr=1;
      return;
/* ����������� �������� 1 �� ������ �������� */
 m15: if(fd[okb[cokb[*i1]+3]]=='0') goto m9; /* ������� ����� */
      if(fd[okb[cokb[*i1]+3]]=='1') goto m18;
      if(fd[okb[cokb[*i1]+4]]=='0') goto m9; /* ������� ����� */
      if(fd[okb[cokb[*i1]+4]]=='1') goto m17;
      fd[okb[cokb[*i1]+3]]='1';
      fd[okb[cokb[*i1]+4]]='1';
      md[*j1]=2;
      *j1=*j1+1;
      *i1=*i1-1;
      if(okb[cokb[*i1+1]+3]>pc[14])
      bdr1[okb[cokb[*i1+1]+3]]=okb[cokb[*i1+1]+3];
      if(okb[cokb[*i1+1]+4]>pc[14])
      bdr1[okb[cokb[*i1+1]+4]]=okb[cokb[*i1+1]+4];
      return;
 m17: fd[okb[cokb[*i1]+3]]='1';
      md[*j1]=2;
      *j1=*j1+1;
      *i1=*i1-1;
      if(okb[cokb[*i1+1]+3]>pc[14])
      bdr1[okb[cokb[*i1+1]+3]]=okb[cokb[*i1+1]+3];
      return;
 m18: if(fd[okb[cokb[*i1]+4]]=='0') goto m9;
      if(fd[okb[cokb[*i1]+4]]=='1') goto m19;
      fd[okb[cokb[*i1]+4]]='1';
      md[*j1]=2;
      *j1=*j1+1;
      *i1=*i1-1;
      if(okb[cokb[*i1+1]+4]>pc[14])
      bdr1[okb[cokb[*i1+1]+4]]=okb[cokb[*i1+1]+4];
      return;
 m19: md[*j1]=2;
      *j1=*j1+1;
      *i1=*i1-1;
      return;
 }

// ����������� ��������� �������� �� ������ �������� ���� ��� 
void opfil(int *i1,int *j1,int *pr)
{
  int i;
  if(fd[*i1]=='1') goto m7; // �������� 1 �� ������ �������� 
// ����������� �������� 0 �� ������ �������� 
// ������ �������� �� ������ �������� 
  if(fd[okb[cokb[*i1]+3]]=='0') goto m5;
  if(fd[okb[cokb[*i1]+3]]=='1') goto m15; // ������� ����� 
  if(fd[okb[cokb[*i1]+4]]=='0') goto m4;
  if(fd[okb[cokb[*i1]+4]]=='1') goto m15; // ������� ����� 
  fd[okb[cokb[*i1]+3]]='0';
  fd[okb[cokb[*i1]+4]]='0';
  md[*j1]=2;
  *i1=*i1-1;
  *j1=*j1+1;
  if(okb[cokb[*i1+1]+3]>pc[14])
  bdr1[okb[cokb[*i1+1]+3]]=okb[cokb[*i1+1]+3];
  m3:   if(okb[cokb[*i1+1]+4]>pc[14])
	    bdr1[okb[cokb[*i1+1]+4]]=okb[cokb[*i1+1]+4];
	    return;
  m4:   fd[okb[cokb[*i1]+3]]='0';
	    md[*j1]=2;
  m33:  *i1=*i1-1;
	    *j1=*j1+1;
	    if(okb[cokb[*i1+1]+3]>pc[14])
	    bdr1[okb[cokb[*i1+1]+3]]=okb[cokb[*i1+1]+3];
	    return;
  m5:   if(fd[okb[cokb[*i1]+4]]=='0') goto m6;
	    if(fd[okb[cokb[*i1]+4]]=='1') goto m15;
        fd[okb[cokb[*i1]+4]]='0';
        md[*j1]=2;
  m32:  *i1=*i1-1;
        *j1=*j1+1;
        goto m3;
  m6:   md[*j1]=2;
        *i1=*i1-1;
        *j1=*j1+1;
        return;
  m7:   if(fd[okb[cokb[*i1]+3]]=='0') goto m13;
        if(fd[okb[cokb[*i1]+3]]=='1') goto m6;
        if(fd[okb[cokb[*i1]+4]]=='0') goto m11;
        if(fd[okb[cokb[*i1]+4]]=='1') goto m6;
        if(md[*j1]==0) goto m9;
        if(md[*j1]==1) goto m8;
  m31:  fd[okb[cokb[*i1]+4]]='1';
        goto m32;
  m8:   fd[okb[cokb[*i1]+3]]='1';
        goto m33;
  m9:   fd[okb[cokb[*i1]+3]]='1';
        md[*j1]=1;
        goto m33;
  m11:  md[*j1]=2;
        goto m8;
// ������ �������� �� ������ ����� 
  m13:  if(fd[okb[cokb[*i1]+4]]=='0') goto m15; // ������� ����� 
        if(fd[okb[cokb[*i1]+4]]=='1') goto m6;
        md[*j1]=2;
        goto m31;
  m15:  md[*j1]=0;
        if(*j1>0) goto m16;
  m35:  *pr=2; // ���������� �������� �������� ������ 
        return;
  m16:  *j1=*j1-1;
        if(*j1<0) goto m35;
        if(md[*j1]==0) goto m16;
        if(md[*j1]==1) goto m18;
        md[*j1]=0;
        goto m16;
  m18:  md[*j1]=2;
        for(i=0;i<=(pc[6]+pc[14]);i++)
          bdr1[i]=bdr[i];
        *pr=1; // ������� ����� 
        return;
 }




 // ����������� ��������� �������� �� ������ �������� ���� �� 
void opfne(int *i1,int *j1,int *pr)
{
        int i;
        if(fd[*i1]=='1') goto m2; // �������� 1 �� ������ �������� 
// �������� 0 �� ������ �������� 
// ������ �������� �� ����� �������� 
        if((fd[okb[cokb[*i1]+3]]=='0')||(fd[okb[cokb[*i1]+3]]=='X'))
        goto m4;
  m13:  md[*j1]=2;
        *j1=*j1+1;
	    *i1=*i1-1;
	    return;
  m2:   if(fd[okb[cokb[*i1]+3]]=='0') goto m13;
	    if(fd[okb[cokb[*i1]+3]]=='1') goto m5;
	    fd[okb[cokb[*i1]+3]]='0';
  m17:  md[*j1]=2;
	    *j1=*j1+1;
	    *i1=*i1-1;
	    if(okb[cokb[*i1+1]+3]>pc[14])
	    bdr1[okb[cokb[*i1+1]+3]]=okb[cokb[*i1+1]+3];
	    return;
  m4:   if(fd[okb[cokb[*i1]+3]]=='0') goto m5;
	    fd[okb[cokb[*i1]+3]]='1';
	    goto m17;
  m5:   md[*j1]=0;
	    if(*j1>0) goto m6;
  m18:  *pr=2; // ���������� �������� �������� ������ 
	    return;
  m6:   *j1=*j1-1;
	    if(*j1<0) goto m18;
	    if(md[*j1]==0) goto m6;
	    if(md[*j1]==1) goto m8;
	    md[*j1]=0;
	    goto m6;
  m8:   md[*j1]=2;
	    for(i=0;i<=(pc[6]+pc[14]);i++)
	    bdr1[i]=bdr[i];
        *pr=1; // ������� ����� 
	return;
}