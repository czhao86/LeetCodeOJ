#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int *a = new int[m + n];
		memcpy(a, A, sizeof(int)*m);
		memcpy(a + m, B, sizeof(int)*n);
		sort(a, a + m + n);
		double median = (double)((n + m) % 2 ? a[(n + m) >> 1] : (a[(n + m - 1) >> 1] + a[(n + m) >> 1]) / 2.0);
		return median;
	}
};

class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n){
		if ((m + n) % 2 == 0)
			return (find(A, m, B, n, (m + n) / 2) + find(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
		else return find(A, m, B, n, (m + n) / 2 + 1);
	}
	double find(int A[], int m, int B[], int n, int k)
	{
		if (m > n) return find(B, n, A, m, k);
		if (m == 0) return B[k - 1];
		if (k == 1) return min(A[0], B[0]);
		int x = min(k / 2, m), y = k - x;
		if (A[x - 1] < B[y - 1])
			return find(A + x, m - x, B, n, k - x);
		else if (A[x - 1] > B[y - 1])
			return find(A, m, B + y, n - y, k - y);
		else return A[x - 1];
	}
};

int main()
{
	return 0;
}
