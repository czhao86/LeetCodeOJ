#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 1) return 1;
		if (n == 2) return 2;
		int *sol = new int[n];
		sol[0] = 1;
		sol[1] = 2;
		for (int i = 2; i < n; ++i)
		{
			sol[i] = sol[i - 2] + sol[i - 1];
		}
		return sol[n-1];
	}
};
