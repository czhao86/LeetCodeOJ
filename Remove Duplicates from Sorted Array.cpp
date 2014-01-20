#include <iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n <= 1) return n;
		int i = 0;
		for (int j = 1; j < n; ++j)
		{
			if (A[j] != A[i])
				A[++i] = A[j];
		}
		return i+1;
	}
};

int main()
{
	int a[6] = {1,1,3,4,5,5};
	Solution sol;
	cout << sol.removeDuplicates(a, 6) << endl;
	return 0;
}
