#include "resources.h"


int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	ofstream fout("output.txt", ios_base::trunc);
	if (!fout.good())
		throw exception("");
	fout << fixed << setprecision(6);

	const int n = 6;
	double f_norm = 0.0;
	for (int i = 0; i < n; i++) {
		fout << f(x(i)) << endl;
		f_norm += pow(f(x(i)), 2);
	}
	f_norm = sqrt(f_norm);

	//дельта 1
	double temp = 0.0;
	for (int i = 0; i < n; i++)
		temp += pow(0.088313 - f(x(i)), 2);
	temp = sqrt(temp);
	fout << "\n\nдельта = " << temp << "\nдругая дельта = " << temp / f_norm * 100 << endl;

	//дельта 2
	temp = 0.0;
	for (int i = 0; i < n; i++)
		temp += pow(-0.0725764286*x(i) + 0.2298490476 - f(x(i)), 2);
	temp = sqrt(temp);
	fout << "\n\nдельта = " << temp << "\nдругая дельта = " << temp / f_norm * 100 << endl;

	//дельта 3
	temp = 0.0;
	for (int i = 0; i < n; i++)
		temp += pow(-1.6097265625*x(i)*x(i) + 1.5371501339*x(i) + 0.0152188393 - f(x(i)), 2);
	temp = sqrt(temp);
	fout << "\n\nдельта = " << temp << "\nдругая дельта = " << temp / f_norm * 100 << endl;

	fout.close();
	return 0;
}


double f(double x) {
	double temp = sin(PI*x) / (x + 1);
	return temp*temp;
}


double x(int i) { return 0.2*i; }
