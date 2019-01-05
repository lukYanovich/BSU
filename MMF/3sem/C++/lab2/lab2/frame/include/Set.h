#pragma once
#include "MyAux.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>


template<class T> class Set {
private:
	vector<T> v;

public:
	Set<T> operator+(Set<T> a) {
		vector<T> vec = v;
		for (size_t i(0); i < a.v.size(); i++) {
			bool flag = false;
			for (auto j : v)
				if (a.v[i] == j) {
					flag = true;
					break;
				}
			if (flag == false)
				vec.push_back(a.v[i]);
		}
		return Set(vec);
	}

	Set<T> operator-(Set<T> a) {
		Set<T> s = Set<T>(v);
		for (auto i : v)
			for (auto j : a.v)
				if (i == j) {
					s.remove(i);
					break;
				}
		return s;
	}

	Set<T> operator*(Set<T> a) {
		vector<T> vec;
		for (auto i : v)
			for (auto j : a.v)
				if (i == j) {
					vec.push_back(i);
					break;
				}
		return Set(vec);
	}

	T& operator[](size_t i) {
		sort(v.begin(), v.end());
		return v[i];
	}

	Set<T>& operator=(const Set<T>& a) {
		if (this == &a)
			return *this;
		v = a.v;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Set<T>& a) {
		vector<T> v = a.v;
		sort(v.begin(), v.end());
		char* separator = ", ";
		for (size_t i(0); i < v.size() - 1; i++)
			os << v[i] << separator;
		os << v[v.size() - 1];
		return os;
	}

	friend istream& operator>>(istream& is, Set<T>& temp) {
		string str;
		getline(is, str);		
		checkOfEmpty(str);
		vector<string> arr;
		boost::split(arr, str, boost::is_any_of(" "));
		repairArr(arr);

		temp.v.clear();
		for (string j : arr) {
			string type = (typeid(T)).name();
			if (type == "int")
				temp.insert((T)toNumber(j));
			else if (type == "double")
				temp.insert((T)toDouble(j));
			else if (type == "char")
				temp.insert((T)j[0]);
		}

		return is;
	}

	bool belongs(const T a) {
		for (auto i : v)
			if (i == a)
				return true;
		return false;
	}

	Set(const vector<T> v) { this->v = v; }
	Set() {}
	Set(const Set<T>& a) { v = a.v; }
	void insert(T a) { v.push_back(a); }
	bool isEmpty() const { return v.empty(); }

private:
	string getTypeOfElements() const { return (typeid(T)).name(); }

	void remove(const T a) {
		for (size_t i(0); i < v.size(); i++)
			if (a == v[i]) {
				swap(v[i--], v[v.size() - 1]);
				v.pop_back();
			}
	}
};
