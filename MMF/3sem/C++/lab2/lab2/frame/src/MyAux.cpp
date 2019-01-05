#include "../include/MyAux.h"


void checkOfEmpty(string str) {
	regex reg("^\\s*$");
	if (regex_match(str, reg))
		throw exception("строка пуста");
}

void repairArr(vector<string>& arr) {
	for (size_t i(0); i < arr.size(); i++)
		if (arr[i].empty())
			arr.erase(arr.begin() + i--);
}

int toNumber(string s) { return atoi(s.c_str()); }
double toDouble(string s) { return atof(s.c_str()); }
