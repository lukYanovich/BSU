#include "TDeque.h"
typedef char* myType;

template<class T> void _Print(T a) { cout << a << ' '; }
template<> void _Print<char*>(char* a) { cout << " || " << a << " || "; }

int main(){
	try{
		TDeque<myType> a;
		a.PushFront("gg");
		a.PushFront("kek");
		a.PushRear("lol");
//		a.ForEach(_Print); cout << endl;
		a.PopFront();
		a.PopRear();
		a.ForEach(_Print); cout << endl;

		TDeque<myType> b;
		b = a;
		b.ForEach(_Print); cout << endl;

	}
	catch (exception& ex) { cout << ex.what() << endl; }
	return 0;
}