#include "../frame/include/Set.h"
typedef double myType;
//double через ',' в файле вводится


template<class T> Set<T> func(Set<T> a, Set<T> b) {
	return (a + b) - a * b;
}


template<class T> void _print(ostream& is,const Set<T>& a) {
	is << "{ " << a << " }" << endl;
}


int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	try {
		string BaseDir = "C:\\Projects\\MMF\\3sem\\C++\\lab2\\lab2\\resources\\", fileIn = "input.txt", fileOut = "output.txt";
		ifstream fin(BaseDir + fileIn);
		if (!fin.is_open())
			throw exception("входной файл не открыт");

		Set<myType> a;
		Set<myType> b;
		fin >> a >> b;
		fin.close();

		ofstream fout(BaseDir + fileOut, ios_base::trunc);
		if (!fout.is_open())
			throw exception("выходной файл не открыт");
		fout << "A: "; _print(fout, a);
		fout << "B: "; _print(fout, b);
		fout << "A + B: "; _print(fout, a + b);
		fout << "A - B: "; _print(fout, a - b);
		fout << "A * B: "; _print(fout, a * b);

		fout << "(A + B)/(A * B): "; _print(fout, func(a, b));
		fout.close();
	}
	catch (exception& e) { cerr << e.what() << endl; }
	return 0;
}
