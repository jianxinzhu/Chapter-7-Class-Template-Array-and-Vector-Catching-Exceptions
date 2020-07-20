/*  name: jianxin zhu
    date: july/19/2020
 */
 
 #include<iostream>
#include<random>
#include<iomanip>
#include<array>
#include<ctime>
using namespace std;


random_device rd;
mt19937 gen(rd());

inline unsigned int rollDice()
{
	int die1 = uniform_int_distribution<unsigned int>{ 1, 6 }(gen);
	int die2 = uniform_int_distribution<unsigned int>{ 1, 6 }(gen);
	int sum = die1 + die2;
	return sum;
}
const int arraySize = 20;
const int totalGame = 1000;

int main()
{
	enum class Status { CONTINUE, WON, LOST };
	int total_Won = 0;
	int total_Lost = 0;
	int total_Game_Length = 0;
	array<int, arraySize>crapGameWonSummary{};
	array<int, arraySize>crapGameLostSummary{};

	for (unsigned int i = 1; i <= totalGame; i++)
	{
		int flag = 0;
		unsigned int myPoint = 0;
		Status myStatus;

		unsigned int sumOfDice = rollDice();

		switch (sumOfDice)
		{
		case 7:
		case 11:
			myStatus = Status::WON;
			flag++;
			break;
		case 2:
		case 3:
		case 12:
			myStatus = Status::LOST;
			flag++;
			break;
		default:
			myStatus = Status::CONTINUE;
			flag++;
			myPoint = sumOfDice;
			break;
		}


		while (Status::CONTINUE == myStatus)
		{
			sumOfDice = rollDice();

			if (sumOfDice == myPoint)
			{
				myStatus = Status::WON;
				flag++;
			}
			else
			{
				if (sumOfDice == 7)
				{
					myStatus = Status::LOST;
					flag++;
				}
				flag++;
			}
		}

		if (Status::WON == myStatus)
		{
			if (flag > 20)
			{
				++crapGameWonSummary[19];
				total_Game_Length += flag;
			}
			else
			{
				++crapGameWonSummary[flag - 1];
				total_Game_Length += flag;
			}
		}
		else
		{
			if (flag > 20)
			{
				++crapGameLostSummary[19];
				total_Game_Length += flag;
			}
			else
			{
				++crapGameLostSummary[flag - 1];
				total_Game_Length += flag;
			}
		}
	}

	cout << setw(10) << "*******Crap Game Won Summary***********" << endl;

	for (unsigned int i = 0; i < arraySize; i++)
	{
		cout << "Won in " << setw(4) << i + 1 << " Roll : " << setw(3) << crapGameWonSummary[i]
			<< "| Lost in " << setw(4) << i + 1 << " Roll : " << setw(3) << crapGameLostSummary[i] << endl;

		total_Won += crapGameWonSummary[i];
		total_Lost += crapGameLostSummary[i];
	}
	double percentage_Of_Winning = (static_cast<double>(total_Won) / totalGame) * 100;
	double average_Length_Game = static_cast<double>(total_Game_Length) / totalGame;
	cout << "-------------------------------------" << endl;
	cout << "Total Won: " << total_Won << endl;
	cout << "Total Lost: " << total_Lost << endl;
	cout << "Winning Percentage: " << percentage_Of_Winning << "%" << endl;
	cout << "Average of Length for each Game: " << average_Length_Game << endl;


}
