#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int n = digits.size();
		bool more = true;
		for (int i = 0; i < n; ++i)
		{
			if (digits[i] != 9)
			{
				more = false;
				break;
			}
		}
		if (more == true)
		{
			digits[0] = 1;
			for (int i = 1; i < n; ++i)
			{
				digits[i] = 0;
			}
			digits.push_back(0);
		}
		else
		{
			if (digits[n - 1] < 9)
			{
				digits[n - 1]++;
			}
			else
			{
				digits[n - 1] = 0;
				digits[n - 2]++;
			}
			for (int i = n - 2; i >= 0; --i)
			{
				if (digits[i] >= 10)
				{
					digits[i] -= 10;
					digits[i - 1] += 1;
				}
			}
		}
		return digits;
	}
};

int main()
{
	Solution sol;
	vector<int> res,ans;
	res.push_back(9);
	res.push_back(9);
	res.push_back(9);
	for (int i = 0; i < 3; ++i)
	{
		cout << res[i] << ' ';
	}
	cout << endl;
	ans = sol.plusOne(res);
	for (int i = 0; i < 4; ++i)
	{
		cout << res[i] << ' ';
	}
	return 0;
}
