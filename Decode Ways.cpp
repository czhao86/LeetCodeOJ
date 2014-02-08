#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int n = s.length();
		if (n == 0 || s[0] == '0') return 0;
		vector<int> d(n + 1, 0);
		d[0] = d[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			if (s[i - 1] != '0') d[i] += d[i - 1];
			if (s[i - 2] == '1' || (s[i - 2] == '2'&&s[i - 1] <= '6')) d[i] += d[i - 2];
		}
		return d[n];
	}
};

int main(){
	Solution sln;
	string s = "130";
	cout << sln.numDecodings(s);
	return 0;
}
