#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		vector<int> t1;
		if (numRows == 0) return res;
		t1.push_back(1);
		res.push_back(t1);
		for (int i = 1; i < numRows; ++i)
		{
			vector<int> t;
			t.push_back(1);
			for (vector<int>::iterator it = t1.begin(); it != t1.end()-1; ++it)
			{			
				t.push_back(*it + *(it + 1));
			}
			t.push_back(1);
			res.push_back(t);
			t1 = t;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> result=sol.generate(4);
	vector<int> x = result.back();
	for (vector<int>::iterator it = x.begin(); it != x.end(); ++it)
	{
		cout << *it << endl;		
	}
	return 0;
}
