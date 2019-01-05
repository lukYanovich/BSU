#include <iostream>
#include <fstream.>
using namespace std;


int func(int, int);
int optimal(int, int);

int N, K;
int* arr[2];


int main(int argc, char argv[]) {

	ifstream fin("in.txt");
	fin >> N >> K;
	arr[0] = new int[N];
	arr[1] = new int[N];

	int first = -1, last = -1;
	for (int i = 0; i < N; i++) {
		fin >> arr[0][i] >> arr[1][i];
		if (arr[0][i] || arr[1][i]) {
			if (first == -1)
				first = i;
			last = i;
		}
	}
	fin.close();

	ofstream fout("out.txt");
	fout << func(first, last + 1);
	fout.close();
	return 0;
}


int optimal(int _i, int _j) {
	if (_i == _j)
		return 0;

	int **matrix = new int*[N + 1];
	for (int i = 0; i < N; i++)
		matrix[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			matrix[i][j] = 0;
	for (int i = _j - 1; i >= _i; i--)
		for (int j = i + 1; j <= _j; j++) {
			if (j - i == 1) {
				if (arr[0][j - 1] && arr[1][j - 1]) {
					if ((i == _i) && (j == _i + 1))
						matrix[i][j] = 2;
					else
						matrix[i][j] = 3;
				}
				else
					matrix[i][j] = 1;
			}
			else
				matrix[i][j] = matrix[i][j - 1] + matrix[j - 1][j];
		}
	return matrix[_i][_j];
}


int func(int first, int last) {

	if (first == -1)
		return 0;
	else if (first > K)
		return optimal(K, last) > 2 * (last - K) ? 2 * (last - K) : optimal(K, last);
	else if (last < K)
		return optimal(first, K) > 2 * (K - first) ? 2 * (K - first) : optimal(first, K);

	int opt = optimal(first, K);
	if (opt > 2 * (K - first))
		opt = 2 * (K - first);
	int result1 = 2 * (last - K) + opt;
	opt = optimal(K, last);
	if (opt > 2 * (last - K))
		opt = 2 * (last - K);
	int result2 = 2 * (K - first) + opt;
	return result1 > result2 ? result2 : result1;
}
