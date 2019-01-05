#include "Bus.h"


int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	try {
		vector<Bus> arr = create("input.txt");
		ofstream fout("output.txt", ios_base::trunc);
		if (!fout.is_open())
			throw exception("выходной файл не открыт");
		fout << "полный список:";
		print(fout, arr);
		fout << endl <<"******************************************************************\n"<< endl;
		string t;
		while (true) {
			char ch;
			cout << "1 - список автобусов для заданного номера маршрута\n"
				<< "2 - список автобусов, которые эксплуатируются больше 10 лет\n"
				<< "3 - список автобусов, пробег у которых больше 10 000 км\n"
				<< "0 - выход из программы." << endl << "\nваш выбор: ";
			cin >> ch;
			if (ch < '0' || ch > '3') {
				cout << "неверный выбор\n\n";
				continue;
			}
			cout << endl;

			switch (ch) {
			case '1':
				cout << "\nвведите номер маршрута: ";
				cin.ignore();
				getline(cin, t);
				fout << "\n\nсписок для номера маршрута: " << t << endl;
				for (auto i : arr)
					if (i.getNumberOfRoute().compare(t) == 0)
						fout << i;
				fout << endl << endl;
				break;
			case '2':
				fout << "\n\n\nсписок автобусов, которые эксплуатируются больше 10 лет:";
				for (auto i : arr)
					if (i.getReleaseYear() <= 2007)
						fout << i;
				fout << endl << endl;
				break;
			case '3':
				fout << "\n\n\nсписок автобусов, пробег у которых больше 10 000 км";
				for (auto i : arr)
					if (i.getMileage() > 10000)
						fout << i;
				fout << endl << endl;
				break;
			default:
				throw exception("работа завершена");
				break;
			}
		}
	}
	catch (exception& ex) { cerr << ex.what() << endl; }
	return 0;
}
