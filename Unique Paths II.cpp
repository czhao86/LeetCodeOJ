#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
		int i;
		vector<vector<int>> path;
		for (int i = 0; i < m; ++i)
		{
			vector<int> temp;
			for (int j = 0; j < n; ++j)
			{
				temp.push_back(0);
			}
			path.push_back(temp);
		}
		for (i = 0; i < m; ++i)
		{
			if (obstacleGrid[i][0] != 1) path[i][0] = 1;
			else break;
		}
		int j;
		for (j = 1; j < n; ++j)
		{
			if (obstacleGrid[0][j] != 1) path[0][j] = 1;
			else break;
		}

		for (int k = 1; k < m; ++k)
		{
			for (int l = 1; l < n; ++l)
			{
				if (obstacleGrid[k][l] != 1)
				{
					if (obstacleGrid[k][l - 1] == 1 && obstacleGrid[k - 1][l] == 1)
						path[k][l] = 0;
					else if (obstacleGrid[k][l - 1] != 1 && obstacleGrid[k - 1][l] == 1)
						path[k][l] = path[k][l - 1];
					else if (obstacleGrid[k][l - 1] == 1 && obstacleGrid[k - 1][l] != 1)
						path[k][l] = path[k - 1][l];
					else if (obstacleGrid[k][l - 1] != 1 && obstacleGrid[k - 1][l] != 1)
						path[k][l] = path[k - 1][l] + path[k][l - 1];
				}
			}
		}
		return path[m - 1][n - 1];
	}
};

int main()
{
	vector<vector<int> > ans;
	vector<int> tmp1, tmp2, tmp3;
	for (int i = 0; i < 3; ++i)
	{
		tmp1.push_back(0);
		tmp3.push_back(0);
	}
	tmp2.push_back(0);
	tmp2.push_back(1);
	tmp2.push_back(0);
	ans.push_back(tmp2);
	ans.push_back(tmp2);
	ans.push_back(tmp3);
	Solution sol;
	cout<<sol.uniquePathsWithObstacles(ans)<<endl;
	return 0;
}
