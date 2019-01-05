#include "Train.h"

const int getHours(const string& a){
	string temp;
	temp = a[0];
	temp += a[1];
	const char* t = temp.c_str();
	return (strtol(t, 0, 0));
}

const int getMinutes(const string& a){
	string temp;
	temp = a[3];
	temp += a[4];
	const char* t = temp.c_str();
	return (strtol(t, 0, 0));
}

bool f(const char& a){
	if (a <= '9' && a >= '0')
		return true;
	return false;
}

bool _check(const string& a){
	if (a.length() == 5)
		if (f(a[0]) && f(a[1]) && a[2] == ':' && f(a[3]) && f(a[4]))
			if (getHours(a) < 25 && getMinutes(a) < 60)
				return true;
	return false;
}

Train::Train(const int _number, const string& _city, const string& _type, const string& _TimeOut, const int _TimeWay){
	if (_type != "pass" && _type != "fast"){
		TrainType w = pass;
		throw ex(w);
	}
	if (!_check(_TimeOut))
		throw ex(_TimeOut);
	if (_number <= 0)
		throw ex(_number);
	if (_TimeWay <= 0)
		throw ex(_number);
	number = _number;
	city = _city;
	type = _type;
	TimeOut = _TimeOut;
	TimeWay = _TimeWay;
}

Train::Train(const Train& a){
	number = a.number;
	city = a.city;
	type = a.type;
	TimeOut = a.TimeOut;
	TimeWay = a.TimeWay;
}

ostream& operator<<(ostream& os, const Train& a){
	os << a.number << ' ' << a.city << ' '<< a.type << ' ' << a.TimeOut << ' ' << a.TimeWay;
	return os;
}


ex::ex(TrainType a){ msg = "неверный тип поездa"; }

ex::ex(const string& a){
	msg = "время \"";
	msg += a;
	msg += "\" неверно";
}

ex::ex(const int a){
	stringstream ss;
	ss << a;
	string temp;
	ss >> temp;
	msg = "число \"";
	msg += temp;
	msg += "\" не подходит по условию";
}

ex::ex(const bool& a) { msg = "входной файл пуст"; }

ex::ex(const ifstream& fin) { msg = "входной файл не открыт"; }

ex::ex(const ofstream& fout) { msg = "выходной файл не открыт"; }