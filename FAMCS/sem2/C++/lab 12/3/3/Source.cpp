#include "ex.h"

int main(){
	setlocale(LC_ALL, ".1251");
	_set a;
	try{
		_read(a, "input.txt");
		const int n = 20;	//до какого числа искать
		_search(a, n);
	}
	catch (exception& e){ cout << e.what() << endl; }
	return 0;
}