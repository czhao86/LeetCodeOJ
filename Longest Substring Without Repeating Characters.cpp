#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.length();
		int ans = 0, max1 = 0;
		bool exist[26] = { false };
		for (int i = 0; i < n; ++i)
		{
			if (exist[s[i] - 'a'])
			{
				max1 = max(max1, ans);
				ans = 1;
				int k = i - 1;
				for (int j = 0; j < 26; ++j)
					exist[j] = false;
				while (s[k] - 'a' != s[i] - 'a')
				{
					ans++;
					exist[s[k] - 'a'] = true;
					k--;
				}
				exist[s[i] - 'a'] = true;
			}
			else
			{
				ans++;
				exist[s[i] - 'a'] = true;
			}
		}
		return max(max1, ans);
	}
};

int main()
{
	Solution sol;
	cout << sol.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << endl;
	return 0;
}
