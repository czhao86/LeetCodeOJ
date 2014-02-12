#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		assert(s&&p);
		if (*p == '\0') return *s == '\0';
		if (*(p + 1) != '*')
		{
			assert(*p != '*');
			return ((*p == *s) || (*p == '.'&&*s != '\0')) && isMatch(s + 1, p + 1);
		}
		while ((*p == *s) || (*p == '.'&&*s != '\0'))
		{
			if (isMatch(s, p + 2)) return true;
			else s++;
		}
		return isMatch(s, p + 2);
	}
};


int main()
{
	Solution sol;
	cout << sol.isMatch("a","ab*") << endl;
	return 0;
}
