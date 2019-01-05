#include "func.h"
typedef int myType;

int main(){
	try{
		unsigned n = 5, m = 5;
		myType** arr = nullptr;

		_createByHands(arr, n, m);
		_show(arr, n, m);
		cout << "column: " << _search<myType>(arr, n, m) << endl;
		_delete(arr, n, m);
	}
	catch (exception& ex) { cout << ex.what() << endl; }
	return 0;
}