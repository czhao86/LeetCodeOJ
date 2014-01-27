#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		vector<vector<bool> > column(9, vector<bool>(9, false));
		vector<vector<bool> > row(9, vector<bool>(9, false));
		vector<vector<bool> > block(9, vector<bool>(9, false));
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.') continue;
				int n = board[i][j] - '1';
				if (column[i][n] || row[j][n] || block[i - i % 3 + j / 3][n]) return false;
				column[i][n] = row[j][n] = block[i - i % 3 + j / 3][n] = true;
			}
		}
		return true;
	}
};
