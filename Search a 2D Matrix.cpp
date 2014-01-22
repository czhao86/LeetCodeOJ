#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		if (target>matrix[m - 1][n - 1]) return false;
		int i;
		for (i = 0; i < m; ++i)
		{
			if (target <= matrix[i][n - 1]) break;
		}
		int j = n - 1;
		while (j >= 0)
		{
			if (target == matrix[i][j]) return true;
			j--;
		}
		return false;
	}
};

int main()
{
	Solution sol;
	return 0;
}
