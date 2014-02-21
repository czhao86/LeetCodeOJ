#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		bool found = false;
		_solveSudoku(board, 0, found);
	}
	void _solveSudoku(vector<vector<char> > &board, int num, bool &found)
	{
		if (num == 81)
		{
			found = true;
			return;
		}
		int r = num / 9;
		int c = num % 9;
		if (board[r][c] != '.') _solveSudoku(board, num + 1, found);
		else
		{
			vector<bool> tmp(10, false);
			for (int i = 0; i < 9; ++i)
			{
				if (board[r][i] != '.') tmp[board[r][i]-'0'] = true;
				if (board[i][c] != '.') tmp[board[i][c]-'0'] = true;
			}
			int rr = r, cc = c;
			while (rr % 3 != 0) rr--;
			while (cc % 3 != 0) cc--;
			for (int i = rr; i < rr+3; ++i)
			{
				for (int j = cc; j < cc+3; ++j)
				{
					if (board[i][j] != '.') tmp[board[i][j] - '0'] = true;
				}
			}
			for (int i = 1; i < 10; ++i)
			{
				if (!tmp[i])
				{
					board[r][c] = '0'+i;
					_solveSudoku(board, num + 1, found);
					if (found) break;
					board[r][c] = '.';
				}
			}
		}
	}
};

int main(){
	string s[9] = {
		"..9748...",
		"7........",
		".2.1.9...",
		"..7...24.",
		".64.1.59.",
		".98...3..",
		"...8.3.2.",
		"........6",
		"...2759.."
	};
	vector<vector<char> > board;
	for (int i = 0; i<9; ++i){
		vector<char> t;
		for (int j = 0; j<9; ++j){
			t.push_back(s[i][j]);
		}
		board.push_back(t);
	}
	Solution sln;
	sln.solveSudoku(board);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			cout << board[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
