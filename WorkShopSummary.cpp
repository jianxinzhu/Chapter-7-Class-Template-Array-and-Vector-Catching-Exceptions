/*  name: jianxin zhu
    date: july/19/2020
 */
 
 #include<iostream>
#include<iomanip>
#include<array>
using namespace std;

const int ROW = 4;
const int CLO = 4;

int main()
{
	int total_Craft = 0;
	int product_Quantity = 0;
	array<array<int, CLO>, ROW>saleSummary{};
	array<int, CLO>productSummary{};


	for (unsigned int i = 0; i < saleSummary.size() - 1; i++)
	{
		for (unsigned int j = 0; j < saleSummary[i].size(); j++)
		{
			cout << "Enter Person [" << i + 1 << "] Product Quantity: ";
			cin >> product_Quantity;

			saleSummary[i][j] = product_Quantity;
			total_Craft += product_Quantity;
		}
	}

	cout << "**********Month Summary*************" << endl;

	cout << "Person:  " << "  Product 1: " << "Product 2: " << "Product 3: "
		<< "Product 4: " << "Total Quantity: " << endl;

	for (unsigned int i = 0; i < saleSummary.size(); i++)
	{
		int total_Craft_Produce = 0;
		int total_Product_Make = 0;

		if (i == 3)
		{
			cout << "Total:   ";
			for (unsigned int k = 0; k < productSummary.size(); k++)
			{
				productSummary[i] += saleSummary[k][i];
				cout << setw(11) << productSummary[k];
			}

			cout << setw(15) << total_Craft << endl;

			break;

		}
		else
		{
			cout << "Number: " << i + 1;



			for (unsigned int j = 0; j < saleSummary[i].size(); j++)
			{

				cout << setw(11) << saleSummary[i][j];
				total_Craft_Produce += saleSummary[i][j];
				total_Product_Make += saleSummary[j][i];

				if (j == 3)
				{
					productSummary[i] = total_Product_Make;
				}
			}

			cout << setw(15) << total_Craft_Produce << endl;
		}
	}
}
