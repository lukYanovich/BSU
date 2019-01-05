#pragma once
#include "author.h"

class book{
public:
	book(const int&, const string&, const int&);
	friend ostream& operator<<(ostream&, book&);
	bool addAuthor(const string&, const string&, const string&);
	bool delAuthor(const string&, const string&, const string&);
	const string getNameBook() const{ return nameBook; }
	list<author> getListauthor() const{ return authorList; }
private:
	int udk;
	string nameBook;
	int crYear;
	list<author> authorList;

	book() { assert(false); }
};