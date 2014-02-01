#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		int sn = S.length();
		int tn = T.length();
		vector<vector<int>> dp(sn+1, vector<int>(tn+1, 0));
		for (int i = 0; i <= sn; ++i)
			dp[i][0] = 1;
		for (int i = 1; i <= sn; ++i)
		{
			for (int j = 1; j <= tn; ++j)
			{
				if (S[i - 1] == T[j - 1]) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
				else dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[sn][tn];
	}
};

int main()
{
	string S = "dd";
	string T = "dd";
	Solution sol;
	cout<<sol.numDistinct(S, T)<<endl;
	return 0;
}
