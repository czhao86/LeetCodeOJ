#include <iostream>
#include <string>
using namespace std;

class Solution1 {
public:
	int reverse(int x) {
		int sign = (x < 0 ? -1 : 1);
		char xx[32];
		itoa(sign*x,xx,10);
		int i = 0;
		while (xx[i]) i++;
		cout << i << endl;
		for (int j = 0; j < i/2; ++j)
		{
			swap(xx[j], xx[i-j-1]);
		}		
		return sign*atoi(xx);
	}
};

class Solution {
public:
	int reverse(int x) {
		int sign = (x < 0 ? -1 : 1);
		int rev = 0;
		while (x)
		{
			rev = rev * 10 + x % 10;
			x /= 10;
		}
		return rev;
	}
};

int main()
{
	Solution sol;
	cout << sol.reverse(-1230000) << endl;
	return 0;
}
