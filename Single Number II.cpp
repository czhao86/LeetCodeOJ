#include <iostream>
using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		int count[32];
		for (int k = 0; k < 32; ++k)
			count[k] = 0;
		int res=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 32; ++j)
			{
				if ((A[i] >> j) & 1) count[j]++;
			}
		}
		for (int j = 0; j < 32; ++j)
		{
			res |= ((count[j] % 3) << j);
		}
		return res;
	}
};

int main()
{
	Solution sol;
	int a[4] = { 1 };
	cout << sol.singleNumber(a, 1) << endl;
	return 0;
}
