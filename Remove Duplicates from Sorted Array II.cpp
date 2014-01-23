#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0) return 0;
		int count = 1, end = 0;
		for (int i = 1; i < n; ++i)
		{
			if (A[end] == A[i] && count < 2)
			{
				A[++end] = A[i];
				count++;
			}
			if (A[end] != A[i])
			{
				A[++end] = A[i];
				count = 1;
			}
		}
		return end + 1;
	}
};

int main()
{
	Solution sol;
	return 0;
}
