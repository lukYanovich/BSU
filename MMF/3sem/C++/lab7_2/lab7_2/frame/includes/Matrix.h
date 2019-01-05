#pragma once
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System;

public ref class Matrix
{
private:
	List<List<int>^>^ arr = gcnew List<List<int>^>();
	int Inow = 0, Jnow = 0, Ireq, Jreq, count=0;

public:
	Matrix() {}
	Matrix(String^, RichTextBox^, int, int);
	Matrix(Matrix^ o) : arr(o->arr), Inow(o->Inow), Jnow(o->Jnow), Ireq(o->Ireq), Jreq(o->Jreq) {}
	void printToTextBox(RichTextBox^);
	void findMin();
	void operator=(const Matrix^);

	bool doIteration(RichTextBox^);
	void lineUp(int);
	void lineDown(int);
	void rowRigth(int);
	void rowLeft(int);
};