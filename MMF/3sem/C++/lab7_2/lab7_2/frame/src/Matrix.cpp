#include "../includes/Matrix.h"


Matrix::Matrix(String^ in, RichTextBox^ out, int i, int j)
{
	String^ t = "\n";
	array<Char>^ delimFirst = t->ToCharArray();
	t = " ,;";
	array<Char>^ delimSecond = t->ToCharArray();
	array<String^>^ arrStr = in->Split(delimFirst);
	for each (String^ str in arrStr)
	{
		array<String^>^ tArr = str->Split(delimSecond);
		List<int>^ tempList = gcnew List<int>();
		for each (String^ s in tArr)
		{
			tempList->Add(Convert::ToInt32(s));
		}
		this->arr->Add(tempList);
	}
	int sizeOfLists = this->arr[i]->Count;
	for each(List<int>^ list in this->arr)
		if (list->Count != sizeOfLists)
			throw gcnew Exception("задана не матрица");
	findMin();
	this->Ireq = i;
	this->Jreq = j;
}

void Matrix::printToTextBox(RichTextBox^ textBox)
{
	textBox->Clear();
	for (int i = 0; i < this->arr->Count; i++)
	{
		List<int>^ temp = this->arr[i];
		for (int j = 0; j < temp->Count; j++)
		{
			textBox->SelectionStart = textBox->TextLength;
			textBox->SelectionLength = 0;
			System::Drawing::Color color;
			if (i == Inow || j == Jnow)
				color = System::Drawing::Color::Red;
			textBox->SelectionColor = color;
			textBox->AppendText(Convert::ToString(temp[j]) + " ");
			textBox->SelectionColor = textBox->ForeColor;
		}
		textBox->AppendText("\r\n");
	}
}

void Matrix::findMin()
{
	int min = Int32::MaxValue;
	for (int i = 0; i < this->arr->Count; i++)
	{
		List<int>^ temp = this->arr[i];
		for (int j = 0; j < temp->Count; j++)
			if (temp[j] < min)
			{
				min = temp[j];
				Inow = i;
				Jnow = j;
			}
	}
}

bool Matrix::doIteration(RichTextBox^ out)
{
	if (Ireq == Inow && Jreq == Jnow)
		return false;
	if (count == 0)
	{
		printToTextBox(out);
		return ++count;
	}
	if (Inow < Ireq)
	{
		lineDown(Inow++);
		printToTextBox(out);
		return true;
	}
	else if (Inow > Ireq)
	{
		lineUp(Inow--);
		printToTextBox(out);
		return true;
	}
	if (Jnow < Jreq)
	{
		rowRigth(Jnow++);
		printToTextBox(out);
		return true;
	}
	else if (Jnow > Jreq)
	{
		rowLeft(Jnow--);
		printToTextBox(out);
		return true;
	}
	return true;
}

void Matrix::operator=(const Matrix^ o)
{
	this->arr = o->arr;
	this->Inow = o->Inow;
	this->Jnow = o->Jnow;
	this->Ireq = o->Ireq;
	this->Jreq = o->Jreq;
}

void Matrix::lineUp(int i)
{
	List<int>^ temp1 = this->arr[i];
	List<int>^ temp2 = this->arr[i - 1];
	for (int j = 0; j < temp1->Count; j++)
	{
		int temp = temp1[j];
		temp1[j] = temp2[j];
		temp2[j] = temp;
	}
}

void Matrix::lineDown(int i)
{
	List<int>^ temp1 = this->arr[i];
	List<int>^ temp2 = this->arr[i + 1];
	for (int j = 0; j < temp1->Count; j++)
	{
		int temp = temp1[j];
		temp1[j] = temp2[j];
		temp2[j] = temp;
	}
}

void Matrix::rowLeft(int j)
{
	for (int i = 0; i < this->arr->Count; i++)
	{
		List<int>^ temp = this->arr[i];
		int buff = temp[j];
		temp[j] = temp[j - 1];
		temp[j - 1] = buff;
	}
}

void Matrix::rowRigth(int j)
{
	for (int i = 0; i < this->arr->Count; i++)
	{
		List<int>^ temp = this->arr[i];
		int buff = temp[j];
		temp[j] = temp[j + 1];
		temp[j + 1] = buff;
	}
}