#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty()) return "";
		int n = strs.size();
		int length = strs[0].length();
		int ans=0;
		for (int i = 0; i < length; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (strs[j][i] != strs[0][i])
				{
					ans = i;
					return strs[0].substr(0, ans);
				}
			}
			ans = i+1;
		}
		return strs[0].substr(0, ans);
	}
};

int main()
{
	Solution sol;
	vector<string> a;
	a.push_back("a");
	a.push_back("a");
	cout<<sol.longestCommonPrefix(a)<<endl;
	return 0;
}
