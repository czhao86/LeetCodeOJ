#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		if (n == 0) return 0;
		vector<int> l(n, 0);
		vector<int> r(n, 0);
		int min = prices[0], max = prices[n - 1];
		for (int i = 1; i < n; ++i)
		{
			l[i] = prices[i] - min>l[i - 1] ? prices[i] - min : l[i - 1];
			min = prices[i] > min ? min : prices[i];
		}
		for (int i = n-2; i >=0; --i)
		{
			r[i] = max - prices[i] > r[i + 1] ? max - prices[i] : r[i + 1];
			max = prices[i] > max ? prices[i] : max;
		}
		int profit = 0;
		for (int i = 0; i < n; ++i)
		{
			if (profit < l[i] + r[i])  profit = l[i] + r[i];
		}
		return profit;
	}
};

int main()
{
	Solution sol;
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(10);
	ans.push_back(100);
	ans.push_back(1000);
	ans.push_back(10);
	ans.push_back(100);
	cout << sol.maxProfit(ans) << endl;
	return 0;
}
