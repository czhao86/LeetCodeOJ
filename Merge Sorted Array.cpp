#include <iostream>
using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int total = m + n;
		while (m > 0 && n>0)
		{
			if (A[m - 1] > B[n - 1])
				A[--total] = A[--m];
			else
				A[--total] = B[--n];
		}
		while (n > 0)
			A[--total] = B[--n];
	}
};

int main()
{
	Solution sol;
	int a[11] = { 10,20,30 };
	int b[8] = { 2,5,6,11,12,13,16,19 };
	sol.merge(a, 3, b, 7);

	return 0;
}
