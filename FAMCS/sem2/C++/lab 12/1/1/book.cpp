#include "book.h"

book::book(const int& _udk, const string& _nameBook, const int& _crYear){
	if (_udk < 1)
		throw ex("udk", _udk);
	if (_crYear < 1)
		throw ex("creates year", _crYear);
	udk = _udk;
	nameBook = _nameBook;
	crYear = _crYear;
}

ostream& operator<<(ostream& os, book& Book){
	Book.authorList.sort(
		[](author a, author b){
			if (a.getSurname() < b.getSurname())
				return true;
			return false;
		}
	);
	os << Book.udk << " \"" << Book.nameBook << "\" " << Book.crYear << ". список авторов:\n";
	for (auto i : Book.authorList)
		os << i << endl;
	return os;
}

bool book::addAuthor(const string& _surname, const string& _name, const string& _middleName){
	author a(_surname, _name, _middleName);
	for (auto i : authorList)
		if (i == a)
			return false;
	authorList.push_back(a);
	return true;
}

bool book::delAuthor(const string& _surname, const string& _name, const string& _middleName){
	author a(_surname, _name, _middleName);
	bool flag = false;
	for (auto i = authorList.begin(); i != authorList.end();)
		if ((*i) == a){
			i = authorList.erase(i);
			flag = true;
		}
		else
			i++;
	if (flag)
		return true;
	else
		return false;
}