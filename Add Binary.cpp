#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.length() < b.length())
		{
			string tmp;
			tmp = a;
			a = b;
			b = tmp;
		}
		int m = a.length();
		int n = b.length();
		int x = 0;
		string c = a;
		for (int i = 0; i<m - n; ++i)
			b = '0' + b;
		while (m>0)
		{
			if (a[m - 1] - '0' + b[m - 1] - '0' + x == 0)
			{
				c[m - 1] = '0'; x = 0;
			}
			else if (a[m - 1] - '0' + b[m - 1] - '0' + x == 1)
			{
				c[m - 1] = '1'; x = 0;
			}
			else if (a[m - 1] - '0' + b[m - 1] - '0' + x == 2)
			{
				c[m - 1] = '0'; x = 1;
			}
			else if (a[m - 1] - '0' + b[m - 1] - '0' + x == 3)
			{
				c[m - 1] = '1'; x = 1;
			}
			m--;
		}
		if (x == 1) c = '1' + c;
		return c;
	}
};

int main()
{
	Solution sol;
	string a = "10";
	string b = "111";
	cout << sol.addBinary(a, b) << endl;
	return 0;
}
