#include "pch.h"
#include "Tree.h"


Tree::Tree(const Tree& a) { Copy(a); }

Tree::~Tree() { Erase(u); }

bool Tree::TestFind(TreeNode* &t, const int& a)
{
	//true - вершина найдена
	//false - вершина не найдена
	//t - ссылка на узел, на котором закончен поиск
	if (t == nullptr)
		return false;
	while (true)
	{
		if (t->info == a)
			return true;
		if (a < t->info)
		{
			if (t->left == nullptr)
				return false;
			t = t->left;
			continue;
		}
		else
		{
			if (t->rigth == nullptr)
				return false;
			t = t->rigth;
		}
	}
}

bool Tree::Insert(const int& a)
{
	if (u == nullptr)
	{
		u = new TreeNode;
		u->info = a;
		return true;
	}
	TreeNode* p = u;
	if (TestFind(p, a))
		return false;
	else
	{
		TreeNode *s = new TreeNode;
		s->info = a;
		s->father = p;
		if (a < p->info)
			p->left = s;
		else if (a > p->info)
			p->rigth = s;
		return true;
	}
}

bool Tree::Find(const int& a, int& b)
{
	b = 0;
	if (u == nullptr)
		return false;
	TreeNode* p = u;
	int count = 0;
	while (true)
	{
		b = ++count;
		if (p->info == a)
			return true;
		if (a < p->info)
		{
			if (p->left == nullptr)
				return false;
			p = p->left;
			continue;
		}
		else
		{
			if (p->rigth == nullptr)
				return false;
			p = p->rigth;
		}
	}
}

void Tree::ForEach(TreeNode* &t, void Func(const int&)) const
{
	if (t == nullptr)
		return;
	ForEach(t->left, Func);
	Func(t->info);
	ForEach(t->rigth, Func);
}

void Tree::ForEach(void Func(const int&)) const
{
	if (u == nullptr)
	{
		ofstream fout("output.txt", ios_base::app);
		if (!fout)
			throw 2;
		fout << "Tree is empty." << endl;
		fout.close();
	}
	TreeNode* p = u;
	ForEach(p, Func);
}

bool Tree::Delete(const int& a)
{
	if (u == nullptr)
		return false;
	TreeNode* p = u;
	if (!(TestFind(p, a)))
		return false;

	if (p->left == nullptr && p->rigth == nullptr)
	{
		if (p == u)
		{
			delete u;
			u = nullptr;
			return true;
		}
		if (p->father->left == p)
			p->father->left = nullptr;
		else
			p->father->rigth = nullptr;
		delete p;
		p = nullptr;
		return true;
	}

	if (p->left == nullptr)
	{
		if (p == u)
		{
			u = p->rigth;
			delete p;
			p = nullptr;
			return true;
		}
		if (p->info < p->father->info)
			p->father->left = p->rigth;
		else
			p->father->rigth = p->rigth;
		delete p;
		p = nullptr;
		return true;
	}

	if (p->rigth == nullptr)
	{
		if (p == u)
		{
			u = p->left;
			delete p;
			p = nullptr;
			return true;
		}
		if (p->info > p->father->info)
			p->father->rigth = p->left;
		else
			p->father->left = p->left;
		delete p;
		p = nullptr;
		return true;
	}

	if (p->left != nullptr && p->rigth != nullptr)
	{
		TreeNode* s = p->rigth;
		while (s->left)
			s = s->left;
		p->info = s->info;
		if (s->left == nullptr && s->rigth == nullptr)
		{
			if (s->father->left == s)
				s->father->left = nullptr;
			else
				s->father->rigth = nullptr;
			delete s;
			s = nullptr;
			return true;
		}
		if (s->left == nullptr)
		{
			if (s->info < s->father->info)
				s->father->left = s->rigth;
			else
				s->father->rigth = s->rigth;
			delete s;
			s = nullptr;
			return true;
		}
		if (s->rigth == nullptr)
		{
			if (s->info > s->father->info)
				s->father->rigth = s->left;
			else
				s->father->left = s->left;
			delete s;
			s = nullptr;
			return true;
		}
	}
	return true;
}

void Tree::Erase(TreeNode* &p)
{
	if (p == nullptr)
		return;
	Erase(p->left);
	Erase(p->rigth);
	delete p;
	p = nullptr;
}

void Tree::Copy(TreeNode* &p)
{
	if (p == nullptr)
		return;
	Insert(p->info);
	Copy(p->left);
	Insert(p->info);
	Copy(p->rigth);
}

void Tree::Copy(const Tree& a)
{
	if (a.u == nullptr)
		return;
	TreeNode* p = a.u;
	Copy(p);
}

Tree& Tree::operator=(const Tree& a)
{
	if (&a == this)
		return *this;
	Erase(u);
	Copy(a);
	return *this;
}





void Tree::PrintTree() const
{
	if (u == nullptr)
	{
		ofstream fout("output.txt", ios_base::app);
		if (!fout)
			throw 2;
		fout << "Tree is empty.\n";
		fout.close();
		return;
	}
	TreeNode *p = u;
	PrintTree(p);
}

void Tree::PrintTree(TreeNode* &p) const
{
	if (p == nullptr)
		return;
	PrintTree(p->left);
	ofstream fout("output.txt", ios_base::app);
	if (!fout)
		throw 2;
	fout << p->info << ' ';
	fout.close();
	PrintTree(p->rigth);
}