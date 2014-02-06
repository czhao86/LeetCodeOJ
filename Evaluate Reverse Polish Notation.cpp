#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<string> st;
		st.push(tokens[0]);
		int i = 1;
		while (i<tokens.size())
		{
			if (tokens[i] != "+"&&tokens[i] != "-"&&tokens[i] != "*"&&tokens[i] != "/")
				st.push(tokens[i]);
			else
			{
				if (st.size() == 1) break;
				string f = st.top();
				st.pop();
				string s = st.top();
				st.pop();
				if (tokens[i] == "+")
				{
					int tmp = atoi(f.c_str()) + atoi(s.c_str());
					st.push(to_string(tmp));
				}
				if (tokens[i] == "-")
				{
					int tmp = atoi(s.c_str()) - atoi(f.c_str());
					st.push(to_string(tmp));
				}
				if (tokens[i] == "*")
				{
					int tmp = atoi(f.c_str()) * atoi(s.c_str());
					st.push(to_string(tmp));
				}
				if (tokens[i] == "/")
				{
					int tmp = atoi(s.c_str()) / atoi(f.c_str());
					st.push(to_string(tmp));
				}
			}
			i++;
		}
		return atoi(st.top().c_str());
	}
};

int main()
{
	Solution sol;
	vector<string> ans;
	//ans.push_back("2");
	//ans.push_back("1");
	//ans.push_back("+");
	//ans.push_back("3");
	//ans.push_back("*");
	ans.push_back("0");
	ans.push_back("3");
	ans.push_back("/");
	cout << sol.evalRPN(ans) << endl;
	return 0;
}
