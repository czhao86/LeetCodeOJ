#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		int d[100][100], i, j;
		for (i = 0; i < m; ++i)
		{
			d[i][0] = 1;
		}
		for (i = 0; i < n; ++i)
		{
			d[0][i] = 1;
		}
		for (i = 1; i < m; ++i)
		{
			for (j = 1; j < n; ++j)
			{
				d[i][j] = d[i - 1][j] + d[i][j - 1];
			}
		}
		return d[m-1][n-1];
	}
};

int main()
{
	Solution sl;
	cout << sl.uniquePaths(23, 12) << endl;
	return 0;
}
