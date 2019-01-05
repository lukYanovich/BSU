#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Tree
{
public:
	Tree() { u = nullptr; }
	Tree(const Tree&);
	Tree& operator=(const Tree&);
	~Tree();

	bool Insert(const int&);
	bool Delete(const int&);
	bool Find(const int&, int&);
	void ForEach(void(const int&)) const;

	void PrintTree() const;
private:
	struct TreeNode
	{
		int info;
		TreeNode *left = nullptr;
		TreeNode *rigth = nullptr;
		TreeNode *father = nullptr;
	};
	TreeNode *u;
	void Copy(const Tree& a);
	void Copy(TreeNode* &);
	bool TestFind(TreeNode* &, const int&);
	void PrintTree(TreeNode* &) const;
	void ForEach(TreeNode* &, void(const int&)) const;
	void Erase(TreeNode* &);
};
