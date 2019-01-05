#include "ex.h"

int main(){
	setlocale(LC_ALL, ".1251");
	word a;
	try{
		_read(a, "input.txt");
		for (auto i : a)
			cout << i.first << " : " << i.second << endl;
	}
	catch (exception& e){ cout << e.what() << endl; }
	return 0;
}