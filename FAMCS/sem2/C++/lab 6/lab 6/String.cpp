#include "String.h"
//unsigned short String::count = 0;
//unsigned short String::max_count = 0;

String::String()
{
	str = 0;
	//count++;
	//ID = ++max_count;
}

String::String(const char* a)
{
	Clone(a);
	//count++;
	//ID = ++max_count;
}

String::String(const String& a)
{
	Clone(a);
	//count++;
	//ID = ++max_count;
}

String& String::operator=(const char* a)
{
	Copy(a);
	return *this;
}

String& String::operator=(const String& a)
{
	if (this == &a)
		return *this;
	Copy(a);
	return *this;
}

String::~String()
{
	erase();
	//count--;
}

size_t String::size() const
{
	if (str == 0)
		return 0;
	size_t i;
	for (i = 0; str[i] != '\0'; ++i);
	return ++i;
}

char& String::operator[](const int& a)
{
	if (a < 0 || a > (int)length())
		throw wrong_index();
	size_t i;
	for (i = 0; i != a; ++i);
	return str[i];
}

const char& String::operator[](const int& a) const
{
	if (a < 0 || a > (int)length())
		throw wrong_index();
	size_t i;
	for (i = 0; i != a; ++i);
	return str[i];
}

String String::operator+(const char* a)
{
	String temp;
	size_t i;
	for (i = 0; a[i] != '\0'; ++i);
	i += size();
	temp.str = new char[i];
	for (size_t j(0); j < i - 1; ++j)
	{
		if (j < length())
			temp.str[j] = str[j];
		else
			temp.str[j] = a[j-length()];
	}
	temp.str[i - 1] = '\0';
	return temp;
}

String String::operator+(const String& a)
{
	String temp;
	size_t i;
	for (i = 0; a[i] != '\0'; ++i);
	i += size();
	temp.str = new char[i];
	for (size_t j(0); j < i - 1; ++j)
	{
		if (j < length())
			temp.str[j] = str[j];
		else
			temp.str[j] = a[j - length()];
	}
	temp.str[i - 1] = '\0';
	return temp;
}

//String& String::operator+=(const String& a)
//{
//	*this = *this + a;
//	return *this;
//}
//String& String::operator+=(const char* a)
//{
//	String temp = a;
//	*this = *this + temp;
//	return *this;
//}

istream& operator>>(istream& is, String& a)
{
	streambuf* buf = is.rdbuf();
	buf->sgetc();
	streamsize size = buf->in_avail();
	a.erase();
	a.str = new char[(unsigned int)size];
	int i;
	for (i = 0; buf->sgetc() != '\n'; ++i)
		a.str[i] = buf->sbumpc();
	is.ignore(1);
	a.str[i] = '\0';
	return is;
}

ostream& operator<<(ostream& os, const String& a)
{
	if (a.str)
		for (size_t i(0); i < a.length(); ++i)
			os << a.str[i];
	else
		os << "";
	return os;
}

bool String::operator==(const String& a) const { return (length() == a.length()) ? true : false; }

bool String::operator!=(const String& a) const { return (length() != a.length()) ? true : false; }

bool String::operator<(const String& a) const { return (length() < a.length()) ? true : false; }

bool String::operator<=(const String& a) const { return (length() <= a.length()) ? true : false; }

bool String::operator>(const String& a) const { return (length() > a.length()) ? true : false; }

bool String::operator>=(const String& a) const { return (length() >= a.length()) ? true : false; }


const char* String::c_str() const
{
	char* temp = new char[size()];
	for (size_t i(0); i < size(); ++i)
		temp[i] = str[i];
	return temp;
}

void String::erase()
{
	if (str)
	{
		delete[] str;
		str = 0;
	}
}

//void String::erase(const size_t& a)
//{
//	if (a > length())
//		throw wrong_index();
//	if (!a)
//	{
//		erase();
//		return;
//	}
//	char* temp = new char[a+1];
//	for (size_t i(0); i < a; ++i)
//		temp[i] = str[i];
//	temp[a] = '\0';
//	erase();
//	str = temp;
//}

void String::Clone(const String& a)
{
	str = new char[a.size()];
	for (size_t i(0); i < a.size(); ++i)
		str[i] = a.str[i];
}

void String::Clone(const char* a)
{
	size_t i;
	for (i = 0; a[i] != '\0'; ++i);
	str = new char[++i];
	for (size_t j(0); j < i; ++j)
		str[j] = a[j];
}

void String::Copy(const String& a)
{
	if (size() != a.size())
	{
		erase();
		str = new char[a.size()];
	}
	for (size_t i(0); i < size(); ++i)
		str[i] = a.str[i];
}

void String::Copy(const char* a)
{
	size_t i;
	for (i = 0; a[i] != '\0'; ++i);
	i++;
	if (size() != i)
	{
		erase();
		str = new char[i];
	}
	for (size_t j(0); j < i; ++j)
		str[j] = a[j];
}