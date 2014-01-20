#include <iostream>
using namespace std;

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		if (target <= A[0]) return 0;
		for (int i = 0; i < n-1; ++i)
		{
			if (target>A[i] && target <= A[i + 1])
			{
				return i + 1;
			}
		}
		return n;
	}
};

int main()
{
	int a[4] = { 1, 3, 5, 6 };
	Solution sol;
	cout<<sol.searchInsert(a, 4, 0)<<endl;
}
