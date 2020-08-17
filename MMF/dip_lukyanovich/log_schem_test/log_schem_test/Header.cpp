#include "pch.h"


System::String^ charToString(char* str) {
	const char* temp = str;
	System::String^ s = gcnew System::String(temp);
	return s;
}

char* stringToChar(System::String^ s) {
	return (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(s);
}


char* myCaption = "внимание!";

void myAlert(char* msg)
{
	System::String^ message = charToString(msg);
	System::Windows::Forms::MessageBox::Show(message, charToString(myCaption));
}

void myAlert(const char* msg)
{
	myAlert((char*)msg);
}

/*
void myAlert(CStringA msg)
{
	System::String^ message = charToString((char*)(const char*)msg);
	System::Windows::Forms::MessageBox::Show(message, charToString(myCaption));
}
*/

void myAlert(System::String^ msg)
{
	System::String^ message = gcnew System::String(msg);
	System::Windows::Forms::MessageBox::Show(message, charToString(myCaption));
}
