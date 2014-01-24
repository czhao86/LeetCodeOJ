#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		int n = s.length();
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				st.push(s[i]);
			}
			else
			{
				if (st.empty()) return false;
				char temp = st.top();
				st.pop();
				if ((temp == '(' && s[i] == ')') || (temp == '[' && s[i] == ']') || (temp == '{' && s[i] == '}'))
					continue;
				else return false;
			}
		}
		if (st.empty()) return true;
		else return false;
	}
};

int main()
{
	return 0;
}
