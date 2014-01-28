#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	double pow(double x, int n) {
		if (n == 0) return 1;
		bool sign = n > 0 ? true : false;
		n = abs(n);
		double ans = 1.0;
		while (n > 0)
		{
			if (n & 1) ans *= x;
			x *= x;
			n >>= 1;
		}
		return sign ? ans : 1.0 / ans;
	}
};

int main()
{
	Solution sol;
	cout << sol.pow(8.88023, -3) << endl;
	return 0;
}
