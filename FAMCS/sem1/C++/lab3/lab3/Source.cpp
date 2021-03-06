/* ������������ ����������� ������. ������������ ����������� ������� ������ ����������� ����������. �������� ����������
��������� ������� ������ � ���������� � ��������� ������ �� ������� �������. ������ ������ �������� �� �����, ��� ��
������ ��������.
������������� ��� ������� ���������� �������: � ���������� � � ������� ������� ��������� �����. � ��������� ������ �����
����������� ������� ������ ������� ���������, �������� ������ ������������ �������� �������.
������� ���������� ���������. �������������� ������� �� ���������
- � ���������� ������� �� n ��������� ���������:
1. ���������� ��������� ���������
2. ����� ��������� �������, ������������� ����� ������ � ������ �������������� ����������
3. ������������� ������ ����� �������, ����� ��������, ������������� [a;b], ������������� ����� ���� ���������. ������� ����������
��������� �� ��������.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	const int nMax = 100;
	int n = 1000, k = 10;	// ���������� �������� ��������
	int mas[nMax], i, j, a, b;
	while (!((n < nMax) && (n >= 1))){
		cout << "������� ���������� ��������� ������� (����� 100): ";
		cin >> n;
		if ((n >= nMax) || (n < 1))
			cout << "error" << endl;
		continue;
	}

	if (n == 1)
		cout << "\n������ ������� �� ������ ��������\n";
	else{
		while (!((k >= 1) && (k <= 2))){
			cout << "\n���� ������ ��������� ������ ����, �� ������� 1. ���� ������ ��������� ������ ���������� ������� - ������� 2: ";
			cin >> k;
			if ((k < 1) || (k>2))
				cout << "error" << endl;
			continue;
		}

		if (k == 1){
			cout << "\n������� �������� �������:\n";
			for (i = 0; i < n; i++)
				cin >> mas[i];
		}
		if (k == 2){
			cout << "������� ������� ���������� ��������� �����:\n";
			cin >> a;
			cin >> b;
			cout << endl;
			if (a == b)
				for (i = 0; i < n; i++)
					mas[i] = a;
			if (a != b){
				if (a > b){
					int temp = a;
					a = b;
					b = temp;
				}
				srand(time(NULL));
				for (i = 0; i < n; i++)
					mas[i] = a + rand() % (b - a + 1);
			}
			for (i = 0; i < n; i++)
				cout << " " << mas[i];
		} // ��������� ��������� ����

		//��������� � �������

		k = 0;
		long int sum = 0;
		bool flag = true;
		for (i = 0; i < n; i++){
			flag = false;
			for (j = i + 1; j < n; j++){
				if (mas[i] == mas[j]){
					flag = true;
					break;
				}
			}
			if (flag == false)
				k++;
		}
		if (k == 1)
			cout << "\n������ ������� �� ���������� ���������\n";
		else
			cout << "\n\n���������� ��������� ���������: " << k << endl;

		k = 0;
		flag = false;
		for (i = 0; i < n-1; i++){			
			if ((mas[i] > 0) && (mas[i + 1]>0)){
				cout << "\n��� �������� �������� => ������ ���" << endl;
				flag = true;
				break;
			}
			else{
				for (j = 0; j < n; j++){
					if (k == 1)
						sum += mas[j];
					if (mas[j] > 0)
						k++;
					if (k == 2){
						sum -= mas[j];
						k++;
					}
				}
			}
		}
		if ((k == 0) && (flag=false))
			cout << endl << "��� ������������� ��������� �������" << endl;
		if ((k == 1) && (flag=false))
			cout << endl << "������ ���� ������������� ������� � �������" << endl;
		if (((k != 1) && (k != 0)) && (flag = false))
			cout << endl << "����� ��������� ������� ����� ������ � ������ �������������� ����������: " << sum << endl;

		a = 0; b = 0;
		cout << "\n������� a: ";
		cin >> a;
		cout << "������� b: ";
		cin >> b;
		cout << endl;

		if (a == b)
			cout << "\n������� ��������� => ��� �����. ��� �������� �������, ������ ��, ����� �������� � �����" << endl;

		if (a > b){
			int temp = b;
			b = a;
			a = temp;
		}		
		for (i = 0; i < n; i++){
			for (int z = 0; z < n; z++){
				for (j = 0; j < n - 1; j++){
					if ((mas[j] <= b) && (mas[j] >= a)){
						int temp = mas[j];
						mas[j] = mas[j + 1];
						mas[j + 1] = temp;
					}
				}
			}
		}		
		
		for (i = 0; i < n; i++){
			cout << " " << mas[i];
		}
		cout << endl;
	}
	return 0;
}