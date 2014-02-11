#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		const char *ss = NULL, *pp = NULL;
		while (*s)
		{
			if (*p=='?' || *p == *s)
			{
				s++;
				p++;
			}
			else if (*p == '*')
			{
				while (*p == '*') p++;
				if (!*p) return true;
				ss = s;
				pp = p;
			}
			else if (*p != *s && ss)
			{
				s = ss++;
				p = pp;
			}
			else return false;
		}
		while (*p == '*') p++;
		return (!*p);
	}
};

int main()
{
	Solution sol;
	bool ans = sol.isMatch("geeks", "g*ks");
	cout << ans << endl;
	return 0;
}
