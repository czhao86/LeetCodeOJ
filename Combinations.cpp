#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> temp;
		combinations(res, temp, 1, n, k);
		return res;
	}
	void combinations(vector<vector<int>> &ans, vector<int> &temp, int start, int n, int k)
	{
		if (temp.size() == k)
		{
			ans.push_back(temp);
			return;
		}
		for (int i = start; i <= n; ++i)
		{
			temp.push_back(i);
			combinations(ans, temp, i + 1, n, k);
			temp.pop_back();
		}
	}
};

int main()
{
	vector<vector<int>>::iterator it;
	vector<int>::iterator itt;
	Solution sol;
	vector<vector<int>> ans=sol.combine(4, 2);
	for (it = ans.begin(); it != ans.end(); ++it)
	{
		for (itt = (*it).begin(); itt != (*it).end(); ++itt)
			cout << *itt << ' ';
		cout << endl;
	}
}
