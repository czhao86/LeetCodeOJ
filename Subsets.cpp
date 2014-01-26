#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > ans;
		sort(S.begin(), S.end());
		if (!S.empty())
		{
			int one = S.back();
			S.pop_back();
			vector<vector<int> > ans1 = subsets(S);
			if (ans1.empty())
			{
				vector<int> tmp;
				ans.push_back(tmp);
				tmp.push_back(one);
				ans.push_back(tmp);
			}
			else
			{
				int n=ans1.size();
				for (int i = 0; i < n; ++i)
				{
					vector<int> temp = ans1.back();
					ans.push_back(temp);
					temp.push_back(one);
					ans.push_back(temp);
					ans1.pop_back();
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(3);
	vector<vector<int> > res = sol.subsets(S);
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
}Subsets
