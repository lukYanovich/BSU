#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

int main()
{	
	const int c1 = 101; // длина строки
	const int c2 = 50; // массив указателей
	char *p = new char [c1];
	std::cout << "enter line:\n";
	gets(p);
	if (p[0]=='\0'){
		std::cout << "line is empty.\n";
		delete[] p;
		return 1;
	}
	char *razd = new char [c1];
	std::cout << "enter line of separators:\n";
	gets(razd);
	if (razd[0] == '\0'){
		std::cout << "line of separators is empty.\n";
		delete[] p;
		delete[] razd;
		return 1;
	}
	std::cout << std::endl;
	
	int len = 0;
	char **newp = new char*[c2];
	char *mas = strtok(p, razd);
	if (mas == 0){
		std::cout << "this line does not contain the worts.\n";
		delete[] p;
		delete[] razd;
		delete[] newp;
		delete[] mas;
		return 1;
	}
	int i = 0;
	while (mas!= NULL){
		if (strlen(mas) > len){
			len = strlen(mas);
			i = 0;
		}
		if (strlen(mas) == len){
			newp[i++] = mas;
		}
		mas = strtok(NULL,razd);
	}
	std::cout << "result string:\n";
	for (short j = 0; j < i; j++){
		if (j < i-1)
			std::cout << newp[j] << "; ";
		else
			std::cout << newp[j];
	}
	std::cout << std::endl;
	
	delete[] newp;
	delete[] p;
	delete[] razd;
	delete[] mas;

	return 0;
}