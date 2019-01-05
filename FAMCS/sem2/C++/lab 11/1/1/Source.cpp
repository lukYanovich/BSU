#include "func.h"

int main(){
	setlocale(LC_ALL, ".1251");
	vector<int> v;
	_enter(v);

	int temp = f1(v);
	f2(v);
	f3(v);
	f4(v);
	f5(v, temp);
	try{ f6(v); }
	catch (exception& ex){ cout << ex.what() << endl; }
	f7(v);
	f8(v);
	return 0;
}