#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		if (n == 0) return 0;
		vector<vector<int>> p(m, vector<int>(n + 1, 0));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '0') p[i][j] = 0;
				else
				{
					if (i == 0) p[i][j] = 1;
					else p[i][j] = p[i - 1][j] + 1;
				}
			}
		}
		int area = 0;
		for (int i = 0; i < m; ++i)
		{
			area = max(area, largestRectangleArea(p[i]));
		}
		return area;
	}
	int largestRectangleArea(vector<int> &height) {
		stack<int> st;
		height.push_back(0);
		int i = 0, m = 0;
		while (i<height.size())
		{
			if (st.empty() || height[st.top()] <= height[i])
				st.push(i++);
			else
			{
				int t = st.top();
				st.pop();
				m = max(m, height[t] * (st.empty() ? i : i - st.top() - 1));
			}
		}
		return m;
	}
};

int main()
{
	Solution sol;
	vector<vector<char> > ans;
	vector<char> ans1;
	ans1.push_back('1');
	ans.push_back(ans1);
	cout<<sol.maximalRectangle(ans)<<endl;
	return 0;
}
