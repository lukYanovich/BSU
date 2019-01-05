/*преобразованый метод поиска комплексных переменных в уравнении.Берется 2 рандомных числа,
и подставляются в уравнение, потом отклонение, подстановка в уравнение, отклонение... и находится корень.*/

#include <iostream>
using namespace std;
double del(int, int);

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, ".1251");
	int a, b;		//делим А на B
	cout << "введите A: "; cin >> a;
	cout << "введите B: "; cin >> b;
	cout << "A/B = " << del(a, b) << endl;
	return 0;
}


double del(int _a, int _b) {
	double a = _a, b = _b;
	double c = 3.0, temp;	//c - рандомное число
	double E = 0.1;		//точность
	double D = 0.05;	//отклонение

	/*forever{
		double temp = b*c - a;
	if (abs(temp) < E)
		break;
	if (b*c > a)
		c -= D;
	else
		c += D;
	}*/

	_asm {
		fld		a	//st(6) : для выражения (b*c)
		fld		D	//st(5)
		fld		E	//st(4)
		fld		a	//st(3)
		fld		b	//st(2)
		fld		c	//st(1) : для изменённой переменной 'с'
		fld		c	//st(0) : для значения выражения (b*c - a)
		mov		ebx, _b

		_forever :
		mov		ecx, 0
			fsub	st(0), st(0)

			_while :
			fadd	st(0), st(1)
			inc		ecx
			cmp		ecx, ebx
			jne		_while

			fsub	st(0), st(3)	//st(0) : b*c - a
			fabs	//модуль st(0)

			fcom	st(4)	//сравниваем s(0) с E
			fstsw	ax
			sahf
			jb		_endForever	//если s(0) < E

			fxch	st(6)
			mov		ecx, 0
			fsub	st(0), st(0)

			while_ :
		fadd	st(0), st(1)
			inc		ecx
			cmp		ecx, ebx
			jne		while_

			fcom	st(3)
			fstsw	ax
			sahf
			ja		Rezult1	//если s(0) > s(3)
			jb		Rezult2	//если s(0) < s(3)		
			jnb		Rezult2 //если s(0) == s(3)

			Rezult1 :
		fxch	st(6)
			fxch	st(1)
			fsub	st(0), st(5)
			fxch	st(1)
			jmp		_forever
			Rezult2 :
		fxch	st(6)
			fxch	st(1)
			fadd	st(0), st(5)
			fxch	st(1)
			jmp		_forever

			_endForever :
		fxch	st(1)
			fxch	st(6)
			fstp	temp
			fstp	temp
			fstp	temp
			fstp	temp
			fstp	temp
			fstp	temp
			fstp	temp
	}
	return temp;
}