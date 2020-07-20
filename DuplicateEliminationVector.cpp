/*   name: jianxin zhu
     date: july/19/2020
     
*/

#include<random>
#include<ctime>
#include<iostream>
#include<vector>
#include<array>

using namespace std;


int main()
{
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1,10 };

	int randomNumber = 0;
	int index = 0;
	array<int, 20>a1{};
	vector<int>v1;

	for (unsigned int i = 0; i < a1.size(); i++)
	{
		randomNumber = randomInt(engine);
		cout << randomNumber << " ";

		a1[i] = randomNumber;
	}
	cout << endl;

	for (unsigned int i = 0; i < a1.size(); i++)
	{
		for (unsigned int j = i + 1; j < a1.size(); j++)
		{
			if (a1[i] == a1[j])
			{
				a1[j] = 0;
			}
		}
	}

	for (unsigned int i = 0; i < a1.size(); i++)
	{
		if (a1[i] != 0)
		{
			v1.push_back(a1[i]);
			cout << v1[index]<<" ";
			index++;
		}
	}
}
