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
	labelPolnota->Text = "Полнота теста " + Convert::ToString(percent) + "%";
	labelPolnota->Text += ", время " + Convert::ToString(((double)end - start) / ((double)CLOCKS_PER_SEC)) + " сек";
	labelResult->Text = "Входная последовательность обнаруживает " + nn + " неисправностей";
	labelResult->Text += "\nВ тест включено " + tst[0] + " наборов";
	if (NumPatGen)
		labelResult->Text += "\nСгенерировано " + Convert::ToString(NumPatGen) + " входных наборов";
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
		//MessageBox(NULL, "Невозможно открыть файл с тестом", "Ошибка ", MB_OK | MB_ICONERROR);//файл с тестом
		myAlert("невозможно открыть файл с тестом");
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
	i1 = l / 32 + n / 32;
	if ((j = l % 32) != 0)i1++;
	if ((j = n % 32) != 0)i1++;
	fwrite(tst, sizeof(int), tst[0] * i1 + 1, in_file);
	fclose(in_file);
	strcat(LpName, ".cff");
	//in_file = fopen(LpName, "wb");
	if ((in_file = fopen(LpName, "wb")) == NULL)
		//MessageBox(NULL, "Невозможно открыть файл .cff", "Ошибка ", MB_OK | MB_ICONERROR);//файл с неисправностями	 
		myAlert("невозможно открыть файл .cff");
	LpName[strlen(LpName) - 4] = 0x00;  // Удаление расширения 
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
		myAlert("неверно введены параметры M1, M2, M3");
		return;
	}
	vermet(&m_MPStruct);
	printcf();
	printtst();
}
