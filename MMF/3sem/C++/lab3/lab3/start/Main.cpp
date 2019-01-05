#include "../frame/include/List.h"
#include "../frame/include/MyAux.h"
#include <fstream>


void check(List, List, ostream&);


int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	try {
		string BaseDir = "C:\\Projects\\MMF\\3sem\\C++\\lab3\\lab3\\resources\\",
			fileInOne = "input1.txt", fileInTwo = "input2.txt", fileOutOne = "output.txt";
		ifstream fin(BaseDir + fileInOne);
		if (!fin.is_open())
			throw exception("входной файл не открыт");

		List a, b;
		fin >> a;
		fin.close();
		fin.open(BaseDir + fileInTwo);
		fin >> b;
		fin.close();

		ofstream fout(BaseDir + fileOutOne, ios_base::trunc);
		if (!fout.is_open())
			throw exception("выходной файл не открыт");
		//		a.indexOf(100);
		fout << "list1: { " << a << " }" << endl;
		fout << "list2: { " << b << " }" << endl;
		check(a, b, fout);
		fout.close();
	}
	catch (exception& e) {
		MyAux::printException(e);
	}
	return 0;
}


void check(List a, List b, ostream& fout) {
	fout << "совпадения: ";
	if (b.size() >= a.size())
		for (size_t i(0); i < b.size(); i++)
			if (b.get(i) == a.get(0)) {
				bool flag = false;
				for (size_t j(0); j < a.size(); j++)
					if (b.get(i+j) != a.get(j)) {
						flag = true;
						break;
					}
				if (flag == false) {
					fout << "да\nпозиция во втором списке: " << i + 1 << endl;
					return;
				}
			}
	fout << "нет" << endl;
}
