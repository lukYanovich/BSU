#include "library.h"
void _read(library&);
void _show(const list<book>);
void _show(library&);
void _delbook(const char*, library&);
void _searchBook(const char*, library&);
void _searchAuthor(const char*, const char*, const char*, library&);
void _addAuthorInBook(const char*, const char*, const char*, const char*, library&);
void _delAuthorInBook(const char*, const char*, const char*, const char*, library&);

const char* sep = "/////////////////////////////////////////////////////////////////////////////////////////\n";
const char* outfile = "output.txt";


int main(){
	setlocale(LC_ALL, ".1251");
	try{
		ofstream fout(outfile, ios_base::trunc);
		if (!fout)
			throw ex(outfile, fout);
		fout.close();
		library lib;
		_read(lib);
		_delbook("Лошица_", lib);
		_searchBook("Бородино", lib);
		_searchAuthor("Ковалёв", "Михаил", "Александрович", lib);
		_addAuthorInBook("Прохоровка", "Лазарев", "Михаил", "Александрович", lib);		//"Холмский", "Аркадий", "Петрович"
		_delAuthorInBook("Бородино", "Круль", "Ярослав", "Игнатьевич", lib);

		cout << "данные успешно записаны в файл." << endl;
	}
	catch (exception& e){ cout << e.what() << endl; }
	return 0;
}


void _read(library& l){
	l.Add(2, "Прохоровка", 1988, "a1.txt");
	l.Add(85445, "Бородино", 1999, "a2.txt");
	l.Add(784, "Лошица", 2010, "a3.txt");
	_show(l);
}

void _show(const list<book> l){
	for (auto i : l)
		cout << i;
	cout << endl;
}

void _show(library& l){
	ofstream fout(outfile, ios_base::app);
	if (!fout)
		throw ex(outfile, fout);
	fout << sep << "\nкниги в библиотеке:\n\n" << l << sep;
	fout.close();
}

void _delbook(const char* nameBook, library& l){
	ofstream fout(outfile, ios_base::app);
	if (!fout)
		throw ex(outfile, fout);
	fout << "\nудаление книги \"" << nameBook << "\":\n";
	if (l.Del(nameBook))
		fout << "\nкнига \"" << nameBook << "\" удалена." << endl << endl;
	else
		fout << "\nв библиотеке нет книги \"" << nameBook << '\"' << endl << endl;
	fout.close();
	_show(l);
}

void _searchBook(const char* nameBook, library& l){
	ofstream fout(outfile, ios_base::app);
	if (!fout)
		throw ex(outfile, fout);
	fout << "\nпоиск книг \"" << nameBook << "\":\n\n";
	try{
		for (auto i : l.SearchBook(nameBook))
			fout << i << endl;
	}
	catch (exception& e){ fout << e.what() << endl << endl; }	
	fout << sep;
	fout.close();
}

void _searchAuthor(const char* surname, const char* name, const char* middlename, library& l){
	ofstream fout(outfile, ios_base::app);
	if (!fout)
		throw ex(outfile, fout);
	fout << "\nпоиск книг автора \"" << surname << ' ' << name << ' ' << middlename << "\":\n\n";
	try{
		for (auto i : l.SearchAuthor(surname, name, middlename))
			fout << i << endl;
	}
	catch (exception& e){ fout << e.what() << endl << endl; }
	fout << sep;
	fout.close();
}

void _addAuthorInBook(const char* nameBook, const char* surname, const char* name, const char* middlename, library& l){
	ofstream fout(outfile, ios_base::app);
	if (!fout)
		throw ex(outfile, fout); 
	fout << "\nдобавление автора \"" << surname << ' ' << name << ' ' << middlename << "\" в книгу \"" << nameBook << "\":\n\n";
	try{
		l.SearchBook(nameBook);
		if (l._addAuthorInBook(nameBook, surname, name, middlename))
			fout << "автор успешно добавлен.\n\n";
		else
			fout << "такой автор уже есть.\n\n";
	}
	catch (exception& e){ fout << e.what() << endl << endl; }
	fout.close();
	_show(l);
}

void _delAuthorInBook(const char* nameBook, const char* surname, const char* name, const char* middlename, library& l){
	ofstream fout(outfile, ios_base::app);
	if (!fout)
		throw ex(outfile, fout);
	fout << "\nудаление автора \"" << surname << ' ' << name << ' ' << middlename << "\" из книги \"" << nameBook << "\":\n\n";
	try{
		l.SearchBook(nameBook);
		if (l._delAuthorInBook(nameBook, surname, name, middlename))
			fout << "автор успешно удалён.\n\n";
		else
			fout << "такого автора нет.\n\n";
	}
	catch (exception& e){ fout << e.what() << endl << endl; }
	fout.close();
	_show(l);
}