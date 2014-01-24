#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x == 0) return true;
		int y = 0;
		int z = x;
		while (x != 0)
		{
			y = y * 10 + x % 10;
			x /= 10;
		}
		if (z == y) return true;
		else return false;
	}
};

int main()
{
	return 0;
}
