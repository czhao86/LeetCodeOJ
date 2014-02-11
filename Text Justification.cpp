#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> res;
		int n = words.size();
		if (words.empty()) return res;
		int j;
		for (int i = 0; i < n; )
		{
			int l1 = words[i].size();
			j = i + 1;
			while (j<n && l1 + words[j].size() + 1<=L)
			{
				l1 = l1 + words[j].size()+1;
				j++;
			}
			l1 = l1 - (j-i)+1;
			if (j == i + 1 && j!=n)
			{
				string tmp1 = words[i];
				for (int x = 0; x < L-words[i].size(); ++x)
					tmp1 += " ";
				res.push_back(tmp1);
				i++;
				continue;
			}
			string tmp = "";
			string ans = words[i];
			if (j != n)
			{
				for (int x = 0; x < (L - l1) / (j - i - 1); ++x)
					tmp += " ";
				for (int x = 0; x < (L - l1) % (j - i - 1); ++x)
					words[x + i + 1] = " " + words[x + i + 1];
				for (int y = i + 1; y < j; ++y)
					ans += tmp + words[y];
			}
			else if (j == n)
			{
				tmp += " ";
				for (int y = i + 1; y < j; ++y)
					ans += tmp + words[y];
				string tmp1 = "";
				for (int x = 0; x < L - l1-(j-i-1); ++x)
					tmp1 += " ";
				ans = ans+tmp1;
			}
			res.push_back(ans);
			i = j;
		}
		return res;
	}
};

int main()
{
	vector<string> words, ans;
	words.push_back("world");
	words.push_back("owes");
	words.push_back("you");
	words.push_back("a");
	words.push_back("living;");
	words.push_back("the");
	words.push_back("justification");
	//words.push_back("end");
	Solution sol;
	ans = sol.fullJustify(words, 30);
	vector<string>::iterator it;
	for (it = ans.begin(); it != ans.end(); ++it)
		cout << *it << endl;
	return 0;
}
