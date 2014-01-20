#include <iostream>
using namespace std;

class Solution {
public:
	int maxSubArray(int A[], int n) {
		int cur_sum = 0;
		int max_sum = A[0];
		for (int i = 0; i < n; ++i)
		{
			if (cur_sum < 0) cur_sum = A[i];
			else (cur_sum += A[i]);
			if (cur_sum>max_sum) max_sum = cur_sum;
		}
		return max_sum;
	}
};

int main()
{
	Solution sol;
	int a[6] = { 3, 5, -7, 9, -4, -2 };
	cout << sol.maxSubArray(a, 6) << endl;
	return 0;
}
