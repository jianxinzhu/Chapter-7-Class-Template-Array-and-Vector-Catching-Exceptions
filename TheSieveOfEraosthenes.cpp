/*  name: jianxin zhu
    date: july/20/2020
 */
 
 #include<iostream>
#include<array>
#include<iomanip>
using namespace std;

const int SIZE = 1000;
int main()
{
	array<int, SIZE>primeNumber{};

	for (int i = 0; i < primeNumber.size(); i++)
	{
		primeNumber[i] = 1;
	}

	for (int i = 2 ; i <primeNumber.size()/2; i++)
	{

		for (int j = 2; j < primeNumber.size()/2; j++)
		{
			int res = j * i;

			if (res < primeNumber.size())
			{
				primeNumber[res] = 0;
			}
			else
			{
				break;
			}
		}

		
	}


	for (int i = 0; i < primeNumber.size(); i++)
	{
		if (primeNumber[i] == 1)
		{
			cout << i << " ";
		}
	}
}
