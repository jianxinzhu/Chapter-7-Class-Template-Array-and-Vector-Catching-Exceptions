/*    name: jianxin zhu
      date: july/20/2020
*/


#include<iostream>
#include<vector>

using namespace std;

void stringBackward(vector<char>v1, size_t beginNumber, size_t endNumber)
{
	if (endNumber == beginNumber)
	{
		cout<< v1[beginNumber];
	}
	else
	{
		cout << v1[endNumber];
		stringBackward(v1, beginNumber, endNumber - 1);
	}
}

int main()
{
	vector<char>v1{};
	char c;

	cout << "Enter your sentence: ";

	while (cin >> c)
	{
		v1.push_back(c);
	}

	cout << "Print the sentence backward: ";
	stringBackward(v1, 0, v1.size() - 1);

}
