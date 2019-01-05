#pragma once
#include "book.h"

class library
{
public:
	void Add(const int&, const string&, const int&, const string&);
	bool Del(const string&);
	list<book> SearchAuthor(const string&, const string&, const string&);
	list<book> SearchBook(const string&);
	bool _addAuthorInBook(const string&, const string&, const string&, const string&);
	bool _delAuthorInBook(const string&, const string&, const string&, const string&);
	friend ostream& operator<<(ostream&, library&);	//не const, потому что сортирую
private:
	list<book> bookList;
};

