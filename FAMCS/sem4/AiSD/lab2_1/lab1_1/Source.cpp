#include <iostream>
#include <fstream>
#include <exception>
using namespace std;


void func(int, bool*, int*, int&, int**, int);


int main(int argc, char argv[])
{
	int size;
	ifstream fin("input.txt");
	fin >> size;
	int** arr = new int*[size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			fin >> arr[i][j];
	fin.close();

	bool* isVisited = new bool[size];
	for (int i = 0; i < size; i++)
		isVisited[i] = false;
	int* nodes = new int[size];
	int count = 1;

	for (int i = 0; i < size; i++)
		if (isVisited[i] == false)
			func(i, isVisited, nodes, count, arr, size);

	ofstream fout("output.txt", ios_base::trunc);
	for (int i = 0; i < size; i++)
		fout << nodes[i] << ' ';
	fout.close();

	return 0;
}


void func(int i, bool* isVisited, int* nodes, int& count, int** arr, int size)
{
	isVisited[i] = true;
	nodes[i] = count++;
	for (int j = 0; j < size; j++)
		if (isVisited[j] == false && arr[i][j] == 1)
			func(j, isVisited, nodes, count, arr, size);
}
