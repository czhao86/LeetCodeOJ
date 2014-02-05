#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		string tmp;
		vector<string> ans;
		if (s.length() > 12) return ans;
		_restore(ans, tmp, s, 0, 0);
		return ans;
	}
	void _restore(vector<string> &ans, string &tmp, string s, int site, int num)
	{
	        if (site == 4 && num == s.size())
		{
			ans.push_back(tmp);
			return;
		}
		int x = 0;
		for (int i = num; i-num<=2, i < s.size(); ++i)
		{
			x = 10 * x + s[i] - '0';
			if (x >= 0 && x <= 255)
			{
				int te = tmp.size();
				if (tmp.size() != 0) tmp.push_back('.');
				tmp += s.substr(num, i - num + 1);
				_restore(ans, tmp, s, site + 1, i + 1);
				tmp.resize(te);
				if (x == 0) break;
			}
		}
	}
};

int main()
{
	Solution sol;
	vector<string> ans;
	ans = sol.restoreIpAddresses("1111");
	vector<string>::iterator it;
	for (it = ans.begin(); it != ans.end(); ++it)
		cout << *it << endl;
	return 0;
}
