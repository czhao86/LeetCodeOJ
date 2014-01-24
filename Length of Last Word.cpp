#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int n = strlen(s);
		int pos = n - 1;
		int count = 0;
		while (s[pos] == ' ' && pos) pos--;
		for (int i = pos; i >= 0; --i)
		{
			if (s[i] == ' ') break;
			count++;
		}
		return count;
	}
};

int main()
{
	Solution sol;
	return 0;
}
