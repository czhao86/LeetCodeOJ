#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		paren(ans, "", 0, 0, n);
		return ans;
	}
	void paren(vector<string> &ans, string s, int left, int right, int n)
	{
		if (left == n && right == n)
		{
			ans.push_back(s);
		}
		if (left < n)
		{
			paren(ans, s + '(', left + 1, right, n);
		}
		if (left>right)
		{
			paren(ans, s + ')', left, right + 1, n);
		}
	}

};

int main()
{
	Solution sl;
	vector<string> result = sl.generateParenthesis(3);
	vector<string>::iterator it;
	for (it = result.begin(); it != result.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
