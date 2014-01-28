#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string s;
		if (n == 0) return "";
		for (int i = 0; i < n; ++i)
		{
			s = next(s);
		}
		return s;
	}
	string next(string n)
	{
		if (n == "") return "1";
		string temp;
		for (int i = 0; i < n.size(); ++i)
		{
			int count = 1;
			while (n[i] == n[i + 1] && i + 1 < n.size())
			{
				i++;
				count++;
			}
			stringstream ss;
			ss << count;
			temp += ss.str();
			temp += n[i];
		}
		return temp;
	}
};

int main()
{
	Solution sol;
	cout << sol.countAndSay(5) << endl;
}
