#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char>> &board) {
		if (board.empty()) return;
		int m = board.size();
		int n = board[0].size();
		vector<int> sri, srj;
		for (int i = 0; i < m; ++i)
		{
			if (board[i][0] == 'O')
			{
				sri.push_back(i);
				srj.push_back(0);
			}
			if (board[i][n - 1] == 'O')
			{
				sri.push_back(i);
				srj.push_back(n - 1);
			}
		}
		for (int j = 1; j < n - 1; ++j)
		{
			if (board[0][j] == 'O')
			{
				sri.push_back(0);
				srj.push_back(j);
			}
			if (board[m - 1][j] == 'O')
			{
				sri.push_back(m - 1);
				srj.push_back(j);
			}
		}
		int i = 0;
		while (i < sri.size())
		{
			int x = sri[i];
			int y = srj[i];
			board[x][y] = 'P';
			if (x - 1 >= 1 && board[x - 1][y] == 'O')
			{
				sri.push_back(x - 1);
				srj.push_back(y);
			}
			if (x + 1 < m-1 && board[x + 1][y] == 'O')
			{
				sri.push_back(x + 1);
				srj.push_back(y);
			}
			if (y - 1 >= 1 && board[x][y - 1] == 'O')
			{
				sri.push_back(x);
				srj.push_back(y - 1);
			}
			if (y + 1 < n-1 && board[x][y + 1] == 'O')
			{
				sri.push_back(x);
				srj.push_back(y + 1);
			}
			i++;
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == 'P') board[i][j] = 'O';
			}
		}
	}
};

int main()
{
	vector<vector<char>> board;
	vector<char> t1, t2, t3, t4;
	t1.push_back('X');
	t1.push_back('X');
	t1.push_back('X');
	t1.push_back('X');
	t2.push_back('X');
	t2.push_back('O');
	t2.push_back('O');
	t2.push_back('X');
	t3.push_back('X');
	t3.push_back('X');
	t3.push_back('O');
	t3.push_back('X');
	t4.push_back('X');
	t4.push_back('O');
	t4.push_back('X');
	t4.push_back('X');
	board.push_back(t1);
	board.push_back(t2);
	board.push_back(t3);
	board.push_back(t4);
	vector<vector<char>>::iterator it;
	vector<char>::iterator itt;
	for (it = board.begin(); it != board.end(); ++it)
	{
		for (itt = (*it).begin(); itt != (*it).end(); ++itt)
		{
			cout << *itt << ' ';
		}
		cout << endl;
	}
	cout << endl;
	Solution sol;
	sol.solve(board);
	for (it = board.begin(); it != board.end(); ++it)
	{
		for (itt = (*it).begin(); itt != (*it).end(); ++itt)
		{
			cout << *itt << ' ';
		}
		cout << endl;
	}
	return 0;
}
