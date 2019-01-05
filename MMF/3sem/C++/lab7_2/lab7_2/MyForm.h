#pragma once
#include "frame\includes\Matrix.h"

namespace lab7_2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonOpen;
	private: System::Windows::Forms::Button^  buttonSave;
	private: System::Windows::Forms::Button^  buttonRun;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBoxI;
	private: System::Windows::Forms::TextBox^  textBoxJ;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;

	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->buttonRun = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxI = (gcnew System::Windows::Forms::TextBox());
			this->textBoxJ = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(62, 19);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(135, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"исходная матрица:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(390, 19);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 19);
			this->label2->TabIndex = 3;
			this->label2->Text = L"итоговая матрица:";
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(206, 12);
			this->buttonOpen->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(134, 34);
			this->buttonOpen->TabIndex = 4;
			this->buttonOpen->Text = L"открыть файл";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &MyForm::buttonOpen_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(530, 12);
			this->buttonSave->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(160, 34);
			this->buttonSave->TabIndex = 5;
			this->buttonSave->Text = L"сохранить в файл";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &MyForm::buttonSave_Click);
			// 
			// buttonRun
			// 
			this->buttonRun->Location = System::Drawing::Point(294, 346);
			this->buttonRun->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->buttonRun->Name = L"buttonRun";
			this->buttonRun->Size = System::Drawing::Size(382, 55);
			this->buttonRun->TabIndex = 6;
			this->buttonRun->Text = L"начать";
			this->buttonRun->UseVisualStyleBackColor = true;
			this->buttonRun->Click += gcnew System::EventHandler(this, &MyForm::buttonRun_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"input.txt";
			this->openFileDialog1->Filter = L"Text files(*.txt)|*.txt|All files(*.*)|*.*";
			this->openFileDialog1->InitialDirectory = L"C:\\\\Projects\\\\MMF\\\\3sem\\\\C++\\\\lab7_2\\\\lab7_2\\\\resources";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"Text files(*.txt)|*.txt|All files(*.*)|*.*";
			this->saveFileDialog1->InitialDirectory = L"C:\\\\Projects\\\\MMF\\\\3sem\\\\C++\\\\lab7_2\\\\lab7_2\\\\resources";
			this->saveFileDialog1->OverwritePrompt = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1500;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(86, 346);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(182, 19);
			this->label3->TabIndex = 7;
			this->label3->Text = L"переместить на позицию:";
			// 
			// textBoxI
			// 
			this->textBoxI->Location = System::Drawing::Point(108, 380);
			this->textBoxI->Name = L"textBoxI";
			this->textBoxI->Size = System::Drawing::Size(39, 27);
			this->textBoxI->TabIndex = 8;
			this->textBoxI->Text = L"1";
			// 
			// textBoxJ
			// 
			this->textBoxJ->Location = System::Drawing::Point(176, 380);
			this->textBoxJ->Name = L"textBoxJ";
			this->textBoxJ->Size = System::Drawing::Size(35, 27);
			this->textBoxJ->TabIndex = 9;
			this->textBoxJ->Text = L"1";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Sylfaen", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(66, 57);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(274, 234);
			this->richTextBox1->TabIndex = 10;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Sylfaen", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox2->Location = System::Drawing::Point(394, 57);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(296, 234);
			this->richTextBox2->TabIndex = 11;
			this->richTextBox2->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(757, 435);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBoxJ);
			this->Controls->Add(this->textBoxI);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->buttonRun);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->buttonOpen);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Sylfaen", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"cli lab 2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Matrix matrix;

	private: System::Void buttonOpen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			StreamReader^ sr = gcnew StreamReader(openFileDialog1->FileName);
			richTextBox1->Text = sr->ReadToEnd();
			sr->Close();
		}
	}

	private: System::Void buttonSave_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			StreamWriter^ sw = gcnew StreamWriter(saveFileDialog1->FileName);
			sw->WriteLine(richTextBox2->Text);
			sw->Close();
		}
	}

	private: System::Void buttonRun_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (timer1->Enabled == false)
		{
			matrix = gcnew Matrix(richTextBox1->Text, richTextBox2, Convert::ToInt32(textBoxI->Text) - 1, Convert::ToInt32(textBoxJ->Text) - 1);
			timer1->Start();
		}
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (matrix.doIteration(richTextBox2) == false)
			timer1->Stop();
	}
	};
}
