#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
typedef int InfoType;
using namespace std;

class Queue{	//abstract class
private:
	virtual void Erase() = 0 {};
	virtual void Clone(const Queue&) = 0 {};
	/*методы с пустыми телами, будут вызваны в базовом классе при
	Реализации конструктора копирования, деструктора и оператора
	присваивания*/
public:
	Queue() {}
	explicit Queue(const Queue&);
	virtual ~Queue();
	virtual Queue& operator=(const Queue&);

	/*далее идут абстрактные методы (чисто виртуальные)
	для базового класса */
	virtual void Push(const InfoType& AInfo) = 0;
	virtual bool Pop() = 0;
	virtual InfoType GetFirst() const = 0;
	virtual bool IsEmpty() const = 0;
	virtual unsigned GetSize() const = 0;
	virtual InfoType& operator[] (unsigned) const = 0;
	virtual const InfoType& GetByIndex(unsigned) const = 0;
	virtual void ForEach(void ItemWork(InfoType)) const = 0; //было Browse
	virtual void ForEach(void ItemWork(InfoType&)) = 0;
};

class QException : public exception{
public:
	QException(const InfoType& a){
		msg = "not pushed \"";
		stringstream ss;
		string temp;
		ss << a;
		ss >> temp;
		msg += temp;
		msg += "\"";
	}

	QException(unsigned& a){
		msg = "there is no element at index \"";
		stringstream ss;
		string temp;
		ss << a;
		ss >> temp;
		msg += temp;
		msg += "\"";
	}

	QException(const char* message) : exception(message) {}
	QException(const QException &right) : exception(right) {}
	virtual const char* what() const throw() { return msg.c_str(); }
private:
	string msg;
};