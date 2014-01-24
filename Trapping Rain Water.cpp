#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(int A[], int n) {
		if (n <= 2) return 0;
		int ans=0;
		int *lm = new int[n];
		int *rm = new int[n];
		lm[0] = 0;
		for (int i = 1; i < n; ++i)
		{
			lm[i] = A[i-1];
			if (lm[i] < lm[i - 1]) lm[i] = lm[i - 1];
		}
		rm[n - 1] = 0;
		for (int j = n - 2; j >= 0; --j)
		{
			rm[j] = A[j+1];
			if (rm[j+1]>rm[j]) rm[j] = rm[j+1];	
			if (rm[j] - A[j] > 0 && lm[j] - A[j] > 0)
			{
				ans += min(rm[j] - A[j], lm[j] - A[j]);
			}
		}
		return ans;
	}
};

int main()
{
	int a[3] = { 0, 2, 0 };
	Solution sol;
	cout << sol.trap(a, 3) << endl;
	return 0;
}
