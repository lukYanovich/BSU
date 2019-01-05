#include "Train.h"

int main(){
	try{
		setlocale(LC_ALL, ".1251");
		ifstream fin("input.txt");
		if (!fin)
			throw ex(fin);
		vector<Train> v;
		string city, type, TimeOut;
		int number, TimeWay;
		bool flag = false;
		while (fin.good()){
			if (!(fin >> number))
				continue;
			flag = true;
			fin >> city >> type >> TimeOut >> TimeWay;
			try{
				Train t(number, city, type, TimeOut, TimeWay);
				v.push_back(t);
			}
			catch (ex& e){ cout << e.what() << endl; }
			city.clear();
			type.clear();
			TimeOut.clear();
		}
		if (!flag)
			throw ex(flag);		
		//сортируем по времени
		sort(v.begin(), v.end(), [](const Train& a, const Train& b){ return sravT(a, b); });	
		f1(v);
		f2(v);
		f3(v);
		f4(v);
	}
	catch (ex& e){ cout << e.what() << endl; }
	cout << endl;
	return 0;
}


bool sravT(const Train& a, const Train& b){
	if (getHours(a.getTimeOut()) < getHours(b.getTimeOut()))
		return true;
	if (getHours(a.getTimeOut()) == getHours(b.getTimeOut()) && getMinutes(a.getTimeOut()) < getMinutes(b.getTimeOut()))
		return true;
	return false;
}

void f1(const vector<Train>& u){
	vector<Train> v;
	int h1 = 6, m1 = 10, h2 = 19, m2 = 50;
	for (ushort i(0); i < u.size(); ++i){
		if (getHours(u[i].getTimeOut()) > h1 && getHours(u[i].getTimeOut()) < h2){
			v.push_back(u[i]);
			continue;
		}
		if (getHours(u[i].getTimeOut()) == h1 || getHours(u[i].getTimeOut()) == h2 && getMinutes(u[i].getTimeOut()) >= m1 && getMinutes(u[i].getTimeOut()) <= m2)
			v.push_back(u[i]);
	}
	cout << "поезда с \"" << h1 << ':' << m1 << "\" по \"" << h2 << ':' << m2 << '\"' << endl;
	for (Train i : v)
		cout << i << endl;
}

void f2(const vector<Train>& u){
	vector<Train> v;
	string city = "Brest";
	for (ushort i(0); i < u.size(); ++i)
		if (u[i].getCity() == city)
			v.push_back(u[i]);
	cout << "\nпоезда, едущие в \"" << city << '\"' << endl;
	for (Train i : v)
		cout << i << endl;
}

void f3(const vector<Train>& u){
	vector<Train> v;
	string city = "Brest";
	for (ushort i(0); i < u.size(); ++i)
		if (u[i].getCity() == city && u[i].getType() == "fast")
			v.push_back(u[i]);
	cout << "\nскорые поезда, едущие в \"" << city << '\"' << endl;
	for (Train i : v)
		cout << i << endl;
}

void f4(const vector<Train>& u){
	Train a(u[0]);
	string city = "Brest";
	int max = INT_MAX;
	for (ushort i(0); i < u.size(); ++i)
		if (u[i].getCity() == city && u[i].getTimeWay() < max){
			max = u[i].getTimeWay();
			a = u[i];
		}
	cout << "\nсамый быстрый поезд, едущий в \"" << city << '\"' << endl << a << endl;
}