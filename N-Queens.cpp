#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		int* C = new int[n];
		memset(C, -1, sizeof(C));
		vector<vector<string> > ans;
		placeQueen(ans, 0, n, C);
		delete[] C;
		return ans;
	}
	void placeQueen(vector<vector<string> > &ans, int row, int n, int* C)
	{

		if (row == n)
		{
			vector<string> temp;
			for (int ii = 0; ii < n; ++ii)
			{
				string s(n,'.');
				s[C[ii]] = 'Q';
				temp.push_back(s);
			}
			ans.push_back(temp);
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
				placeQueen(ans, row + 1, n, C);
			}
		}
	}

};

int main()
{
	Solution sol;
	vector<vector<string> > ans=sol.solveNQueens(4);
	vector<vector<string> >::iterator it;
	vector<string>::iterator itt;
	for (it = ans.begin(); it != ans.end(); ++it)
	{
		for (itt = (*it).begin(); itt != (*it).end(); ++itt)
		{
			cout << *itt << endl;
		}
		cout << endl;
	}
	return 0;
}
