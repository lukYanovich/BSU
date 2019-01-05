#include "library.h"

void library::Add(const int& _udk, const string& _nameBook, const int& _crYear, const string& _fileWithAuthors){
	ifstream fin(_fileWithAuthors);
	if (!fin)
		throw ex(_fileWithAuthors, fin);
	book Book(_udk, _nameBook, _crYear);
	bool flag = false;
	while (fin.good()){
		string surname, name, middleName;
		fin >> surname >> name >> middleName;
		bool _flag = false;
		if (!Book.getListauthor().empty()){
			author a(surname, name, middleName);
			for (auto i : Book.getListauthor())
				if (i == a){
					_flag = true;
					break;
				}
		}
		if (!_flag)
			Book.addAuthor(surname, name, middleName);
		surname.clear();
		name.clear();
		middleName.clear();
		flag = true;
	}
	fin.close();
	if (!flag)
		throw ex(fin, _fileWithAuthors);
	bookList.push_back(Book);
}

bool library::Del(const string& _nameBook){
	bool flag = false;
	for (list<book>::iterator i = bookList.begin(); i != bookList.end();)
		if (i->getNameBook() == _nameBook){
			i = bookList.erase(i);
			flag = true;
		}
		else
			i++;
	return flag;
}

list<book> library::SearchAuthor(const string& _surname, const string& _name, const string& _middleName){
	list<book> temp;
	author a(_surname, _name, _middleName);
	for (auto i : bookList)
		for (auto j : i.getListauthor())
			if (j == a)
				temp.push_back(i);
	if (temp.empty())
		throw ex("таких книг нет");
	return temp;
}

list<book> library::SearchBook(const string& _nameBook){
	list<book> temp;
	for (auto i : bookList)
		if (i.getNameBook() == _nameBook)
			temp.push_back(i);
	if (temp.empty())
		throw ex("таких книг нет");
	return temp;
}

ostream& operator<<(ostream& os, library& lib){
	lib.bookList.sort(
		[](const book& a, const book& b){
			if (a.getNameBook() < b.getNameBook())
				return true;
			return false;
		}
	);
	for (auto i : lib.bookList)
		os << i << endl;
	return os;
}

bool library::_addAuthorInBook(const string& _nameBook, const string& _surname, const string& _name, const string& _middleName){
	bool flag = false;
	for (auto &i : bookList)
		if (i.getNameBook() == _nameBook){
			flag = true;
			for (auto j : i.getListauthor())
				if (j.getSurname() == _surname && j.getName() == _name && j.getMiddleName() == _middleName){
					flag = false;
					break;
				}
			if (flag)
				i.addAuthor(_surname, _name, _middleName);
		}
	return flag;
}

bool library::_delAuthorInBook(const string& _nameBook, const string& _surname, const string& _name, const string& _middleName){
	bool flag = false;
	for (auto &i : bookList)
		if (i.getNameBook() == _nameBook)
			if (i.delAuthor(_surname, _name, _middleName))	
				flag = true;
	return flag;
}