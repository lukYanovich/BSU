#include "ex.h"

ex::ex(const char* _filename, const ifstream&){
	msg = "file \"";
	msg += _filename;
	msg += "\" not open.";
}

ex::ex(const ifstream&, const char* _filename){
	msg = "file \"";
	msg += _filename;
	msg += "\" is empty or not true.";
}

ex::ex(const int n){
	stringstream ss;
	ss << n;
	string temp;
	ss >> temp;
	msg = "в множестве нет простых элементов <=\"";
	msg += temp;
	msg += '\"';
}