#include <iostream>
using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		if (n == 0) return 0;
		int count;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] == elem) count++;
			else if (count>0) (A[i - count] = A[i]);
		}
		return n-count;
	}
};
