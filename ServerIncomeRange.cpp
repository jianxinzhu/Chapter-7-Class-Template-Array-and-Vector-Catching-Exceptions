/*  name: jianxin zhu
    date: july/19/2020
 */
 
 #include<array>
#include<iomanip>
#include<iostream>
using namespace std;

int main()
{
	array<int, 9>salary{};

	int dailySalary = 0;

	cout << "Enter today's salary: ";

	while (cin >> dailySalary)
	{
		if (dailySalary > 100)
		{
			++salary[8];
		}
		else
		{
			++salary[dailySalary / 10 - 2];
		}
		cout << "Enter today's salary: ";
	}

	cout << "******Salary List" << endl;
	for (int i = 0; i < salary.size(); i++)
	{
		if (8 == i)
		{
			cout << "100 and over: ";
		}
		else if(0==i)
		{
			cout << "20-29:";
		}
		else
		{
			cout << i * 10 + 20 << "-" << i * 10 + 29 << ":";
		}

		for (int star = 0; star < salary[i]; star++)
		{
			cout << "*";
		}

		cout << endl;
	}

}
