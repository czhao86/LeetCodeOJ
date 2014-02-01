#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int> > ans;
		vector<int> tmp;
		set<vector<int>> s;
		sort(num.begin(), num.end());
		_combinationSum(ans, tmp, num, 0, target, s);
		return ans;
	}
	void _combinationSum(vector<vector<int> > &ans, vector<int> &tmp, vector<int> num, int start, int target, set<vector<int>> &s)
	{
		if (target == 0)
		{
			if (s.find(tmp) == s.end())
			{
				ans.push_back(tmp);
				s.insert(tmp);
				return;
			}

		}
		for (int i = start; i < num.size() && target - num[i] >= 0; ++i)
		{
			tmp.push_back(num[i]);
			_combinationSum(ans, tmp, num, i + 1, target - num[i], s);
			tmp.pop_back();
		}
	}
};
