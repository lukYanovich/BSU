/* Вычисление условий образования существенного пути от места */
/* неисправности до выходных полюсов логической сети          */
#include "pch.h"
#include "Myelements.h"
#include "MyRegmethod.h"


extern int* okb, * cokb, * vi, * ma, * nlin, * ba,
* bd, * oid, * coid, pc[], f1, s, w, v;
extern char* f, * fa;
void ucltr()
{
    int i1, j1, q;
    int i, iot;
    iot = 0;
    s = 0;
me2: for (i = 0; i <= (pc[6] + pc[14]); i++)
fa[i] = f[i];
v = w;
ba[0] = nlin[0];
i1 = 1;
j1 = 1;
f1 = 1;
q = oid[coid[nlin[0]] + 1];
while (q > 0)
{  /* q - признак активности */
    if (okb[cokb[nlin[i1]] + 1] == 1)
        /* активизация пути через элемент типа И */
        uti(&i1, &j1, &q);
    else
        if (okb[cokb[nlin[i1]] + 1] == 2)
            /* активизация пути через элемент типа ИЛИ */
            utili(&i1, &j1, &q);
        else
            /* активизация пути через элемент типа НЕ */
            utne(&i1, &j1, &q);
    /* printf("ucltr: э----¦т: %d, fa: %c%c%c%c%c%c%c%c%c%c%c%c\n",nlin[i1], */
    /*	fa[1],fa[2],fa[3],fa[4],fa[5],fa[6],fa[7],fa[8],fa[9],           */
    /*	fa[10],fa[11],fa[12]);  */
    if (s > 0) return;
}
iot++;
if (iot == 101) return;
for (i1 = i1 - 1; i1 > 0; i1--)
{
    if (ma[i1] == 1)
    {
        ma[i1] = 2;
        goto me2;
    }
    if (ma[i1] > 1)
        ma[i1] = 0;
}
}

/* Активизация пути через элемент типа И */
void uti(int* i1, int* j1, int* q)
{
    int i;
    /* Анализ значений на входах элемента и выбор варианта активизации */
    if (fa[okb[cokb[nlin[*i1]] + 3]] == 'D') goto m13;
    if (fa[okb[cokb[nlin[*i1]] + 3]] == '1') goto m35;
    if (fa[okb[cokb[nlin[*i1]] + 3]] == 'B') goto m24;
    if (fa[okb[cokb[nlin[*i1]] + 3]] == '0') goto m44;
    if (fa[okb[cokb[nlin[*i1]] + 4]] == 'D') goto m5;
    if (fa[okb[cokb[nlin[*i1]] + 4]] == 'B') goto m3;
    if (fa[okb[cokb[nlin[*i1]] + 4]] == '0') goto m2;
    ma[*i1] = 0;
    *i1 = *i1 + 1;
    return;
m2: fa[nlin[*i1]] = '0';
    ma[*i1] = 2;
    goto m11;
m3: *q = *q - 1;
    if (ma[*i1] == 0) goto m4;
    if (ma[*i1] == 2) goto m6;
    fa[okb[cokb[nlin[*i1]] + 3]] = '1';
    fa[nlin[*i1]] = 'B';
    *q = *q + oid[coid[nlin[*i1]] + 1];
    bd[v] = okb[cokb[nlin[*i1]] + 3];
    v++;
    goto m9;
m4: fa[okb[cokb[nlin[*i1]] + 3]] = '1';
    fa[nlin[*i1]] = 'B';
    *q = *q + oid[coid[nlin[*i1]] + 1];
    goto m8;
m5: *q = *q - 1;
    if (ma[*i1] == 0)goto m7;
    if (ma[*i1] == 2) goto m6;
    fa[okb[cokb[nlin[*i1]] + 3]] = '1';
    bd[v] = okb[cokb[nlin[*i1]] + 3];
    v = v + 1;
    fa[nlin[*i1]] = 'D';
    q = q + oid[coid[nlin[*i1]] + 1];
    goto m9;
m6: fa[okb[cokb[nlin[*i1]] + 3]] = '0';
    fa[nlin[*i1]] = '0';
    bd[v] = okb[cokb[nlin[*i1]] + 3];
    v++;
    goto m11;
m7: fa[okb[cokb[nlin[*i1]] + 3]] = '1';
    fa[nlin[*i1]] = 'D';
    *q = *q + oid[coid[nlin[*i1]] + 1];
m8: ma[*i1] = 1;
    bd[v] = okb[cokb[nlin[*i1]] + 3];
    v++;
m9: for (i = 0; i < pc[5]; i++)
{
    if (nlin[*i1] == vi[i]) goto m12;
}
m11: ba[*j1] = nlin[*i1];
f1++;
*i1 = *i1 + 1;
*j1 = *j1 + 1;
return;
m12: ba[*j1] = nlin[*i1];
f1++;
s = 1;
return;
m13: *q = *q - 1;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'D') goto m14;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'B') goto m18;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '0') goto m19;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '1') goto m115;
if (ma[*i1] == 0) goto m20;
if (ma[*i1] == 1) goto m21;
fa[okb[cokb[nlin[*i1]] + 4]] = '0';
fa[nlin[*i1]] = '0';
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
goto m11;
m14: *q = *q - 1;
m115: fa[nlin[*i1]] = 'D';
*q = *q + oid[coid[nlin[*i1]] + 1];
ma[*i1] = 2;
goto m9;
m18: *q = *q - 1;
m19: fa[nlin[*i1]] = '0';
ma[*i1] = 2;
goto m11;
m20: fa[okb[cokb[nlin[*i1]] + 4]] = '1';
fa[nlin[*i1]] = 'D';
ma[*i1] = 1;
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m21: fa[okb[cokb[nlin[*i1]] + 4]] = '1';
fa[nlin[*i1]] = 'D';
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m24: *q = *q - 1;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'D') goto m31;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'B') goto m25;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '0') goto m32;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '1') goto m26;
if (ma[*i1] == 0) goto m33;
if (ma[*i1] == 1) goto m34;
fa[okb[cokb[nlin[*i1]] + 4]] = '0';
fa[nlin[*i1]] = '0';
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
goto m11;
m25: *q = *q - 1;
m26: fa[nlin[*i1]] = 'B';
ma[*i1] = 2;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m31: *q = *q - 1;
m32: fa[nlin[*i1]] = '0';
ma[*i1] = 2;
goto m11;
m33: fa[okb[cokb[nlin[*i1]] + 4]] = '1';
fa[nlin[*i1]] = 'B';
ma[*i1] = 1;
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m34: fa[okb[cokb[nlin[*i1]] + 4]] = '1';
fa[nlin[*i1]] = 'B';
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m35: if (fa[okb[cokb[nlin[*i1]] + 4]] == 'D') goto m36;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'B') goto m41;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '0') goto m43;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '1') goto m42;
ma[*i1] = 0;
*i1 = *i1 + 1;
return;
m36: *q = *q - 1;
fa[nlin[*i1]] = 'D';
ma[*i1] = 2;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m41: *q = *q - 1;
fa[nlin[*i1]] = 'B';
ma[*i1] = 2;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m42: fa[nlin[*i1]] = '1';
ma[*i1] = 2;
goto m11;
m43: fa[nlin[*i1]] = '0';
ma[*i1] = 2;
goto m11;
m44: fa[nlin[*i1]] = '0';
if ((fa[okb[cokb[nlin[*i1]] + 4]] != 'D') && (fa[okb[cokb[nlin[*i1]] + 4]] != 'B'))
goto m71;
*q = *q - 1;
m71: ma[*i1] = 2;
ba[*j1] = nlin[*i1];
f1++;
*i1 = *i1 + 1;
*j1 = *j1 + 1;
return;
}

/* Активизация пути через элемент типа ИЛИ */
void utili(int* i1, int* j1, int* q)
{
    int i;
    /* анализ значений на входах элемента и выбор варианта активизации */
    if (fa[okb[cokb[nlin[*i1]] + 3]] == 'D') goto m13;
    if (fa[okb[cokb[nlin[*i1]] + 3]] == 'B') goto m34;
    if (fa[okb[cokb[nlin[*i1]] + 3]] == '1') goto m33;
    if (fa[okb[cokb[nlin[*i1]] + 3]] == '0') goto m24;
    if (fa[okb[cokb[nlin[*i1]] + 4]] == 'D') goto m5;
    if (fa[okb[cokb[nlin[*i1]] + 4]] == 'B') goto m3;
    if (fa[okb[cokb[nlin[*i1]] + 4]] == '1') goto m2;
    ma[*i1] = 0;
    *i1 = *i1 + 1;
    return;
m2:  fa[nlin[*i1]] = '1';
    ma[*i1] = 2;
    goto m11;
m3:  *q = *q - 1;
    if (ma[*i1] == 0) goto m4;
    if (ma[*i1] == 2) goto m6;
    fa[okb[cokb[nlin[*i1]] + 3]] = '0';
    fa[nlin[*i1]] = 'B';
    bd[v] = okb[cokb[nlin[*i1]] + 3];
    v++;
    *q = *q + oid[coid[nlin[*i1]] + 1];
    goto m9;
m4:  fa[okb[cokb[nlin[*i1]] + 3]] = '0';
    fa[nlin[*i1]] = 'B';
    *q = *q + oid[coid[nlin[*i1]] + 1];
    goto m8;
m5:  *q = *q - 1;
    if (ma[*i1] == 2) goto m6;
    if (ma[*i1] == 0) goto m7;
    fa[okb[cokb[nlin[*i1]] + 3]] = '0';
    bd[v] = okb[cokb[nlin[*i1]] + 3];
    v++;
    fa[nlin[*i1]] = 'D';
    *q = *q + oid[coid[nlin[*i1]] + 1];
    goto m9;
m6:  fa[okb[cokb[nlin[*i1]] + 3]] = '1';
    bd[v] = okb[cokb[nlin[*i1]] + 3];
    v++;
    fa[nlin[*i1]] = '1';
    goto m11;
m7:  fa[okb[cokb[nlin[*i1]] + 3]] = '0';
    fa[nlin[*i1]] = 'D';
    *q = *q + oid[coid[nlin[*i1]] + 1];
m8:  ma[*i1] = 1;
    bd[v] = okb[cokb[nlin[*i1]] + 3];
    v++;
m9:  for (i = 0; i < pc[5]; i++)
{
    if (nlin[*i1] == vi[i]) goto m12;
}
m11: ba[*j1] = nlin[*i1];
f1++;
*i1 = *i1 + 1;
*j1 = *j1 + 1;
return;
m12: ba[*j1] = nlin[*i1];
f1++;
s = 1;
return;
m13: *q = *q - 1;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'D') goto m18;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'B') goto m15;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '0') goto m19;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '1') goto m16;
if (ma[*i1] == 0) goto m17;
if (ma[*i1] == 1) goto m14;
fa[okb[cokb[nlin[*i1]] + 4]] = '1';
fa[nlin[*i1]] = '1';
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
goto m11;
m14: fa[okb[cokb[nlin[*i1]] + 4]] = '0';
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
fa[nlin[*i1]] = 'D';
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m15: *q = *q - 1;
m16: fa[nlin[*i1]] = '1';
ma[*i1] = 2;
goto m11;
m17: fa[okb[cokb[nlin[*i1]] + 4]] = '0';
fa[nlin[*i1]] = 'D';
*q = *q + oid[coid[nlin[*i1]] + 1];
ma[*i1] = 1;
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
goto m9;
m18: *q = *q - 1;
m19: fa[nlin[*i1]] = 'D';
*q = *q + oid[coid[nlin[*i1]] + 1];
ma[*i1] = 2;
goto m9;
m24: if (fa[okb[cokb[nlin[*i1]] + 4]] == 'D') goto m28;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'B') goto m25;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '0') goto m26;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '1') goto m27;
ma[*i1] = 0;
*i1 = *i1 + 1;
return;
m25: *q = *q - 1;
fa[nlin[*i1]] = 'B';
ma[*i1] = 2;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m26: fa[nlin[*i1]] = '0';
ma[*i1] = 2;
goto m11;
m27: fa[nlin[*i1]] = '1';
ma[*i1] = 2;
goto m11;
m28: *q = *q - 1;
fa[nlin[*i1]] = 'D';
ma[*i1] = 2;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m33: fa[nlin[*i1]] = '1';
if ((fa[okb[cokb[nlin[*i1]] + 4]] == 'D') || (fa[okb[cokb[nlin[*i1]] + 4]] == 'B'))
*q = *q - 1;
ma[*i1] = 2;
ba[*j1] = nlin[*i1];
f1++;
*i1 = *i1 + 1;
*j1 = *j1 + 1;
return;
m34: *q = *q - 1;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'D') goto m37;
if (fa[okb[cokb[nlin[*i1]] + 4]] == 'B') goto m39;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '0') goto m40;
if (fa[okb[cokb[nlin[*i1]] + 4]] == '1') goto m38;
if (ma[*i1] == 1) goto m35;
if (ma[*i1] == 0) goto m36;
fa[okb[cokb[nlin[*i1]] + 4]] = '1';
fa[nlin[*i1]] = '1';
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
goto m11;
m35: fa[okb[cokb[nlin[*i1]] + 4]] = '0';
fa[nlin[*i1]] = 'B';
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m36: fa[okb[cokb[nlin[*i1]] + 4]] = '0';
fa[nlin[*i1]] = 'B';
ma[*i1] = 1;
bd[v] = okb[cokb[nlin[*i1]] + 4];
v++;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
m37: *q = *q - 1;
m38: fa[nlin[*i1]] = '1';
ma[*i1] = 2;
goto m11;
m39: *q = *q - 1;
m40: fa[nlin[*i1]] = 'B';
ma[*i1] = 2;
*q = *q + oid[coid[nlin[*i1]] + 1];
goto m9;
}



/* Активизация пути через элемент типа НЕ */
void utne(int* i1, int* j1, int* q)
{
    int i;
    /* Анализ значения на входе и выбор варианта активизации */
    if (fa[okb[cokb[nlin[*i1]] + 3]] == 'X')
    {
        ma[*i1] = 0;
        *i1 = *i1 + 1;
        return;
    }
    if (fa[okb[cokb[nlin[*i1]] + 3]] == '1')
    {
        fa[nlin[*i1]] = '0';
        ma[*i1] = 2;
        ba[*j1] = nlin[*i1];
        f1++;
        *j1 = *j1 + 1;
        *i1 = *i1 + 1;
        return;
    }
    if (fa[okb[cokb[nlin[*i1]] + 3]] == '0')
    {
        fa[nlin[*i1]] = '1';
        ma[*i1] = 2;
        ba[*j1] = nlin[*i1];
        f1++;
        *j1 = *j1 + 1;
        *i1 = *i1 + 1;
        return;
    }
    if (fa[okb[cokb[nlin[*i1]] + 3]] == 'D')
    {
        *q = *q - 1;
        fa[nlin[*i1]] = 'B';
    m1: *q = *q + oid[coid[nlin[*i1]] + 1];
        ma[*i1] = 2;
        for (i = 0; i < pc[5]; i++)
        {
            if (nlin[*i1] == vi[i])
            {
                ba[*j1] = nlin[*i1];
                f1++;
                s = 1;
                return;
            }
        }
        ba[*j1] = nlin[*i1];
        f1++;
        *j1 = *j1 + 1;
        *i1 = *i1 + 1;
        return;
    }
    *q = *q - 1;
    fa[nlin[*i1]] = 'D';
    goto m1;
}