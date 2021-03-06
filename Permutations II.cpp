#include <iostream>
#include <vector>
#include <map>
using namespace std;

void print(vector<vector<int>> result)
{
	vector<vector<int>>::iterator itt;
	vector<int>::iterator it;
	for (itt = result.begin(); itt != result.end(); ++itt)
	{
		for (it = (*itt).begin(); it != (*itt).end(); ++it)
		{
			cout << *it << ' ';
		}
		cout << endl;
	}
}

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int> &num) {
		vector<vector<int>> res, res1;
		vector<vector<int>>::iterator it;
		vector<int>::iterator itt;
		map<vector<int>, bool> mm;
		if (num.size() == 1)
		{
			res.push_back(num);
			return res;
		}
		int t = *num.begin();
		num.erase(num.begin());
		res1 = permuteUnique(num);
		for (it = res1.begin(); it != res1.end(); ++it)
		{
			int n = 0;
			for (itt = (*it).begin(); itt != (*it).end(); ++itt)
			{
				vector<int> it1 = *it;
				vector<int>::iterator ittt;
				ittt = it1.begin() + n;
				it1.insert(ittt, t);
				n++;
				if (mm[it1]) continue;
				mm[it1] = true;
				res.push_back(it1);
			}
			(*it).push_back(t);
			if (mm[*it]) continue;
			mm[*it] = true;
			res.push_back(*it);
		}
		return res;
	}
};

int main()
{
	vector<int> x;
	x.push_back(2);
	x.push_back(2);
	x.push_back(3);
	//x.push_back(4);
	Solution sol;
	vector<vector<int>> result = sol.permute(x);
	print(result);
	return 0;
}
