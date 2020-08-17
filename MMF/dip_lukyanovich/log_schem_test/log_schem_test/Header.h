#pragma once
#include <cstring>
#include <string>

//using namespace System;
//using namespace System::Runtime::InteropServices;


System::String^ charToString(char*);
char* stringToChar(System::String^);

void myAlert(char* msg);
void myAlert(const char* msg);
//void myAlert(CStringA msg);
void myAlert(System::String^ msg);