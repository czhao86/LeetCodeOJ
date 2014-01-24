#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int n = num.size();
		sort(num.begin(),num.end());
		int v;
		int start, end;
		int diff=INT_MAX, ans;
		for (int i = n-1; i >= 2; --i)
		{
			v = num[i];
			start = 0;
			end = i - 1;
			while (start < end)
			{
				if (num[start] + num[end] != target - v)
				{
					int current = abs(target - num[start] - num[end] - v);
					if (current < diff)
					{
						diff = current;
						ans = num[start] + num[end] + v;
					}
				}
				if (num[start] + num[end] == target - v) return target;
				if (num[start] + num[end] < target - v) start++;
				else end--;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	cout<<sol.threeSumClosest(a,0)<<endl;
	return 0;
}
