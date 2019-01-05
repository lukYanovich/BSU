#include "Person.h"
#include "Student.h"
#include "Teacher.h"

int main()
{
	try
	{
		Student a("Carpenter", "David", 19, "fpmi", 10, 2);
		Teacher b("Grant", "Francis", 40, "isc");
		Student c("Carpenter", "Arron", 17, "fpmi", 11, 1);
		Student d("Sharp", "William", 21, "fpmi", 5, 4);
		Student e("Reed", "Cecilia", 20, "fpmi", 1, 3);
		Teacher g("Brown", "Jennifer", 30, "isc");

		Person* arr[] = { &a, &b, &c, &d, &e, &g };
		for (ushort i(0); i < 4; ++i)
			for (ushort j = i + 1; j < 5; ++j)
				if (arr[i]->getSurname() == arr[j]->getSurname() && typeid(arr[i]) == typeid(arr[j]))
					cout << "group: " << arr[i]->getInfo1() << ", course: " << arr[i]->getInfo2()
					<< ", and " << "group: " << arr[j]->getInfo1() << ", course: " << arr[j]->getInfo2() << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}