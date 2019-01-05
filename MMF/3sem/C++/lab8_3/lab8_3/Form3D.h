#pragma once

namespace lab8_3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form3D
	/// </summary>
	public ref class Form3D : public System::Windows::Forms::Form
	{
	public:
		Form3D(void)
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
		~Form3D()
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
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button1;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(610, 450);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(644, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"начало по x:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(647, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"конец по x:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(647, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"начало по y:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(752, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"-1.5";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(752, 79);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"1.5";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(752, 135);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L"-1.5";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(752, 179);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 7;
			this->textBox4->Text = L"1.5";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(752, 243);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 8;
			this->textBox5->Text = L"-1.5";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(752, 292);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 9;
			this->textBox6->Text = L"1.5";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(652, 179);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"конец по y:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(652, 243);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"начало по z:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(657, 292);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"конец по z:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(650, 340);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 101);
			this->button1->TabIndex = 13;
			this->button1->Text = L"нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form3D::button1_Click);
			// 
			// Form3D
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(936, 481);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form3D";
			this->Text = L"Form3D";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		int h = pictureBox1->Height, w = pictureBox1->Width;
		Bitmap^ pic = gcnew Bitmap(w, h);
		Graphics^ gr = Graphics::FromImage(pic);

		int i3, j3;
		int i1, j1, i2, j2;
		array<int>^ a1;
		array<int>^ a2;
		a1 = gcnew array<int>(2);
		a2 = gcnew array<int>(2);
		IJ(0, 0, 0, a1);

		//Рисуем и подписываем ось x
		IJ(4, 0, 0, a2);
		gr->DrawLine(Pens::Red, a1[0], a1[1], a2[0], a2[1]);
		gr->DrawString("X", this->Font, Brushes::Red, a2[0] + 3, a2[1]);

		//Рисуем и подписываем ось y
		IJ(0, 4, 0, a2);
		gr->DrawLine(Pens::Red, a1[0], a1[1], a2[0], a2[1]);
		gr->DrawString("Y", this->Font, Brushes::Red, a2[0] + 3, a2[1]);

		//Рисуем и подписываем ось z
		IJ(0, 0, 4.3, a2);
		gr->DrawLine(Pens::Red, a1[0], a1[1], a2[0], a2[1]);
		gr->DrawString("Z", this->Font, Brushes::Red, a2[0] + 3, a2[1] - 3);

		for (j3 = 0; j3<25; j3++)
		{
			for (i3 = 0; i3<30; i3++)
			{
				IJ(h0 + h*i3, h0 + h*j3, F1(h0 + h*i3, h0 + h*j3), a1);
				ob[0].X = a1[0];
				ob[0].Y = a1[1];
				IJ(h0 + h*i3, h0 + h*(j3 + 1), F1(h0 + h*i3, h0 + h*(j3 + 1)), a1);
				ob[1].X = a1[0];
				ob[1].Y = a1[1];
				IJ(h0 + h*(i3 + 1), h0 + h*(j3 + 1), F1(h0 + h*(i3 + 1), h0 + h*(j3 + 1)), a1);
				ob[2].X = a1[0];
				ob[2].Y = a1[1];
				IJ(h0 + h*(i3 + 1), h0 + h*j3, F1(h0 + h*(i3 + 1), h0 + h*j3), a1);
				ob[3].X = a1[0];
				ob[3].Y = a1[1];
				gr->DrawPolygon(Pens::Blue, ob);
			}
		}
		
		pictureBox1->Image = pic;		
	}

					private:
						static double x0 = 4, Y0 = -0.5, z0 = 3, alf = 4.31, bet = 4.92, A = -6.5, a = -6.5;
						static double Xmin = -1.5, Xmax = 1.5, Ymin = -1.5, Ymax = 1.5;
						static int Width = 200, Height = 200;
						static double h = 0.1, h0 = 0.25;
						static array<Point>^ ob = gcnew array<Point>(4);

						//------------------------------------------------------------------------------
						//*********** void IJ(double x, double y, double z, array<int>^ ar) **********
private: void IJ(double x, double y, double z, array<int>^ ar)
{
	double Xn, Yn, Zn;

	//Осуществляем перенос системы координат в т.(x0,Y0,z0)
	Xn = (x - x0)*Math::Cos(alf) - (y - Y0)*Math::Sin(alf);
	Yn = ((x - x0)*Math::Sin(alf) + (y - Y0)*Math::Cos(alf))*Math::Cos(bet) - (z - z0)*Math::Sin(bet);
	Zn = ((x - x0)*Math::Sin(alf) + (y - Y0)*Math::Cos(alf))*Math::Sin(bet) + (z - z0)*Math::Cos(bet);

	//Делаем проекцию на плоскость
	Xn /= Zn / A + 1;
	Yn /= Zn / a + 1;

	//Масштабируем оси x и y
	ar[0] = Width*(Xn - Xmin) / (Xmax - Xmin);
	ar[1] = Height*(Yn - Ymax) / (Ymin - Ymax);
}
		 //******* void IJ(double x, double y, double z, array<int>^ ar) **********
		 //------------------------------------------------------------------------------

		 //------------------------------------------------------------------------------
		 //****** double F1(double x1,double y1) *****************************
	private: double F1(double x1, double y1)
	{
		return x1*y1*y1;
	}
		 //***** double F1(double x1,double y1) *****************************
		 //------------------------------------------------------------------------------



		 //Рисование поверхности
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		int i3, j3;
		int i1, j1, i2, j2;
		array<int>^ a1;
		array<int>^ a2;
		a1 = gcnew array<int>(2);
		a2 = gcnew array<int>(2);
		IJ(0, 0, 0, a1);

		//Рисуем и подписываем ось x
		IJ(4, 0, 0, a2);
		e->Graphics->DrawLine(Pens::Red, a1[0], a1[1], a2[0], a2[1]);
		e->Graphics->DrawString("X", this->Font, Brushes::Red, a2[0] + 3, a2[1]);

		//Рисуем и подписываем ось y
		IJ(0, 4, 0, a2);
		e->Graphics->DrawLine(Pens::Red, a1[0], a1[1], a2[0], a2[1]);
		e->Graphics->DrawString("Y", this->Font, Brushes::Red, a2[0] + 3, a2[1]);

		//Рисуем и подписываем ось z
		IJ(0, 0, 4.3, a2);
		e->Graphics->DrawLine(Pens::Red, a1[0], a1[1], a2[0], a2[1]);
		e->Graphics->DrawString("Z", this->Font, Brushes::Red, a2[0] + 3, a2[1] - 3);


		for (j3 = 0; j3<25; j3++)
		{
			for (i3 = 0; i3<30; i3++)
			{
				IJ(h0 + h*i3, h0 + h*j3, F1(h0 + h*i3, h0 + h*j3), a1);
				ob[0].X = a1[0];
				ob[0].Y = a1[1];
				IJ(h0 + h*i3, h0 + h*(j3 + 1), F1(h0 + h*i3, h0 + h*(j3 + 1)), a1);
				ob[1].X = a1[0];
				ob[1].Y = a1[1];
				IJ(h0 + h*(i3 + 1), h0 + h*(j3 + 1), F1(h0 + h*(i3 + 1), h0 + h*(j3 + 1)), a1);
				ob[2].X = a1[0];
				ob[2].Y = a1[1];
				IJ(h0 + h*(i3 + 1), h0 + h*j3, F1(h0 + h*(i3 + 1), h0 + h*j3), a1);
				ob[3].X = a1[0];
				ob[3].Y = a1[1];
				e->Graphics->DrawPolygon(Pens::Blue, ob);


			}
		}


	}

};
}
