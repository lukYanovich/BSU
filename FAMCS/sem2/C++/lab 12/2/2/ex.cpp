#include "ex.h"

ex::ex(const char* _filename, const ifstream& fin){
	msg = "file \"";
	msg += _filename;
	msg += "\" not open.";
}

ex::ex(const ifstream& fin, const char* _filename){
	msg = "file \"";
	msg += _filename;
	msg += "\" is empty.";
}