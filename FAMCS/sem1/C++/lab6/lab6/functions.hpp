#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

void Swap(int *Mas, short i)
{
	int temp;
	temp = Mas[i];
	Mas[i] = Mas[i - 1];
	Mas[i - 1] = temp;
}

void ShakerSort(int *Mas, int Start, short N)
{
	short Left, Right, i;
	Left = Start;
	Right = N - 1;
	while (Left <= Right){
		for (i = Right; i >= Left; i--)
			if (Mas[i - 1] > Mas[i]) Swap(Mas, i);
		for (int j = 0; j < N; j++){
			std::cout << " " << Mas[j];
		}
		std::cout << std::endl;
		Left++;
		for (i = Left; i <= Right; i++)
			if (Mas[i - 1] > Mas[i]) Swap(Mas, i);
		for (short j = 0; j < N; j++){
			std::cout << " " << Mas[j];
		}
		std::cout << std::endl;
		Right--;
	}
}

#endif