#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		map<string, vector<string>> dict;
		vector<string> ans;
		vector<string>::iterator it;
		for (it = strs.begin(); it != strs.end(); ++it)
		{
			string temp = *it;
			sort(temp.begin(), temp.end());
			dict[temp].push_back(*it);
		}
		map<string, vector<string>>::iterator th;
		for (th = dict.begin(); th != dict.end(); ++th)
		{
			if (th->second.size() > 1)
			{
				for (it = th->second.begin(); it != th->second.end(); ++it)
					ans.push_back(*it);
			}
		}
		return ans;
	}
};

int main(){
	Solution sol;
	vector<string> tmp;
	string a = "and";
	string b = "dan";
	tmp.push_back(a);
	tmp.push_back(b);
	vector<string> res = sol.anagrams(tmp);
	cout << res[0] << endl;
	return 0;
}
