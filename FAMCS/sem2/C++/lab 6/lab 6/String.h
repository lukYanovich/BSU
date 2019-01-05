#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class String
{
public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&); 
	String& operator=(const char*);
	bool operator==(const String&) const;
	bool operator!=(const String&) const;
	bool operator<(const String&) const;
	bool operator<=(const String&) const;
	bool operator>(const String&) const;
	bool operator>=(const String&) const;
	String operator+(const String&);
	String operator+(const char*);
	size_t length() const { return size() - 1; }
	char& operator[](const int&);
	const char& operator[](const int&) const;
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, const String&);
	~String();

	//String& operator+=(const String&);
	//String& operator+=(const char*);
	const char* c_str() const;
	void erase();
	//void erase(const size_t&);
	//unsigned short getID() const{ return ID; }
	//unsigned short getCount() const{ return count; }
private:
	char* str;
	//unsigned short ID;
	//static unsigned short count;
	//static unsigned short max_count;

	size_t size() const;
	void Copy(const String&);
	void Copy(const char*);
	void Clone(const String&);
	void Clone(const char*);
};

class wrong_index : public exception
{
public:
	wrong_index() throw()
	{
		msg = "wrong index.";
	}
	virtual const char* what() const throw()
	{
		return msg.c_str();
	}
private:
	String msg;
};