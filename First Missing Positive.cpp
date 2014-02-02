#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution  {
public:
	int firstMissingPositive(int A[], int n) {
		for (int i = 0; i < n; ++i)
		{
			if (A[i]>0 && A[i] <= n)
			{
				if (A[i] - 1 != i && A[A[i] - 1] != A[i])
				{
					swap(A[A[i] - 1], A[i]);
					i--;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (A[i] - 1 != i) return i + 1;
		}
		return n+1;
	}
};

int main()
{
	Solution sol;
	int A[4] = { 3, 4, -1,1 };
	cout<<sol.firstMissingPositive(A,4)<<endl;
}
