#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		stack<int> st;
		height.push_back(0);
		int i = 0, m = 0;
		while (i<height.size())
		{
			if (st.empty() || height[st.top()]<=height[i])
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
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(2);
	cout << sol.largestRectangleArea(ans) << endl;
	return 0;
}
