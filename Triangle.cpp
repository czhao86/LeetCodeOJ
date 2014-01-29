#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		if (n < 1) return -1;
		int *d = new int[n];
		for (int i = 0; i < n; ++i)
		{
			d[i] = triangle[n-1][i];
		}
		for (int j = n - 2; j >= 0; --j)
		{
			for (int k = 0; k <= j; ++k)
			{
				d[k] = min(d[k], d[k + 1]) + triangle[j][k];
			}
		}
		return d[0];
	}
};

int main()
{
}
