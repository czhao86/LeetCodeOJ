#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.length();
		stack<int> st;
		int count = 0, ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '(')
			{
				st.push(count);
				count = 0;
			}
			else if (!st.empty())
			{
				count += 1+st.top();
				st.pop();
				ans = max(ans, count);
			}
			else count = 0;
		}
		return 2*ans;
	}
};

int main()
{
	Solution sol;
	cout << sol.longestValidParentheses("()") << endl;
	return 0;
}