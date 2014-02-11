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

int main()
{
	return 0;
}
