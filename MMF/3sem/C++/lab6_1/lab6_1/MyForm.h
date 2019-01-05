#pragma once
#include "EndOfOffset.h"

namespace lab6_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::RichTextBox^  richTextBoxOut;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBoxArray;
	private: System::Windows::Forms::TextBox^  textBoxNumberOfOffset;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RadioButton^  radioButtonRight;
	private: System::Windows::Forms::RadioButton^  radioButtonLeft;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->richTextBoxOut = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxArray = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNumberOfOffset = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->radioButtonRight = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonLeft = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBoxOut
			// 
			this->richTextBoxOut->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxOut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBoxOut->ForeColor = System::Drawing::SystemColors::WindowText;
			this->richTextBoxOut->Location = System::Drawing::Point(42, 139);
			this->richTextBoxOut->Margin = System::Windows::Forms::Padding(5);
			this->richTextBoxOut->Name = L"richTextBoxOut";
			this->richTextBoxOut->ReadOnly = true;
			this->richTextBoxOut->Size = System::Drawing::Size(653, 63);
			this->richTextBoxOut->TabIndex = 0;
			this->richTextBoxOut->Text = L"здесь что-то будет.\nпотом";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(52, 20);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"массив:";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(52, 65);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(157, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"число смещений(k):";
			// 
			// textBoxArray
			// 
			this->textBoxArray->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxArray->Location = System::Drawing::Point(237, 20);
			this->textBoxArray->Margin = System::Windows::Forms::Padding(5);
			this->textBoxArray->Name = L"textBoxArray";
			this->textBoxArray->Size = System::Drawing::Size(430, 26);
			this->textBoxArray->TabIndex = 0;
			this->textBoxArray->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBoxArray_KeyDown);
			// 
			// textBoxNumberOfOffset
			// 
			this->textBoxNumberOfOffset->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxNumberOfOffset->Location = System::Drawing::Point(237, 62);
			this->textBoxNumberOfOffset->Margin = System::Windows::Forms::Padding(5);
			this->textBoxNumberOfOffset->Name = L"textBoxNumberOfOffset";
			this->textBoxNumberOfOffset->Size = System::Drawing::Size(430, 26);
			this->textBoxNumberOfOffset->TabIndex = 4;
			this->textBoxNumberOfOffset->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBoxNumberOfOffset_KeyDown);
			// 
			// timer1
			// 
			this->timer1->Interval = 1200;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::PaleGreen;
			this->button1->Location = System::Drawing::Point(237, 218);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 46);
			this->button1->TabIndex = 5;
			this->button1->Text = L"начать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(52, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"направление:";
			// 
			// radioButtonRight
			// 
			this->radioButtonRight->AutoSize = true;
			this->radioButtonRight->Checked = true;
			this->radioButtonRight->Location = System::Drawing::Point(6, 11);
			this->radioButtonRight->Name = L"radioButtonRight";
			this->radioButtonRight->Size = System::Drawing::Size(81, 24);
			this->radioButtonRight->TabIndex = 7;
			this->radioButtonRight->TabStop = true;
			this->radioButtonRight->Text = L"вправо";
			this->radioButtonRight->UseVisualStyleBackColor = true;
			// 
			// radioButtonLeft
			// 
			this->radioButtonLeft->AutoSize = true;
			this->radioButtonLeft->Location = System::Drawing::Point(93, 11);
			this->radioButtonLeft->Name = L"radioButtonLeft";
			this->radioButtonLeft->Size = System::Drawing::Size(73, 24);
			this->radioButtonLeft->TabIndex = 8;
			this->radioButtonLeft->Text = L"влево";
			this->radioButtonLeft->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButtonRight);
			this->groupBox1->Controls->Add(this->radioButtonLeft);
			this->groupBox1->Location = System::Drawing::Point(237, 96);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(176, 35);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 276);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxNumberOfOffset);
			this->Controls->Add(this->textBoxArray);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBoxOut);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"visual c++ - lab 1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		List<String^>^ arr;
		int numberOfOffset, iteration = 0, positionOfHead = 0;
		bool isCanonical = true;
		String^ separatorsLine = " ,;.";
		String^ currentLine = "";
		array<Char>^ separators = separatorsLine->ToCharArray();

	private: System::Void showMessageOfError(String^ str) {
		String^ message = str + ".\nлибо прекратите работу приложения.";
			MessageBox::Show(message);
	}

	private: System::Void endTick() {
		timer1->Stop();
		iteration = 0;
		noChangeForm(false);
		EndOfOffset^ t = gcnew EndOfOffset(textBoxNumberOfOffset->Text);
		t->ShowDialog();
	}

	private: System::Void noChangeForm(bool flag) {
		textBoxArray->ReadOnly = flag;
		textBoxNumberOfOffset->ReadOnly = flag;
		button1->Enabled = !flag;
		groupBox1->Enabled = !flag;
	}

	private: System::Void printArray() {
		String^ temp = arr[0];
		for (int i(1); i < arr->Count; i++)
			temp = temp + " " + arr[i];
		richTextBoxOut->Select(0, temp->Length);
		richTextBoxOut->SelectionColor = Color::Black;
		richTextBoxOut->Text = temp;
		int begPos = 0;
		for (int i(0); i < positionOfHead; i++)
			begPos += arr[i]->Length + 1;
		richTextBoxOut->Select(begPos, arr[positionOfHead]->Length);
		richTextBoxOut->SelectionColor = Color::Red;
		richTextBoxOut->Select(0, 0);
	}

	private: System::Void stepToLeft() {
		String^ temp = arr[0];
		for (int i(0); i < arr->Count - 1; i++)
			arr[i] = arr[i + 1];
		arr[arr->Count - 1] = temp;
		if (positionOfHead == 0)
			positionOfHead = arr->Count - 1;
		else
			positionOfHead--;
	}

	private: System::Void stepToRigth() {
		String^ temp = arr[arr->Count - 1];
		for (int i(arr->Count - 1); i > 0; i--)
			arr[i] = arr[i - 1];
		arr[0] = temp;
		if (positionOfHead == arr->Count - 1)
			positionOfHead = 0;
		else
			positionOfHead++;
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (iteration >= numberOfOffset)
			endTick();
		else {
			isCanonical ? stepToRigth() : stepToLeft();
			printArray();
			iteration++;
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (String::Compare(textBoxArray->Text, "") == 0)
			showMessageOfError("введите массив");
		else if (String::Compare(textBoxNumberOfOffset->Text, "") == 0)
			showMessageOfError("введите число смещений");
		else {
			numberOfOffset = Convert::ToInt32(textBoxNumberOfOffset->Text);
			if (numberOfOffset <= 0)
				showMessageOfError("введите число смещений больше 0");
			else {
				if (String::Compare(currentLine, textBoxArray->Text) != 0) {
					currentLine = textBoxArray->Text;
					arr = gcnew List<String^>(currentLine->Split(separators));
					for (int i(0); i < arr->Count; i++)
						if (String::Compare(arr[i], "") == 0)
							arr->RemoveAt(i--);
					positionOfHead = 0;
				}
				isCanonical = radioButtonRight->Checked;
				printArray();
				noChangeForm(true);
				timer1->Start();
			}
		}
	}

	private: System::Void textBoxNumberOfOffset_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::Enter: button1_Click(sender, e); break;
		case Keys::Up: textBoxArray->Focus(); break;
		default:
			break;
		}
	}

	private: System::Void textBoxArray_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::Enter: button1_Click(sender, e); break;
		case Keys::Down: textBoxNumberOfOffset->Focus(); break;
		default:
			break;
		}
	}
	};
}
