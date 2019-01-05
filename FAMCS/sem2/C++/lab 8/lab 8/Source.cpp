#include "LQueue.h"
#include "CQueue.h"

void _Print(InfoType& a) { cout << a << ' '; }

int main()
{
	CQueue a(4);
	LQueue b;
	try{
		a.Push(0);
		a.Push(1);
		a.Push(2);
		a.Push(3);
		a.ForEach(_Print); cout << endl;
		b = a;
		b.ForEach(_Print); cout << endl;
	}
	catch (exception& ex){
		cout << ex.what() << endl;
	}
	return 0;
}