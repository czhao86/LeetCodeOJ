#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		string temp;
		if (digits.length() == 0)
		{
			ans.push_back(temp);
			return ans;
		}
		char table[10][4] =
		{ { ' ', 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 'a', 'b', 'c', 0 },
		{ 'd', 'e', 'f', 0 },
		{ 'g', 'h', 'i', 0 },
		{ 'j', 'k', 'l', 0 },
		{ 'm', 'n', 'o', 0 },
		{ 'p', 'q', 'r', 's' },
		{ 't', 'u', 'v', 0 },
		{ 'w', 'x', 'y', 'z' },
		};
		_letterCombinations(ans, temp, digits, 0, table);
		return ans;
	}
	void _letterCombinations(vector<string> &ans, string &temp, string &digits, int pos, char table[][4])
	{
		if (pos == digits.length())
		{
			ans.push_back(temp);
			cout << temp << endl;
			return;
		}
		int n = 3;
		int x = digits[pos] - '0';
		if (x == 0) n = 1;
		if (x == 1) n = 0;
		if (x == 7 || x == 9) n = 4;
		if (digits[pos] == '1') _letterCombinations(ans, temp, digits, pos + 1, table);
		for (int i = 0; i < n; ++i)
		{
			//int ss = temp.length();
			temp.push_back(table[x][i]);
			_letterCombinations(ans, temp, digits, pos + 1, table);
			temp.pop_back();
			//temp.resize(ss);
		}
	}
};

int main()
{
	Solution sol;
	vector<string> ans = sol.letterCombinations("013887");
	return 0;
}
