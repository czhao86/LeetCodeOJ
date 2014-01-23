#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		int start = 0, end = n - 1, i;
		int num = 1;
		while (start < end)
		{
			for (i = start; i < end; ++i)
			{
				matrix[start][i] = num;
				num++;
			}
			for (i = start; i < end; ++i)
			{
				matrix[i][end] = num;
				num++;
			}
			for (i = end; i>start; --i)
			{
				matrix[end][i] = num;
				num++;
			}
			for (i = end; i > start; --i)
			{
				matrix[i][start] = num;
				num++;
			}
			start++;
			end--;
		}
		if (start == end) matrix[start][start] = num;
		return matrix;
	}
};

int main()
{
	Solution sol;
	int n = 4;
	vector<vector<int> > res=sol.generateMatrix(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
