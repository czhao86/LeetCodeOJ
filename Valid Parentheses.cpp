class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		int n = s.length();
		for (int i = 0; i < n; ++i)
		{
			char c = s[i];
			if (c== '(' || c == '[' || c == '{')
			{
				st.push(c);
			}
			else
			{
				if (st.empty()) return false;
				char temp=st.top();
				st.pop();
				if ((temp == '(' && c == ')') || (temp == '[' && c == ']') || (temp == '{' && c == '}'))
					continue;
				else return false;
			}
		}
		if (st.empty()) return true;
		else return false;
	}
};
