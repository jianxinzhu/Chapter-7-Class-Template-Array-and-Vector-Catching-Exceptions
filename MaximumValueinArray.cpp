/*  name: jianxin zhu
    date: july/21/2020
 */
 
 #include<iostream>
#include<array>

using namespace std;

int maximumArray(array<int, 10>a1, size_t current, int maximumNumber)
{
	if (current == a1.size() - 1)
	{
		return maximumNumber;
	}
	else
	{
		if (a1[current] > maximumNumber)
		{
			maximumNumber = a1[current];
		}

		return maximumArray(a1, current + 1, maximumNumber);
	}
}

int main()
{
	array<int, 10>a1{ 10,99,300,3,40,5,12,120,120,11 };

	cout << "The maximum number is: " << maximumArray(a1, 0, 0);
}
