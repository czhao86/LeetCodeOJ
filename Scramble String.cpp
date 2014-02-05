#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		int n = s1.length();
		if (n != s2.length()) return false;
		if (s1 == s2) return true;
		vector<vector<vector<bool>>> dp(n,vector<vector<bool>>(n,vector<bool>(n, false)));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				dp[i][j][0] = (s1[i]==s2[j]);
		}
		for (int length = 1; length < n; ++length)
		{
			for (int i = 0; i < n-length; ++i)
			{
				for (int j = 0; j < n-length; ++j)
				{
					for (int mid = 0; mid < length; ++mid)
					{
						if ((dp[i][j][mid] && dp[i + mid + 1][j + mid + 1][length - mid - 1]) || (dp[i][j + mid + 1][length - mid - 1] && dp[i + length - mid][j][mid]))
						{
							dp[i][j][length] = true;
							break;
						}
					}
				}
			}
		}
		cout << dp[0][0][1] << endl;
		cout << dp[0][1][1] << endl;
		cout << dp[1][0][1] << endl;
		cout << dp[1][1][1] << endl;
		cout << dp[0][0][2] << endl;
		cout << dp[0][1][2] << endl;
		cout << dp[1][0][2] << endl;
		cout << dp[1][1][2] << endl;
		return dp[0][0][n - 1];
	}
};

int main()
{
	Solution sol;
	cout << sol.isScramble("abc", "bac") << endl;
	return 0;
}
