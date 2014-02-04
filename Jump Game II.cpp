#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
		int start = 0, end = 0, count = 0;
		if (n == 1) return 0;
		while (end < n)
		{
			int max = 0;
			count++;
			for (int i = start; i <= end; ++i)
			{
				if (A[i] + i >= n - 1) return count;
				if (A[i] + i > max) max = A[i] + i;
			}
			start = end + 1;
			end = max;
		}
	}
};

int main()
{
	Solution sol;
	int a[5] = { 1,2,1,1,1 };
	cout<<sol.jump(a, 5)<<endl;
	return 0;
}
