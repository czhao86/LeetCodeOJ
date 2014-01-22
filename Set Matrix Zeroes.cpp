#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		queue<int> p, q;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					p.push(i);
					q.push(j);
				}
			}
		}
		while (p.size())
		{
			int r = p.front();
			int s = q.front();
			for (int i = 0; i < n; ++i)
			{
				matrix[r][i] = 0;
			}
			for (int i = 0; i < m; ++i)
			{
				matrix[i][s] = 0;
			}
			p.pop();
			q.pop();
		}
	}
};

int main()
{
	Solution sol;
	vector<vector<int> > m;
	vector<int> m1 = { 0,0,0,5 };
	vector<int> m2 = { 4,3,1,4 };
	vector<int> m3 = { 0,1,1,4 };
	vector<int> m4 = { 1,2,1,3 };
	vector<int> m5 = { 0,0,1,1 };
	m.push_back(m1);
	m.push_back(m2);
	m.push_back(m3);
	m.push_back(m4);
	m.push_back(m5);
	vector<vector<int> >::iterator it;
	vector<int>::iterator itt;
	for (it = m.begin(); it != m.end(); ++it)
	{
		for (itt = (*it).begin(); itt != (*it).end(); ++itt)
		{
			cout << *itt << ' ';
		}
		cout << endl;
	}
	cout << endl;
	sol.setZeroes(m);
	for (it = m.begin(); it != m.end(); ++it)
	{
		for (itt = (*it).begin(); itt != (*it).end(); ++itt)
		{
			cout << *itt << ' ';
		}
		cout << endl;
	}
	return 0;
}
