#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int n = num.size();
		if (n <= 1) return;
		for (int i = n - 1; i > 0; --i)
		{
			if (num[i - 1] < num[i])
			{
				for (int j = n - 1; j >= i; --j)
				{
					if (num[j] > num[i - 1])
					{
						swap(num[j], num[i - 1]);
						sort(num.begin() + i, num.end());
						return;
					}
				}
			}
		}
		sort(num.begin(), num.end());
	}
};

int main()
{
	Solution sol;
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(2);
	sol.nextPermutation(ans);
	vector<int>::iterator it;
	for (it = ans.begin(); it != ans.end(); ++it)
		cout << *it << ' ';
}
