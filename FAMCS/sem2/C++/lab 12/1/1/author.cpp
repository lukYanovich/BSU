#include "author.h"

author::author(const string& _surname, const string& _name, const string& _middleName){
	surname = _surname;
	name = _name;
	middleName = _middleName;
}

ostream& operator<<(ostream& os, const author& a){
	os << a.surname << ' ' << a.name << ' ' << a.middleName;
	return os;
}

bool author::operator==(const author& a){
	if (surname == a.surname && name == a.name && middleName == a.middleName)
		return true;
	return false;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


ex::ex(const string& a, const int& b){
	string temp;
	stringstream ss;
	ss << b;
	ss >> temp;
	msg = a;
	msg += " \"";
	msg += temp;
	msg += "\" isn't true";
}

ex::ex(const string& _fileName, const ifstream& fin){
	msg = "file \"";
	msg += _fileName;
	msg += "\" not open";
}

ex::ex(const ifstream& fin, const string& _fileName){
	msg = "file \"";
	msg += _fileName;
	msg += "\" is empty";
}

ex::ex(const string& a) { msg = a; }

ex::ex(const string& _fileName, const ofstream&){
	msg = "file \"";
	msg += _fileName;
	msg += "\" not open";
}