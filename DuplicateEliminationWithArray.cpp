/*  name: jianxin zhu
    date: july/19/2020
 */
 
 #include<iostream>
#include<array>
#include<random>
#include<ctime>

using namespace std;

void duplicateArray(array<int, 20>& n)
{
	for (unsigned int i = 0; i < n.size(); i++)
	{
		for (unsigned int j = i + 1; j < n.size(); j++)
		{
			if (n[i] == n[j])
			{
				n[i] = 0;
			}
		}
	}


	for (unsigned int i = 0; i < n.size(); i++)
	{
		if (n[i] == 0)
		{
			continue;
		}
		else
		{
			cout << n[i] << " ";
		}
	}
}

int main()
{
	array<int, 20>number{};
	int randomNumber = 0;

	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<int> randomInt{ 1,9 };

	for (unsigned int i = 0; i < number.size(); i++)
	{
		randomNumber = randomInt(engine);
		number[i] = randomNumber;

	}
	cout << "Before removing duplicate number: " << endl;
	for (unsigned int i = 0; i < number.size(); i++)
	{
		cout << number[i] << " ";
	}

	cout << "\nAfter removed duplicate number: " << endl;
	duplicateArray(number);


}
