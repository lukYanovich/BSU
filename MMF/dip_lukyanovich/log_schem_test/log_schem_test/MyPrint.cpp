#include "pch.h"
#include "form_start.h"
#include "myprint.h"

extern char* LpName;
extern int l, n, ns, * tst;
void printtst()
{

    int c1[32] = { 0x80000000,0x40000000,0x20000000,0x10000000,
                0x8000000,0x4000000,0x2000000,0x1000000,
                0x800000,0x400000,0x200000,0x100000,
                0x80000,0x40000,0x20000,0x10000,
                0x8000,0x4000,0x2000,0x1000,
                0x800,0x400,0x200,0x100,
                0x80,0x40,0x20,0x10,
                0x8,0x4,0x2,0x1 };
    FILE* ftstd;
    int i, j, k, i1;

    strcat(LpName, ".tsd");
    //ftstd = fopen(LpName, "w");
    if ((ftstd = fopen(LpName, "w")) == NULL)
        //MessageBox(NULL, "Невозможно открыть файл типа .tsd", "Ошибка ", MB_OK | MB_ICONERROR);
        myAlert("невозможно открыть файл типа .tsd");
    LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
    fprintf(ftstd, "          ПРОВЕРЯЮЩИЙ  ТЕСТ\n");
    fprintf(ftstd, "      ВХОДЫ ");
    for (i = 0; i < (l - 4); i++)
        fprintf(ftstd, " ");
    fprintf(ftstd, "ВЫХОДЫ\n");
    j = 1;
    k = 0;
    for (i = 1; i <= tst[0]; i++)
    {
        fprintf(ftstd, "%4d) ", i);
        for (i1 = 0; i1 < l; i1++)
        {
            if ((tst[j] & c1[k]) != 0)
                fprintf(ftstd, "%c", '1');
            else
                fprintf(ftstd, "%c", '0');
            if (k != 31)k++;
            else
            {
                k = 0;
                j++;
            }
        }
        fprintf(ftstd, "  ");
        if (k != 0)
        {
            k = 0;
            j++;
        }
        for (i1 = 0; i1 < n; i1++)
        {
            if ((tst[j] & c1[k]) != 0)
                fprintf(ftstd, "%c", '1');
            else
                fprintf(ftstd, "%c", '0');
            if (k != 31)k++;
            else
            {
                k = 0;
                j++;
            }
        }
        fprintf(ftstd, "\n");
        if (k != 0)
        {
            k = 0;
            j++;
        }
    }
    fclose(ftstd);
}



extern int PointIdent[];
extern char Ident[];

extern int* ml, * mn, * nvx, * svx, * nvix, * svix, * nct, * cf, nhcf1;

void printcf()
{
    int c1[32] = { 0x80000000,0x40000000,0x20000000,0x10000000
                 ,0x08000000,0x04000000,0x02000000,0x01000000
                 ,0x00800000,0x00400000,0x00200000,0x00100000
                 ,0x00080000,0x00040000,0x00020000,0x00010000
                 ,0x00008000,0x00004000,0x00002000,0x00001000
                 ,0x00000800,0x00000400,0x00000200,0x00000100
                 ,0x00000080,0x00000040,0x00000020,0x00000010
                 ,0x00000008,0x00000004,0x00000002,0x00000001 };

    FILE* fcfd;
    int i, j, k, i1, count, pr;
    char IdentEl[40];  /* Идентификатор злемента*/
    strcat(LpName, ".fff");
    //fcfd = fopen(LpName, "w");
    if ((fcfd = fopen(LpName, "w")) == NULL)
        //MessageBox(NULL, "Невозможно открыть файл типа .fff", "Ошибка ", MB_OK | MB_ICONERROR);
        myAlert("невозможно открыть файл типа .fff");
    LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 

    fprintf(fcfd, "                СПИСОК НЕПРОВЕРЕННЫХ НЕИСПРАВНОСТЕЙ\n");
    for (i = 0; i < 70; i++) fprintf(fcfd, "*");
    fprintf(fcfd, "\nВ списке %d неисправностей\n", nhcf1);
    i1 = 0;

    for (i = 0; i < l; i++)
    {
        if ((cf[i] & c1[0]) != 0)
        {
            count = PointIdent[i + 3] - PointIdent[i + 2];
            fprintf(fcfd, " ");
            for (j = 0; j < count; j++)
                fprintf(fcfd, "%c", Ident[PointIdent[i + 2] + j]);
            fprintf(fcfd, " 0");
            if (i1 != 4) i1++;
            else
            {
                i1 = 0;
                fprintf(fcfd, "\n");
            }
        }
        if ((cf[i] & c1[1]) != 0)
        {
            count = PointIdent[i + 3] - PointIdent[i + 2];
            fprintf(fcfd, " ");
            for (j = 0; j < count; j++)
                fprintf(fcfd, "%c", Ident[PointIdent[i + 2] + j]);
            fprintf(fcfd, " 1");
            if (i1 != 4) i1++;
            else
            {
                i1 = 0;
                fprintf(fcfd, "\n");
            }
        }
    }
    if (i1 != 0) fprintf(fcfd, "\n");
    /*Вывод списка неисправностей для элементов */

    for (i = 0; i < ns; i++)
    {
        pr = 0;
        count = PointIdent[nct[nvix[svix[i]]] + 2] - PointIdent[nct[nvix[svix[i]]] + 1];
        i1 = 0; /* i1= числу символов в индефикаторе элементов */
        for (j = 0; j < count; j++)
        {
            if (Ident[PointIdent[nct[nvix[svix[i]]] + 1] + j] == '(') break;
            else
            {
                i1++;
                IdentEl[j] = Ident[PointIdent[nct[nvix[svix[i]]] + 1] + j];
            }
        }
        for (j = 0; j < ml[i]; j++)
        {
            if ((cf[l + i * 4] & c1[j]) != 0)
            {
                pr++;
                for (k = 0; k < i1; k++)
                    fprintf(fcfd, "%c", IdentEl[k]);
                fprintf(fcfd, ":");
                count = PointIdent[nct[nvx[svx[i] + j]] + 2] -
                    PointIdent[nct[nvx[svx[i] + j]] + 1];

                for (k = 0; k < count; k++)
                    fprintf(fcfd, "%c", Ident[PointIdent[nct[nvx[svx[i] + j]] + 1] + k]);
                fprintf(fcfd, " 0");//
            }
            if ((cf[l + i * 4 + 1] & c1[j]) != 0)
            {
                pr++;
                for (k = 0; k < i1; k++)
                    fprintf(fcfd, "%c", IdentEl[k]);
                fprintf(fcfd, ":");
                count = PointIdent[nct[nvx[svx[i] + j]] + 2] -
                    PointIdent[nct[nvx[svx[i] + j]] + 1];

                for (k = 0; k < count; k++)
                    fprintf(fcfd, "%c", Ident[PointIdent[nct[nvx[svx[i] + j]] + 1] + k]);
                fprintf(fcfd, " 1");//
            }
        }
        for (j = 0; j < mn[i]; j++)
        {
            if ((cf[l + i * 4 + 2] & c1[j]) != 0)
            {
                pr++;
                count = PointIdent[nct[nvix[svix[i] + j]] + 2] -
                    PointIdent[nct[nvix[svix[i] + j]] + 1];
                for (k = 0; k < count; k++)
                    fprintf(fcfd, "%c", Ident[PointIdent[nct[nvix[svix[i] + j]] + 1] + k]);
                fprintf(fcfd, " 0");//
            }
            if ((cf[l + i * 4 + 3] & c1[j]) != 0)
            {
                pr++;
                count = PointIdent[nct[nvix[svix[i] + j]] + 2] -
                    PointIdent[nct[nvix[svix[i] + j]] + 1];
                for (k = 0; k < count; k++)
                    fprintf(fcfd, "%c", Ident[PointIdent[nct[nvix[svix[i] + j]] + 1] + k]);
                fprintf(fcfd, " 1");//
            }
        }
        if (pr != 0) fprintf(fcfd, "\n");
    }
    fclose(fcfd);
    return;
}/* end printcf*/
