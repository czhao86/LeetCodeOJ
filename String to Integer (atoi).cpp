#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		if (str == NULL) return -1;
		while (*str == ' ') str++;
		int sign = 0;
		if (*str == '+' || *str == '-')
		{
			if (*str == '-') sign = 1;
			else sign = 0;
			str++;
		}
		long long ans = 0;
		while (*str)
		{
			if (*str > '9' || *str < '0') break;
			ans = 10 * ans + (*str - '0');
			if (!sign&&ans>INT_MAX)
			{
				ans = INT_MAX;
				break;
			}
			if (sign&&-ans < INT_MIN)
			{
				ans = INT_MIN;
				break;
			}
			str++;
		}
		return sign ? -ans : ans;
	}
};

int main()
{
	Solution sol;
	cout << sol.atoi("-1232") << endl;
	return 0;
}