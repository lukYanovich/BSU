#pragma once
#include <iostream>
using namespace std;

namespace Alex
{	
	class List
	{
	public:
		List() { u = NULL; }
		List(const List& a) { Copy(a); }
		List& operator=(const List&);
		~List() { Erase(); }

		void InsertInBeg(const double&);
		void InsertInEnd(const double&);
		void DeleteBeg();
		void DeleteEnd();
		bool Delete(const double&);

		void Insert(const double&);
		
		int Find(const double&);
		void ForEach(void Func(double&)) const;
		void ForEach(double& Func(double&));

		void PrintList() const;		
	private:
		struct ListElement
		{
			double info;
			ListElement* next = NULL;
		};
		ListElement* u;
		void Erase();
		void Copy(const List&);		
	};
}