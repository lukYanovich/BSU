#pragma once


namespace logschemtest {

	//using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for form_start
	/// </summary>
	public ref class form_start : public System::Windows::Forms::Form
	{
	public:
		form_start(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~form_start()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ buttonPrintTest;

	private: System::Windows::Forms::Button^ buttonOpen;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonStartMethodForm;







	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ buttonPrintProtocol;
	private: System::Windows::Forms::Button^ buttonPrintUntesting;


	private: System::Windows::Forms::CheckBox^ checkBoxRegMethod;
	private: System::Windows::Forms::CheckBox^ checkBoxVerMethod;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ labelFileName;



	protected:

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->buttonPrintTest = (gcnew System::Windows::Forms::Button());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonStartMethodForm = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->buttonPrintProtocol = (gcnew System::Windows::Forms::Button());
			this->buttonPrintUntesting = (gcnew System::Windows::Forms::Button());
			this->checkBoxRegMethod = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxVerMethod = (gcnew System::Windows::Forms::CheckBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->labelFileName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(243, 20);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(596, 272);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// buttonPrintTest
			// 
			this->buttonPrintTest->Enabled = false;
			this->buttonPrintTest->Location = System::Drawing::Point(351, 345);
			this->buttonPrintTest->Name = L"buttonPrintTest";
			this->buttonPrintTest->Size = System::Drawing::Size(125, 60);
			this->buttonPrintTest->TabIndex = 3;
			this->buttonPrintTest->Text = L"теста";
			this->buttonPrintTest->UseVisualStyleBackColor = true;
			this->buttonPrintTest->Click += gcnew System::EventHandler(this, &form_start::buttonPrintTest_Click);
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(89, 82);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(125, 30);
			this->buttonOpen->TabIndex = 4;
			this->buttonOpen->Text = L"выбрать файл";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &form_start::buttonOpen_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &form_start::openFileDialog1_FileOk);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Location = System::Drawing::Point(65, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(172, 119);
			this->label1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Location = System::Drawing::Point(65, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(172, 36);
			this->label2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(96, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(118, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"открытие файла";
			// 
			// buttonStartMethodForm
			// 
			this->buttonStartMethodForm->Enabled = false;
			this->buttonStartMethodForm->Location = System::Drawing::Point(89, 262);
			this->buttonStartMethodForm->Name = L"buttonStartMethodForm";
			this->buttonStartMethodForm->Size = System::Drawing::Size(125, 30);
			this->buttonStartMethodForm->TabIndex = 14;
			this->buttonStartMethodForm->Text = L"перейти";
			this->buttonStartMethodForm->UseVisualStyleBackColor = true;
			this->buttonStartMethodForm->Click += gcnew System::EventHandler(this, &form_start::buttonVerMethod_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(101, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 17);
			this->label4->TabIndex = 17;
			this->label4->Text = L"выбор метода";
			// 
			// label5
			// 
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->Location = System::Drawing::Point(65, 138);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(172, 36);
			this->label5->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Location = System::Drawing::Point(65, 138);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(172, 164);
			this->label6->TabIndex = 15;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(397, 311);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 17);
			this->label7->TabIndex = 20;
			this->label7->Text = L"вывод";
			// 
			// label8
			// 
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Location = System::Drawing::Point(65, 301);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(774, 36);
			this->label8->TabIndex = 19;
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label9->Location = System::Drawing::Point(65, 301);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(774, 115);
			this->label9->TabIndex = 18;
			// 
			// buttonPrintProtocol
			// 
			this->buttonPrintProtocol->Enabled = false;
			this->buttonPrintProtocol->Location = System::Drawing::Point(112, 345);
			this->buttonPrintProtocol->Name = L"buttonPrintProtocol";
			this->buttonPrintProtocol->Size = System::Drawing::Size(125, 60);
			this->buttonPrintProtocol->TabIndex = 21;
			this->buttonPrintProtocol->Text = L"протокола";
			this->buttonPrintProtocol->UseVisualStyleBackColor = true;
			this->buttonPrintProtocol->Click += gcnew System::EventHandler(this, &form_start::buttonPrintProtocol_Click);
			// 
			// buttonPrintUntesting
			// 
			this->buttonPrintUntesting->Enabled = false;
			this->buttonPrintUntesting->Location = System::Drawing::Point(631, 345);
			this->buttonPrintUntesting->Name = L"buttonPrintUntesting";
			this->buttonPrintUntesting->Size = System::Drawing::Size(125, 60);
			this->buttonPrintUntesting->TabIndex = 22;
			this->buttonPrintUntesting->Text = L"непроверенных неисправностей";
			this->buttonPrintUntesting->UseVisualStyleBackColor = true;
			this->buttonPrintUntesting->Click += gcnew System::EventHandler(this, &form_start::buttonPrintUntesting_Click);
			// 
			// checkBoxRegMethod
			// 
			this->checkBoxRegMethod->AutoSize = true;
			this->checkBoxRegMethod->Checked = true;
			this->checkBoxRegMethod->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxRegMethod->Location = System::Drawing::Point(88, 189);
			this->checkBoxRegMethod->Name = L"checkBoxRegMethod";
			this->checkBoxRegMethod->Size = System::Drawing::Size(108, 21);
			this->checkBoxRegMethod->TabIndex = 25;
			this->checkBoxRegMethod->Text = L"регул€рный";
			this->checkBoxRegMethod->UseVisualStyleBackColor = true;
			this->checkBoxRegMethod->CheckedChanged += gcnew System::EventHandler(this, &form_start::checkBoxRegMethod_CheckedChanged);
			// 
			// checkBoxVerMethod
			// 
			this->checkBoxVerMethod->AutoSize = true;
			this->checkBoxVerMethod->Location = System::Drawing::Point(88, 228);
			this->checkBoxVerMethod->Name = L"checkBoxVerMethod";
			this->checkBoxVerMethod->Size = System::Drawing::Size(132, 21);
			this->checkBoxVerMethod->TabIndex = 26;
			this->checkBoxVerMethod->Text = L"веро€тностный";
			this->checkBoxVerMethod->UseVisualStyleBackColor = true;
			this->checkBoxVerMethod->CheckedChanged += gcnew System::EventHandler(this, &form_start::checkBoxVerMethod_CheckedChanged);
			// 
			// label10
			// 
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label10->Location = System::Drawing::Point(-19, 425);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(945, 56);
			this->label10->TabIndex = 27;
			// 
			// labelFileName
			// 
			this->labelFileName->AutoSize = true;
			this->labelFileName->Location = System::Drawing::Point(12, 433);
			this->labelFileName->MaximumSize = System::Drawing::Size(897, 490);
			this->labelFileName->Name = L"labelFileName";
			this->labelFileName->Size = System::Drawing::Size(0, 17);
			this->labelFileName->TabIndex = 28;
			// 
			// form_start
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(913, 478);
			this->Controls->Add(this->labelFileName);
			this->Controls->Add(this->checkBoxVerMethod);
			this->Controls->Add(this->checkBoxRegMethod);
			this->Controls->Add(this->buttonPrintUntesting);
			this->Controls->Add(this->buttonPrintProtocol);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonStartMethodForm);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonOpen);
			this->Controls->Add(this->buttonPrintTest);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->MaximizeBox = false;
			this->Name = L"form_start";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"log_schcem_test";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &form_start::form_start_FormClosed);
			this->Load += gcnew System::EventHandler(this, &form_start::form_start_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//private: System::Void buttonRegMethod_Click(System::Object^ sender, System::EventArgs^ e);
		//private: System::Void buttonResult_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonOpen_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {}
	private: System::Void buttonVerMethod_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void form_start_Load(System::Object^ sender, System::EventArgs^ e) {	}
	private: System::Void checkBoxVerMethod_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonPrintUntesting_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonPrintProtocol_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonPrintTest_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void form_start_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void checkBoxRegMethod_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void printResult(char*);
	};
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
#define INT_SIZE 32

UINT Mainpr(LPVOID pParam);
UINT FromFile(LPVOID pParam);
int Pow2(int);
void ReadElement(FILE*);
int Convertor();
void ClearArrays();

int ReadData();
void SaveData();


void DeleteFiles();