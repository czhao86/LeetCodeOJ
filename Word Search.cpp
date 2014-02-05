#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.empty()) return false;
		int m = board.size();
		int n = board[0].size();
		bool ans = false;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == word[0])
				{
					if (existornot(board, word, i, j, 1, visited))
						return true;
				}
			}
		}
		return false;
	}
	bool existornot(vector<vector<char> > &board, string word, int i, int j, int k, vector<vector<bool>> &visited)
	{
		if (k == word.size()) return true;
		bool found = false;
		int h[4] = { -1, 1, 0, 0 };
		int v[4] = { 0, 0, -1, 1 };
		visited[i][j] = true;
		for (int x = 0; x < 4; ++x)
		{
			int ii = i + h[x];
			int jj = j + v[x];
			if (ii >= 0 && ii < board.size() && jj >= 0 && jj < board[0].size() && board[ii][jj] == word[k] && !visited[ii][jj])
			{
				if (existornot(board, word, ii, jj, k + 1, visited))
				{
					found = true;
					break;
				}
			}
		}
		visited[i][j] = false;
		return found;
	}
};

int main()
{
	vector<vector<char> > board;
	vector<char> tmp, tmp1;
	tmp.push_back('a');
	tmp.push_back('a');
	tmp.push_back('a');
	tmp.push_back('a');
	tmp1.push_back('a');
	tmp1.push_back('a');
	tmp1.push_back('a');
	tmp1.push_back('b');
	board.push_back(tmp);
	board.push_back(tmp);
	board.push_back(tmp);
	board.push_back(tmp);
	board.push_back(tmp1);
	Solution sol;
	cout << sol.exist(board, "aaaaaaaaaaaaaaaaaaaa") << endl;
	return 0;
}
