#include "ex.h"

ex::ex(const char* _filename, const ifstream&){
	msg = "input file \"";
	msg += _filename;
	msg += "\" not open";
}

ex::ex(const ifstream&, const char* _filename){
	msg = "input file \"";
	msg += _filename;
	msg += "\" is empty or not true";
}

ex::ex(const char* _filename, const ofstream&){
	msg = "output file \"";
	msg += _filename;
	msg += "\" not open";
}