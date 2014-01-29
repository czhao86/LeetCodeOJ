#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int sqrt(int x) {
		if (x < 0) return -1;
		if (x == 0 || x == 1) return x;
		int start = 0, end = x;
		while (start <= end)
		{
			long long tmp;
			int mid = start + (end - start) / 2;
			tmp = (long long)mid*mid;
			if (tmp == x) return mid;
			if (tmp>x) end = mid - 1;
			else start = mid + 1;
		}
		return end;
	}
};

int main()
{
	Solution sol;
	cout<<sol.sqrt(256)<<endl;
	return 0;
}
