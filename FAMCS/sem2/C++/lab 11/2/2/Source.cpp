#include "Header.h"

int main(){
	try{
		setlocale(LC_ALL, ".1251");
		ifstream fin("Students.txt");
		if (!fin)
			throw ex(fin);
		string fio;
		int course, group;
		bool flag = false;
		vector<Student> v;
		while (fin.good()){
			if (!(fin >> fio))
				continue;
				fin >> course >> group;
			flag = true;
			try{
				Student s(fio, course, group);
				v.push_back(s);
			}
			catch (ex& e){ cout << e.what() << endl; }
			fio.clear();
		}
		if (!flag)
			throw ex(flag);
		fin.close();
		ofstream fout1("Fio.txt", ios_base::trunc), fout2("Groups.txt", ios_base::trunc);
		if (!fout1 || !fout2)
			throw ex(fout1);

		sort(v.begin(), v.end(), 
			[](const Student& a, const Student& b){ 
			return a.getFIO() < b.getFIO(); }
		);
		for (Student i : v)
			fout1 << i;
		fout1.close();

		sort(v.begin(), v.end(),
			[](const Student& a, const Student& b){
			if (a.getCourse() < b.getCourse())
				return true;
			if (a.getCourse() == b.getCourse())
				if (a.getGroup() < b.getGroup()){
					return true;
					if (a.getGroup() == b.getGroup())
						if (a.getFIO() < b.getFIO())
							return true;
				}
			return false;
		}
		);
		for (Student i : v)
			fout2 << i;
		fout2.close();
	}
	catch (ex& e){ cout << e.what() << endl; }
	return 0;
}