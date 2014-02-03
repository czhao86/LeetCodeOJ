#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) return true;
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			while (i < j&&!isatoz(s[i])) i++;
			while (i < j&&!isatoz(s[j])) j--;
			if (!isequal(s[i], s[j])) return false;
			i++, j--;
		}
		return true;
	}
	bool isatoz(char a)
	{
		if ((a - 'a' >= 0 && a - 'a' <= 25) || (a - 'A' >= 0 && a - 'A' <= 25) || (a - '0' >= 0 && a - '0' <= 9))
			return true;
		else return false;
	}
	bool isequal(char a, char b)
	{
		if (a > b)
		{
			char x;
			x = a, a = b, b = x;
		}
		return b == a || b - 32 == a;
	}
};

int main()
{
	Solution sol;
	cout << sol.isPalindrome("1a2") << endl;;
	return 0;
}
