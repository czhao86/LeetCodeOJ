#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		int* C = new int[n];
		memset(C, -1, sizeof(C));
		vector<vector<string> > ans;
		int count = 0;
		placeQueen(ans, 0, n, C,count);
		delete[] C;
		return count;
	}
	void placeQueen(vector<vector<string> > &ans, int row, int n, int* C, int &count)
	{

		if (row == n)
		{
			count++;
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			bool test = true;
			C[row] = i;
			for (int j = 0; j < row; ++j)
			{
				if (abs(C[row] - C[j]) == row - j || row == j || C[row] == C[j])
				{
					test = false;
					break;
				}
			}
			if (test)
			{
				placeQueen(ans, row + 1, n, C, count);
			}
		}
	}
};

int main()
{
	Solution sol;
	cout << sol.totalNQueens(5) << endl;
	return 0;
}
