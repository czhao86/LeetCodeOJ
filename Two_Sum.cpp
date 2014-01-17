#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int> &numbers, int target) 
	{
		vector<pair<int, int>> num;
		for (int i = 0; i < numbers.size(); ++i)
		{
			num.push_back(make_pair(numbers[i],i+1));
		}
		sort(num.begin(),num.end());
		int m, n;
		int begin=0, end=numbers.size()-1;
		while (begin < end)
		{
			if (num[begin].first + num[end].first == target)
			{
				m = min(num[begin].second, num[end].second);
				n = max(num[begin].second, num[end].second);
				break;
			}
			else if (num[begin].first + num[end].first > target)
				end--;
			else begin++;
		}
		vector<int> res;
		res.push_back(m);
		res.push_back(n);
		return res;
	}
};

int main()
{
	return 0;
}
