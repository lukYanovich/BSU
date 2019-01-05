#include "Bus.h"
char* Bus::separator = "  |  ";


Bus::Bus() {
	this->FIO = this->numberOfBus = this->numberOfRoute = this->brand = "";
	this->releaseYear = this->mileage = 0;
}


ostream& Bus::show(ostream& os) {
	char* sep = "------------------------------------------------------------------";
	os << endl << sep << endl << this->FIO << separator << this->numberOfBus << separator << this->numberOfRoute << separator
		<< this->brand << separator << this->releaseYear << separator << this->mileage;
	return os;
}


ostream& operator<<(ostream& os, Bus& a) {
	return a.show(os);
}


bool isNumber(string s){
	return s.find_first_not_of("1234567890") == string::npos;
}


size_t toNumber(string s, int i) {
	if (!isNumber(s)) {
		cerr << ("не является числом") << endl;
		invalidDateInLine(i);
	}
	int temp = atoi(s.c_str());
	if (temp < 0) {
		cerr << ("отрицательное число") << endl;
		invalidDateInLine(i);
	}
	return (size_t)temp;
}


void invalidDateInLine(int i) {
	string str = "в строке \'";
	str += to_string(i);
	str += "\' неверные данные";
	throw exception(str.c_str());
}


vector<Bus> create(const char* filename) {
	ifstream fin(filename);
	if (!fin.is_open())
		throw exception("входной файл не открыт.");

	vector<Bus> arr;
	for (int i = 1; fin.good(); i++) {
		try {
			string str;
			getline(fin, str);
			if (str.empty())
				continue;

			vector<string> arrStr;
			boost::split(arrStr, str, boost::is_any_of(" "));
			for (size_t j(0); j < arrStr.size(); j++)
				if (arrStr[j].empty())
					arrStr.erase(arrStr.begin() + j--);
			if (arrStr.size() != 8)
				invalidDateInLine(i);

			for (auto i : arr)
				if (i.getNumberOfBus().compare(arrStr[3]) == 0)
					throw exception("");

			Bus temp;
			str = arrStr[0] + " " + arrStr[1] + " " + arrStr[2];
			temp.setFIO(str);
			temp.setNumberOfBus(arrStr[3]);
			temp.setNumberOfRoute(arrStr[4]);
			temp.setBrand(arrStr[5]);
			temp.setReleaseYear(toNumber(arrStr[6], i));
			temp.setMileage(toNumber(arrStr[7], i));

			arr.push_back(temp);
		}
		catch (exception& e) { cerr << e.what() << endl; }
	}
	fin.close();
	return arr;
}


void print(ostream& os, vector<Bus>& arr) {
	for (auto i : arr)
		os << i << endl;
}
