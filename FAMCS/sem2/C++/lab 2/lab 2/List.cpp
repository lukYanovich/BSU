#include "List.h"
using namespace Alex;

void List::InsertInBeg(const double& a)
{
	ListElement* p = new ListElement;
	p->info = a;
	p->next = u;
	u = p;
}

void List::InsertInEnd(const double& a)
{
	if (u == NULL)
	{
		InsertInBeg(a);
		return;
	}
	ListElement* p = new ListElement;
	p->info = a;
	ListElement* s = u;
	while (s->next)
		s = s->next;
	s->next = p;
}

void List::DeleteBeg()
{
	if (u == NULL)
	{
		cout << "List is empty.\n";
		return;
	}
	ListElement* p = u->next;
	delete u;
	u = p;
}

void List::DeleteEnd()
{
	if (u == NULL)
	{
		cout << "List is empty.\n";
		return;
	}
	ListElement* p = u;
	while (p->next->next)
		p = p->next;
	delete p->next;
	p->next = NULL;
}

bool List::Delete(const double& a)
{
	if (u->info == a)
	{
		DeleteBeg();
		return true;
	}
	ListElement* p = u;
	while (true)
	{
		if (p->next->info == a)
			break;
		if (p->next->next == NULL)
			return false;
		p = p->next;
	}
	ListElement *temp = p->next;
	p->next = p->next->next;
	delete temp;
	return true;
}

int List::Find(const double& a)	
{
	//если не найдено - вернёт 0
	int count = 0;
	ListElement *p = u;
	while (p)
	{
		count++;
		if (p->info == a)
			return count;
		p = p->next;
	}
	return 0;
}

void List::Erase()
{
	ListElement *p = u, *temp;
	while (p)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
	u = NULL;
}

void List::Copy(const List& a)
{
	ListElement *p, *q, *s;
	s = NULL;
	p = a.u;
	while (p != NULL)
	{
		q = new ListElement;
		q->info = p->info;
		if (s == NULL)
			u = q;
		else
			s->next = q;
		s = q;
		p = p->next;
	}
}

List& List::operator=(const List& a)
{
	if (this == &a)
		return *this;
	Erase();
	Copy(a);
	return *this;
}

void List::ForEach(void Func(double&)) const
{
	if (u == NULL)
	{
		cout << "List is empty.\n";
		return;
	}
	ListElement *p = u;
	cout << "contens of List:\n";
	while (p)
	{
		Func(p->info);
		p = p->next;
	}
	cout << endl;
}

void List::ForEach(double& Func(double&))
{
	if (u == NULL)
	{
		cout << "List is empty.\n";
		return;
	}
	ListElement *p = u;
	while (p)
	{
		p->info = Func(p->info);
		p = p->next;
	}
}

void List::PrintList() const
{
	if (u == NULL)
	{
		cout << "List is empty.\n";
		return;
	}
	ListElement* p = u;
	cout << "contens of List:\n";
	while (p)
	{
		cout << p->info << ' ';
		p = p->next;
	}
	cout << endl;
}


void List::Insert(const double& a)
{
	if (u == nullptr || a < u->info)
	{
		InsertInBeg(a);
		return;
	}
	ListElement* p = u;
	while (p)
	{
		if (a < p->info)
			break;
		p = p->next;
	}
	if (p == nullptr)
	{
		InsertInEnd(a);
		return;
	}
	double k = p->info;
	p->info = a;
	ListElement* s = new ListElement;
	s->info = k;
	s->next = p->next;
	p->next = s;
}