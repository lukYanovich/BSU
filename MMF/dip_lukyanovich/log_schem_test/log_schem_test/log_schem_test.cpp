#include "pch.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    logschemtest::form_start start;
    Application::Run(% start);

    return 0;
}
