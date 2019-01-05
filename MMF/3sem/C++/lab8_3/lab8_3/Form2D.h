#pragma once
#define M_PI 3.14159265358979323846

namespace lab8_3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2D
	/// </summary>
	public ref class Form2D : public System::Windows::Forms::Form
	{
	public:
		Form2D(void)
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
		~Form2D()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(35, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(493, 428);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(552, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"начало по x:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(557, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"конец по x:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(641, 62);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"-5";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(641, 123);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"5";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(569, 306);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 130);
			this->button1->TabIndex = 5;
			this->button1->Text = L"нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2D::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(557, 185);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"начало по y:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(557, 242);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"конец по y:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(641, 182);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"-10";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(641, 242);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 9;
			this->textBox4->Text = L"10";
			// 
			// Form2D
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(778, 480);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form2D";
			this->Text = L"Form2D";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int h = pictureBox1->Height, w = pictureBox1->Width;
		Bitmap^ logsp = gcnew Bitmap(w, h);
		Graphics^ gr = Graphics::FromImage(logsp);
		//оси
		Pen^ myPen = gcnew Pen(Color::Black, 2);
		gr->DrawLine(myPen, 0, h*0.5, w, h*0.5);
		gr->DrawLine(myPen, w*0.5, 0, w*0.5, h);

		gr->DrawLine(myPen, w - 25, h / 2 + 8, w, h / 2);
		gr->DrawLine(myPen, w - 25, h / 2 - 8, w, h / 2);
		gr->DrawLine(myPen, w / 2 - 8, 25, w / 2, 0);
		gr->DrawLine(myPen, w / 2 + 8, 25, w / 2, 0);
		gr->DrawString("X", this->Font, Brushes::Black, w - 15, h / 2 - 25);
		gr->DrawString("Y", this->Font, Brushes::Black, w / 2 - 25, 5);

		
		double x1, x2, y1, y2, x, y, mx, my, x0, y0, dx, dt;

		x1 = Convert::ToDouble(textBox1->Text);   
		x2 = Convert::ToDouble(textBox2->Text);
		y1 = Convert::ToDouble(textBox3->Text);
		y2 = Convert::ToDouble(textBox4->Text);
		dx = 0.001;     // step

		x = x1;
		while (x <= x2)
		{
			y = f(x);
			if (y < y1) y1 = y;
			if (y > y2) y2 = y;
			x += dx;
		}

		my = 0.5*h / (y2 - y1);           // mashtab po osi y
		mx = w / (x2 - x1);                 // mashtab po osi x

		x = x1;
		y1 = f(x1);
		x += dx;
		// График
		while (x <= x2)
		{
			y = f(x);
			gr->DrawLine(gcnew Pen(Color::Blue, 2), (int)(x1*mx + w / 2), (int)(h / 2 - y1*my), (int)(x*mx + w / 2), (int)(h / 2 - y*my));
			x1 = x;
			y1 = y;
			x += dx;
		}




		x1 = Convert::ToDouble(textBox1->Text);
		x2 = Convert::ToDouble(textBox2->Text);
		y1 = Convert::ToDouble(textBox3->Text);
		y2 = Convert::ToDouble(textBox4->Text);
		dx = 0.001;     // step
		x = x1;
		while (x <= x2)
		{
			y = f1(x);
			if (y < y1) y1 = y;
			if (y > y2) y2 = y;
			x += dx;
		}
		my = 0.5*h / (y2 - y1);           // mashtab po osi y
		mx = w / (x2 - x1);                 // mashtab po osi x
		x = x1;
		y1 = f1(x1);
		x += dx;
		// График
		while (x <= x2)
		{
			y = f1(x);
			gr->DrawLine(gcnew Pen(Color::Red, 2), (int)(x1*mx + w / 2), (int)(h / 2 - y1*my), (int)(x*mx + w / 2), (int)(h / 2 - y*my));
			x1 = x;
			y1 = y;
			x += dx;
		}

		pictureBox1->Image = logsp;
	}

			 double f(double x)
			 {
				 return -0.5*Math::Exp(x);
			 }

			 double f1(double x)
			 {
				 return x*x-Math::Sin(M_PI*x*x);
			 }
	};
}
