#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		if (n == 0)
		{
			res.push_back(0);
			return res;
		}
		if (n == 1)
		{
			res.push_back(0);
			res.push_back(1);
			return res;
		}
		vector<int> test;
		vector<int> ans;
		test = grayCode(n - 1);
		vector<int>::iterator it;
		for (it = test.begin(); it != test.end(); ++it)
		{
			ans.push_back(*it);
		}
		for (it = test.end()-1; it > test.begin(); --it)
		{
			int x = (1 << (n-1)) | *it;
			ans.push_back(x);
		}
		it = test.begin();
		int x = (1 << (n - 1)) | *it;
		ans.push_back(x);
		return ans;
	}
};

int main()
{
	Solution sl;
	vector<int> t;
	t=sl.grayCode(3);
	vector<int>::iterator it;
	for (it = t.begin(); it != t.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
