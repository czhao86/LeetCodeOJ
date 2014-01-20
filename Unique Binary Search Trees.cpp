#include <iostream>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		int result=0;
		if (n == 0 || n==1) return 1;
		for (int i = 0; i < n; ++i)
		{
			result += numTrees(i)*numTrees(n - i-1);
		}
		return result;
	}
};

int main()
{
	int n=3;
	Solution sl;
	cout<<sl.numTrees(n)<<endl;
	return 0;
}
