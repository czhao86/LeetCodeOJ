#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans;
		if (rowIndex == 0)
		{
			ans.push_back(1);
			return ans;
		}
		vector<int> t = getRow(rowIndex - 1);
		ans.push_back(1);
		for (vector<int>::iterator it = t.begin(); it != t.end()-1; ++it)
		{
			ans.push_back(*it + (*(it + 1)));
		}
		ans.push_back(1);
		return ans;
	}
};
int main()
{
	Solution sl;
	vector<int> res= sl.getRow(3);
	vector<int>::iterator it;
	for (it = res.begin(); it != res.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
