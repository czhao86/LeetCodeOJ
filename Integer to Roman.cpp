#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string res;
		int val[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string sym[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int i = 0, times;
		while (num > 0)
		{
			if (num / val[i])
			{
				times = num / val[i];
				num -= val[i] * times;
				for (int j = 0; j < times; ++j)
					res += sym[i];
			}
			++i;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	cout << sol.intToRoman(212) << endl;
	return 0;
}
