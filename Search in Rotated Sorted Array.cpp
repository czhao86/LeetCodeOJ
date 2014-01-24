#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
		int start = 0, end = n - 1;	
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (target == A[mid]) return mid;
			if (A[start] <= A[mid])
			{
				if (target >= A[start] && target < A[mid])
					end = mid - 1;
				else start = mid + 1;
			}
			else
			{
				if (target>A[mid] && target <= A[end])
					start = mid + 1;
				else end = mid - 1;
			}
		}
		return -1;
	}
};

int main()
{
	int a[6] = { 3, 4,5,6,1,2 };
	Solution sol;
	cout<<sol.search(a, 6, 2)<<endl;
	return 0;
}
