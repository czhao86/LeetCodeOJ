#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		int max = 0, start = 0;
		for (int i = 0; i < n; ++i)
		{
			int p = 1;
			while (i - p >= 0 && i + p < n&&s[i - p] == s[i + p])
			{
				p++;
			}
			int q = 0;
			if (s[i] == s[i + 1])
			{
				q = 1;
				while (i - q >= 0 && i+1 + q < n&&s[i - q] == s[i+1 + q])
				{
					q++;
				}
			}
			if (2*p - 1>max || 2*q > max)
			{
				if (2*p-1>2*q)
				{
					start = i+1 - p;
					max = 2 * p - 1;
				}
				else
				{
					start = i+1 - q;
					max = q * 2;
				}
			}
		}
		return s.substr(start, max);
	}
};

int main()
{
	Solution sol;
	cout << sol.longestPalindrome("abaaaabbbaaa") << endl;
	return 0;
}
