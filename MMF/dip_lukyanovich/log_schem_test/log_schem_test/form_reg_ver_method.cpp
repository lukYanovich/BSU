#include "pch.h"
#include "form_reg_ver_method.h"
#include "MyPrint.h"
#include "MyRegmethod.h"
#include "MyVermet.h"
#include "time.h"


extern char* LpName;
extern FILE* in_file;
extern int l, n, ns, nhcf1, nn, nhcf, NumPatGen;
extern int* tst,*cf;


System::Void logschemtest::form_reg_ver_method::buttonStart_Click(System::Object^ sender, System::EventArgs^ e) {
	clock_t start, end;
	start = clock();
	if (isVerMethod)
		verMethod();
	else
		regMethod();
	end = clock();
	int percent = nn * 100 / nhcf;
	labelPolnota->Text = "������� ����� " + Convert::ToString(percent) + "%";
	labelPolnota->Text += ", ����� " + Convert::ToString(((double)end - start) / ((double)CLOCKS_PER_SEC)) + " ���";
	labelResult->Text = "������� ������������������ ������������ " + nn + " ��������������";
	labelResult->Text += "\n� ���� �������� " + tst[0] + " �������";
	if (NumPatGen)
		labelResult->Text += "\n������������� " + Convert::ToString(NumPatGen) + " ������� �������";
	progressBar1->Value = percent;
}

System::Void logschemtest::form_reg_ver_method::form_reg_ver_method_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	//this->Parent->Show();
	return;
}


System::Void logschemtest::form_reg_ver_method::regMethod()
{
	HWND hWnd;
	int i1, j;

	modcx(hWnd);
	strcat(LpName, ".tst");
	//in_file = fopen(LpName, "wb");
	if ((in_file = fopen(LpName, "wb")) == NULL)
		//MessageBox(NULL, "���������� ������� ���� � ������", "������ ", MB_OK | MB_ICONERROR);//���� � ������
		myAlert("���������� ������� ���� � ������");
	LpName[strlen(LpName) - 4] = 0x00;  // �������� ���������� 
	i1 = l / 32 + n / 32;
	if ((j = l % 32) != 0)i1++;
	if ((j = n % 32) != 0)i1++;
	fwrite(tst, sizeof(int), tst[0] * i1 + 1, in_file);
	fclose(in_file);
	strcat(LpName, ".cff");
	//in_file = fopen(LpName, "wb");
	if ((in_file = fopen(LpName, "wb")) == NULL)
		//MessageBox(NULL, "���������� ������� ���� .cff", "������ ", MB_OK | MB_ICONERROR);//���� � ���������������	 
		myAlert("���������� ������� ���� .cff");
	LpName[strlen(LpName) - 4] = 0x00;  // �������� ���������� 
	fwrite(&nhcf1, sizeof(int), 2, in_file);
	fwrite(cf, sizeof(int), l + ns * 4, in_file);
	printcf();
	printtst();
}

System::Void logschemtest::form_reg_ver_method::verMethod()
{
	MPStruct m_MPStruct;
	m_MPStruct.M.SetSize(4);	
	m_MPStruct.M.SetAt(0, Convert::ToInt32(textBoxM1->Text));
	m_MPStruct.M.SetAt(1, Convert::ToInt32(textBoxM1->Text));
	m_MPStruct.M.SetAt(2, Convert::ToInt32(textBoxM1->Text));
	//m_MPStruct.M.SetAt(3, WM_VERMETUPDATE);
	//m_MPStruct.hw = m_hWnd;

	if ((m_MPStruct.M.GetAt(0) <= 0) | (m_MPStruct.M.GetAt(2) <= 0) | (m_MPStruct.M.GetAt(1) <= 0))
	{
		myAlert("������� ������� ��������� M1, M2, M3");
		return;
	}
	vermet(&m_MPStruct);
	printcf();
	printtst();
}
