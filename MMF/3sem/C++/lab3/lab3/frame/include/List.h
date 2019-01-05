#pragma once
#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <string>
#include <memory>
#include <vector>
#include <boost\algorithm\string.hpp>
#include <regex>
using namespace std;


struct Node {
	shared_ptr<Node> next;
	int info;
	Node(const int a) : info(a), next(nullptr) {}
};


class List {
private:
	size_t _size;
	shared_ptr<Node> first;


public:
	List();
	List(const List& o);

	void add(const int a) noexcept;
	void add(const size_t index, const int element);
	void clear() noexcept; //очистка списка
	bool contains(const int& o) const noexcept;
	size_t indexOf(const int& o) const; //первая позиция
	bool isEmpty() const noexcept;
	size_t lastIndexOf(const int& o) const;
	void remove(const int& o) noexcept;
	void remove(const size_t index);
	void removeAll(const int& o) noexcept;
	void set(const size_t index, const int element);
	int get(const size_t index) const;
	int* toArray() const; //отдаём массив
	size_t size() const noexcept;
	void sort() noexcept;

	List& operator=(const List& o) noexcept;
	friend istream& operator>> (istream& is, List& o);
	friend ostream& operator<<(ostream& os, const List& o);


private:
	void create() noexcept;
	shared_ptr<Node> findEnd() const noexcept;
	shared_ptr<Node> findOfIndex(const size_t index) const noexcept;
	void check(const char* nameOfMethod) const;
	void check(const size_t index, const char* nameOfMethod) const;
	void push_front(const int o) noexcept;
	void pop_front() noexcept;

	static void checkOfEmpty(string);
	static void repairArr(vector<string>&);
	static int toNumber(string);
	static vector<string> read(istream&);
};
