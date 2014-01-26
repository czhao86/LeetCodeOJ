#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vector<vector<int> > ans;
		sort(S.begin(), S.end());
		if (!S.empty())
		{
			int one = S.back();
			S.pop_back();
			vector<vector<int> > ans1 = subsetsWithDup(S);
			if (ans1.empty())
			{
				vector<int> tmp;
				ans.push_back(tmp);
				tmp.push_back(one);
				ans.push_back(tmp);
			}
			else
			{
				set<vector<int>> set;
				int n = ans1.size();
				for (int i = 0; i < n; ++i)
				{
					vector<int> temp = ans1.back();
					if (set.find(temp) == set.end())
					{
						ans.push_back(temp);
						set.insert(temp);
					}
					temp.push_back(one);
					if (set.find(temp) == set.end())
					{
						ans.push_back(temp);
						set.insert(temp);
					}
					ans1.pop_back();
				}
			}
		}
		return ans;
	}
};
