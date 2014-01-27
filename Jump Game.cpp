#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		int reach = 1;
		for (int i = 0; i < reach&& reach < n; ++i)
		{
			reach = max(reach, A[i] + i + 1);
		}
		return reach >= n;
	}
};
