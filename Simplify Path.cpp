#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		int i = 0;
		while (i < path.length() - 1)
		{
			if (path[i] == '/'&&path[i + 1] == '/')
				path.erase(i, 1);
			else i++;
		}
		if (path[path.length() - 1] != '/') path = path + "/";
		stack<string> dir;
		int flag = 0;
		string str = "";
		for (int i = 0; i < path.length(); ++i)
		{
			if (path[i] == '/') flag++;
			if (flag == 1) str += path[i];
			if (flag == 2)
			{
				if (str != "/."&&str != "/..") dir.push(str);
				if (str == "/.." && !dir.empty()) dir.pop();
				str = "/";
				flag = 1;
			}
		}
		if (dir.empty()) return "/";
		str = "";
		while (!dir.empty())
		{
			str = dir.top() + str;
			dir.pop();
		}
		return str;
	}
};


int main()
{
	return 0;
}
