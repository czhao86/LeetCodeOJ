#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() <= 1) return 0;
		vector<int>::iterator it;
		it = prices.begin();
		int min_val = *it;
		int max_diff = *(it + 1) - *it;
		for (it = prices.begin() + 1; it != prices.end(); ++it)
		{
			if (*it - min_val > max_diff)
				max_diff = *it - min_val;
			if (*it < min_val)
				min_val = *it;
		}
		if (max_diff < 0) return 0;
		else return max_diff;
	}
};

int main()
{
	vector<int> stock;
	Solution sl;
	stock.push_back(3);
	stock.push_back(2);
	cout << sl.maxProfit(stock) << endl;
	return 0;
}
