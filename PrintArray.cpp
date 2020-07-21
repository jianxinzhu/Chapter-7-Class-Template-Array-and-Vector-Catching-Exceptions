/*   name: jianxin zhu
     date: july/20/2020
 */
 
#include<array>
#include<iostream>

using namespace std;
const int SIZE = 20;

void printArray(array<int, SIZE>a1, size_t beginNumber, size_t endNumber)
{
	if (beginNumber < endNumber)
	{
		cout << a1[beginNumber]<<" ";
		printArray(a1, beginNumber+1, endNumber);

	}
		
	
}

int main()
{
	array<int, SIZE>a1{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int i, j=0;


	cout << "Print Array: ";
	printArray(a1, 0, SIZE);

}
