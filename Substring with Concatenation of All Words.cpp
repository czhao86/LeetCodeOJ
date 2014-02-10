#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> ans;
		int m = L.size();
		int n = L[0].size();
		map<string, int> words;
		map<string, int> current;
		for (int i = 0; i<m; ++i)
			++words[L[i]];
		if (L.empty() || m*n>S.length()) return ans;
		for (int i = 0; i < S.length() - m*n + 1; ++i)
		{
			int j;
			current.clear();
			for (j = 0; j < m; ++j)
			{
				string tmp = S.substr(i+j*n, n);
				if (words.find(tmp) == words.end())
					break;
				else
				{
					current[tmp]++;
				}
				if (current[tmp]>words[tmp]) break;
			}
			if (j == m) ans.push_back(i);
		}
		return ans;
	}
};

int main()
{
	vector<string> ans;
	ans.push_back("foo");
	ans.push_back("bar");
	string S = "barfoothefoobarman";
	Solution sol;
	vector<int> a = sol.findSubstring(S, ans);
	vector<int>::iterator it;
	for (it = a.begin(); it != a.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
