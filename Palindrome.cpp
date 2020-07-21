/*  name: jianxin zhu
    date: july/20/2020
*/

#include<vector>
#include<iostream>

using namespace std;


bool testPalindrome(vector<char>word, int left, int right)
{
	if (left == right)
	{
		return true;
	}
	else if(word[left]!=word[right])
	{
		return false;
	}
	else
	{
		return testPalindrome(word, left + 1, right - 1);
	}
}


int main()
{
	vector<char>v1{};

	char c;

	cout << "Enter your word:";

	while (cin >> c)
	{
		v1.push_back(c);
	}

	for (auto i : v1)
	{
		cout << i;
	}

	cout << "The sentence is: " << (testPalindrome(v1, 0, v1.size() - 1) ? "a Palindrome" : "not a Palindrome") << endl;
}
