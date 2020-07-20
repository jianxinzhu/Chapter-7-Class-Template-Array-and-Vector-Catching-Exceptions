/*  name: jianxin zhu
    date: july/19/2020
*/

#include<random>
#include<ctime>
#include<iomanip>
#include<iostream>
#include<vector>
#include<array>

using namespace std;


int main()
{
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	uniform_int_distribution<unsigned int> randomInt{ 1,6 };
	
	array<int, 11>rollDice{};

	for (unsigned int i = 1; i <= 6'000; i++)
	{
		int dice1 = randomInt(engine);
		int dice2 = randomInt(engine);

		int sum = dice1 + dice2;

		++rollDice[sum - 2];

	}

	for (unsigned int i = 0; i < rollDice.size(); i++)
	{
		cout << setw(4) << i + 2 << " : " << rollDice[i] << endl;
		
	}
	
}
