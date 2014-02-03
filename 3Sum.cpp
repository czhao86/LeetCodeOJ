#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ans;
		vector<vector<int> > tmp;
		sort(num.begin(), num.end());
		int v, prev=INT_MIN;
		while (!num.empty())
		{
			v = num.back();
			num.pop_back();
			if (v < 0) break;
			if (v == prev) continue;
			prev = v;
			tmp = twoSum(num, -v);
			if (tmp.empty()) continue;
			for (int i = 0; i < tmp.size(); ++i)
			{
				tmp[i].push_back(v);
				ans.push_back(tmp[i]);
			}
			tmp.clear();
		}
		return ans;
	}
	vector<vector<int> > twoSum(vector<int> &num, int target)
	{
		vector<vector<int> > vvi;
		vector<int> vi(2);
		int b = 0, e = num.size() - 1;
		while (b < e)
		{
			if (num[b] + num[e] == target)
			{
				vi[0]=(num[b]);
				vi[1]=(num[e]);
				vvi.push_back(vi);
				while (b < e&&num[e] == num[e - 1]) e--;
				while (b < e&&num[b] == num[b + 1]) b++;
				e--, b++;
			}
			else if (num[b] + num[e] > target) e--;
			else if (num[b] + num[e] < target) b++;
		}
		return vvi;
	}
};

int main()
{
	return 0;
}
