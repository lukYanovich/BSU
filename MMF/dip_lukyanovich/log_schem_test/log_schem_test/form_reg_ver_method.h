#pragma once


namespace logschemtest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for form_reg_ver_method
	/// </summary>
	public ref class form_reg_ver_method : public System::Windows::Forms::Form
	{
	public:
		form_reg_ver_method(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
		form_reg_ver_method(bool checked)
		{
			isVerMethod = checked;
			if (!checked)
				name = "√енераци€ теста регул€рным методом";
			else
				name = "√енераци€ теста веро€тностным методом";
			InitializeComponent();
		}

		
		bool isVerMethod;
		System::String^ name;
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~form_reg_ver_method()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	protected:
	private: System::Windows::Forms::TextBox^ textBoxM1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxM2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxM3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonStart;

	private: System::Windows::Forms::Label^ labelResult;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ labelPolnota;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->textBoxM1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxM2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxM3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->labelResult = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelPolnota = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(78, 194);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(330, 36);
			this->progressBar1->TabIndex = 0;
			// 
			// textBoxM1
			// 
			this->textBoxM1->Enabled = isVerMethod;//true;
			this->textBoxM1->Location = System::Drawing::Point(119, 51);
			this->textBoxM1->Name = L"textBoxM1";
			this->textBoxM1->Size = System::Drawing::Size(51, 22);
			this->textBoxM1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(91, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"M1:";
			// 
			// textBoxM2
			// 
			this->textBoxM2->Enabled = isVerMethod;//true;
			this->textBoxM2->Location = System::Drawing::Point(119, 89);
			this->textBoxM2->Name = L"textBoxM2";
			this->textBoxM2->Size = System::Drawing::Size(51, 22);
			this->textBoxM2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(91, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"M2:";
			// 
			// textBoxM3
			// 
			this->textBoxM3->Enabled = isVerMethod;//true;
			this->textBoxM3->Location = System::Drawing::Point(119, 129);
			this->textBoxM3->Name = L"textBoxM3";
			this->textBoxM3->Size = System::Drawing::Size(51, 22);
			this->textBoxM3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(91, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"M3:";
			// 
			// buttonStart
			// 
			this->buttonStart->Location = System::Drawing::Point(78, 320);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(330, 30);
			this->buttonStart->TabIndex = 9;
			this->buttonStart->Text = L"старт";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &form_reg_ver_method::buttonStart_Click);
			// 
			// labelResult
			// 
			this->labelResult->Location = System::Drawing::Point(78, 243);
			this->labelResult->Name = L"labelResult";
			this->labelResult->Size = System::Drawing::Size(330, 75);
			this->labelResult->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(46, 210);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(28, 17);
			this->label4->TabIndex = 12;
			this->label4->Text = L"0%";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(414, 210);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 17);
			this->label5->TabIndex = 13;
			this->label5->Text = L"100%";
			// 
			// labelPolnota
			// 
			this->labelPolnota->AutoSize = true;
			this->labelPolnota->Location = System::Drawing::Point(115, 168);
			this->labelPolnota->Name = L"labelPolnota";
			this->labelPolnota->Size = System::Drawing::Size(0, 17);
			this->labelPolnota->TabIndex = 14;
			// 
			// form_reg_ver_method
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(489, 381);
			this->Controls->Add(this->labelPolnota);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->labelResult);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->textBoxM3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxM2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxM1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label1);
			this->Name = L"form_reg_ver_method";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = name;// L"тест";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &form_reg_ver_method::form_reg_ver_method_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void form_reg_ver_method_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void regMethod();
	private: System::Void verMethod();
	};
}


struct MPStruct {
	CUIntArray M;
	HWND hw;
	LPCSTR st;
};