#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.length();
		int n = s2.length();
		int mn = s3.length();
		if (m + n != mn) return false;
		vector<vector<bool>> res(m+1, vector<bool>(n+1, false));
		for (int i = 0; i <= m; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				if (i == 0 && j == 0) res[i][j] = true;
				else if (i == 0 && s2[j - 1] == s3[j - 1])
					res[0][j] = res[0][j - 1];
				else if (j == 0 && s1[i - 1] == s3[i - 1])
					res[i][0] = res[i - 1][0];
				else if (i != 0 && j != 0 && s1[i - 1] == s3[i + j - 1] && s2[j - 1] != s3[i + j - 1])
					res[i][j] = res[i - 1][j];
				else if (i != 0 && j != 0 && s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
					res[i][j] = res[i][j - 1];
				else if (i != 0 && j != 0 && s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
					res[i][j] = (res[i][j - 1] || res[i - 1][j]);
			}
		}
		return res[m][n];
	}
};

int main()
{
	Solution sol;
	cout << sol.isInterleave("aab", "aac", "aabaac") << endl;
	return 0;
}
