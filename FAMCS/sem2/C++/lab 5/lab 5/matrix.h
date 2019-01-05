#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;
typedef unsigned short ushort;

namespace lukYanovich
{
	template<class T> class matrix
	{
	public:
		matrix() { arr = nullptr; n = 0; m = 0; ID = ++count; }
		matrix(const ushort& a, const ushort& b)
		{ 
			n = a;
			m = b;
			Create();
			ID = ++count;
		}
		~matrix() { Erase(); count--; }

		matrix(const matrix<T>& a)
		{
			n = a.n;
			m = a.m;
			Create();
			for (ushort i(0); i < a.n; ++i)
				for (ushort j(0); j < a.m; ++j)
					arr[i][j] = a.arr[i][j];
			ID = ++count;
		}		

		matrix<T>& operator=(const matrix<T>& a)
		{
			if (this == &a)
				return *this;
			Copy(a);
			return *this;
		}

		matrix<T>& operator+=(const matrix<T>& a)
		{
			*this = *this + a;
			return *this;
		}

		matrix<T>& operator-=(const matrix<T>& a)
		{
			*this = *this - a;
			return *this;
		}

		matrix<T>& operator*=(const matrix<T>& a)
		{
			*this = *this * a;
			return *this;
		}
		
		matrix<T> operator*(const T& a)
		{
			matrix<T> temp = *this;
			for (ushort i(0); i < temp.n; ++i)
				for (ushort j(0); j < temp.m; ++j)
					temp.arr[i][j] *= a;
			return temp;
		}

		friend matrix<T> operator*(const T& a, const matrix<T>& m)
		{
			matrix<T> temp = m;
			for (ushort i(0); i < temp.n; ++i)
				for (ushort j(0); j < temp.m; ++j)
					temp.arr[i][j] *= a;
			return temp;
		}

		matrix<T> operator/(const T& a)
		{
			if (!a)
				throw xZero();
			matrix<T> temp = *this;
			for (ushort i(0); i < temp.n; ++i)
				for (ushort j(0); j < temp.m; ++j)
					temp.arr[i][j] /= a;
			return temp;
		}

		matrix<T> operator+(const matrix<T>& a)
		{
			if (n != a.n || m != a.m)
				throw size_error("addition");
			matrix<T> temp = *this;
			for (ushort i(0); i < n; ++i)
				for (ushort j(0); j < m; ++j)
					temp.arr[i][j] += a.arr[i][j];
			return temp;
		}

		matrix<T> operator-(const matrix<T>& a)
		{
			if (n != a.n || m != a.m)
				throw size_error("difference");
			matrix<T> temp = *this;
			for (ushort i(0); i < n; ++i)
				for (ushort j(0); j < m; ++j)
					temp.arr[i][j] -= a.arr[i][j];
			return temp;
		}

		matrix<T> operator-()
		{
			matrix<T> temp = *this;
			for (ushort i(0); i < n; ++i)
				for (ushort j(0); j < m; ++j)
					temp.arr[i][j] *= -1;
			return temp;
		}

		matrix<T> operator*(const matrix<T> a)
		{
			if (m != a.n)
				throw size_error("multiplication");
			matrix<T> temp(n, a.m);
			for (ushort i(0); i < n; ++i)
				for (ushort j(0); j < a.m; ++j)
					for (ushort k(0); k < m; ++k)
						temp.arr[i][j] += arr[i][k] * a.arr[k][j];
			return temp;
		}

		bool operator==(const matrix<T>& a)
		{
			if (n != a.n || m != a.m)
				return false;
			for (ushort i(0); i < n; ++i)
				for (ushort j(0); j < m; ++j)
					if (arr[i][j] != a.arr[i][j])
						return false;
			return true;
		}

		bool operator!=(const matrix<T>& a)
		{
			if (n != a.n || m != a.m)
				return true;
			for (ushort i(0); i < n; ++i)
				for (ushort j(0); j < m; ++j)
					if (arr[i][j] != a.arr[i][j])
						return true;
			return false;
		}

		friend istream& operator>>(istream& is, matrix<T>& a)
		{
			if (a.arr == nullptr)
				return is;
			for (ushort i(0); i < a.n; ++i)
				for (ushort j(0); j < a.m; ++j)
					is >> a.arr[i][j];
			return is;
		}

		friend ostream& operator<<(ostream& os, const matrix<T>& a)
		{
			if (a.arr == nullptr)
				return os;
			for (ushort i(0); i < a.n; ++i)
			{
				for (ushort j(0); j < a.m; ++j)
				{
					if (j != a.m - 1)
						os << setprecision(2) << a.arr[i][j] << '\t';
					else
						os << a.arr[i][j];
				}
				if (i != a.n - 1)
					os << '\n';
			}
			return os;
		}
		
		static ushort getCount() { return count; }
		ushort getID() const { return ID; }
		matrix<T> Rand(const T& beg, const T& end)
		{
			srand((unsigned int)time(NULL));
			if (!strcmp((typeid(T)).name(), "float") || !strcmp((typeid(T)).name(), "double"))
			{
				for (ushort i(0); i < n; ++i)
					for (ushort j(0); j < m; ++j)
						arr[i][j] = (T)(beg + (double(rand()) / RAND_MAX) * (end - beg));
			}
			else
			{
				for (ushort i(0); i < n; ++i)
					for (ushort j(0); j < m; ++j)
						arr[i][j] = (T)(beg + rand() % (end - beg + 1));
			}
			return *this;
		}

		class size_error : public exception
		{
			string str;
		public:
			size_error(const string& a)
			{
				str += "operation \"";
				str += a;
				str += "\" not defined: the dimensions of the matrices \ntype \"";
				str += (typeid(T)).name();
				str += "\" don't match.";
			}
			virtual const char* what() const { return str.c_str(); }
		};

		class xZero : public exception
		{
			string str;
		public:
			xZero()
			{
				str += "an attempt to divide a matrix of type \"";
				str += (typeid(T)).name();
				str += "\" to zero.";
			}
			virtual const char* what() const { return str.c_str(); }
		};

	private:
		int n;	//строки
		int m;	//столбцы
		T** arr;
		ushort ID;
		static ushort count;

		void Create()
		{
			arr = new T*[n];
			for (ushort i(0); i < n; ++i)
				arr[i] = new T[m];
			for (ushort i(0); i < n; ++i)
				for (ushort j(0); j < m; ++j)
					arr[i][j] = 0;
		}

		void Copy(const matrix<T>& a)
		{
			if (!(n == a.n && m == a.m))
			{
				Erase();
				n = a.n;
				m = a.m;
				Create();
			}
			for (ushort i(0); i < a.n; ++i)
				for (ushort j(0); j < a.m; ++j)
					arr[i][j] = a.arr[i][j];
		}

		void Erase()
		{
			for (ushort i(0); i < n; ++i)
				delete[] arr[i];
			delete[] arr;
			arr = nullptr;
		}
	};
}