#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int>> ans;
		int n = num.size();
		if (n < 4) return ans;
		vector<int> x(4);
		sort(num.begin(), num.end());
		set<string> dup;
		for (int i = 0; i < n - 3; ++i)
		{
			x[0] = num[i];
			for (int j = i + 1; j < n - 2;++j)
			{
				x[1] = num[j];
				int begin = j + 1;
				int end = n - 1;
				while (begin < end)
				{
					if (num[begin] + num[end] + x[0] + x[1] == target)
					{
						x[2] = num[begin];
						x[3] = num[end];
						string str;
						str += x[0];
						str += x[1];
						str += x[2];
						str += x[3];
						set<string>::iterator it = dup.find(str);
						if (it == dup.end())
						{
							dup.insert(str);
							ans.push_back(x);
						}
						begin++;
						end--;
					}
					else if (num[begin] + num[end] + x[0] + x[1] > target) end--;
					else if (num[begin] + num[end] + x[0] + x[1] < target) begin++;
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(0);
	ans.push_back(-1);
	ans.push_back(0);
	ans.push_back(-2);
	ans.push_back(2);
	vector<vector<int> > res;
	res=sol.fourSum(ans, 0);
	vector<vector<int> >::iterator it;
	vector<int>::iterator itt;
	for (it = res.begin(); it != res.end(); ++it)
	{
		for (itt = (*it).begin(); itt != (*it).end(); ++itt)
		{
			cout << *itt << ' ';
		}
		cout << endl;
	}
	return 0;
}
