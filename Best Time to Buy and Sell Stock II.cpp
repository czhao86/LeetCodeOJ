#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) return 0;
		vector<int>::iterator it;
		int max_diff = 0;
		for (it = prices.begin(); it != prices.end()-1; ++it)
		{
			if (*(it + 1) > *it) 
				max_diff += (*(it + 1) - *it);
		}
		return max_diff;
	}
};

int main()
{
	vector<int> stock;
	Solution sol;
	stock.push_back(3);
	stock.push_back(2);
	stock.push_back(8);
	stock.push_back(20);
	cout << sol.maxProfit(stock) << endl;
	return 0;
}
