#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int n1 = num1.length();
		int n2 = num2.length();
		vector<int> vi1(n1, 0);
		vector<int> vi2(n2, 0);
		vector<int> vi(n1+n2, 0);
		string ans="";
		if (num1=="0" || num2 == "0") return "0";
		for (int i = 0; i < n1; ++i)
			vi1[i] = num1[i] - '0';
		for (int i = 0; i < n2; ++i)
			vi2[i] = num2[i] - '0';
		for (int i = 0; i < n1; ++i)
		{
			for (int j = 0; j < n2; ++j)
			{
				vi[i + j+1] += vi1[i] * vi2[j];
			}
		}
		int up = 0;
		for (int i = n1+n2-1; i >=0; --i)
		{
				char tmp = '0' + (vi[i] % 10);
				ans = tmp+ans;
				if (i>0) vi[i-1] += vi[i] / 10;
		}
		string tmp;
		if (ans[0] == '0')
		{
			tmp = ans.substr(1, ans.length() - 1);
			return tmp;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	cout << sol.multiply("123", "456") << endl;
	return 0;
}