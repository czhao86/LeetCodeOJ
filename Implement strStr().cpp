#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		while (true)
		{
			char *p = haystack;
			char *q = needle;
			while (*q && *p == *q)
			{
				p++;
				q++;
			}
			if (!*q) return haystack;
			if (!*p) return NULL;
			haystack++;
		}
	}
};

int main()
{
	Solution sol;
	cout << sol.divide(-120,3) << endl;
	return 0;
}
