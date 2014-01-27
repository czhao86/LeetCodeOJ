class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		sort(num.begin(), num.end());
		int n = num.size();
		int first = num[0];
		int count = 1, max = 0;
		for (int i = 1; i < n; ++i)
		{
			if (num[i] == first + 1)
			{
				count++;
				cout << count << endl;
				first++;
				if (count>max) max = count;
			}
			else
			{
				first = num[i];
				count = 1;
			}
		}
		return max;
	}
};

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		map<int, bool> tmp;
		int n = num.size();
		int count, max = 0;
		for (int i = 0; i < n; ++i)
		{
			tmp[num[i]] = true;
		}
		for (int j = 0; j < n; ++j)
		{
			count = 1;
			int x = num[j], y=num[j];
			tmp.erase(x);
			while (tmp.find(x + 1) != tmp.end())
			{
				count++;
				tmp.erase(x + 1);
				x++;
			}
			while (tmp.find(y - 1) != tmp.end())
			{
				count++;
				tmp.erase(y - 1);
				y--;
			}
			if (count > max) max = count;
		}
		return max;
	}
};

int main()
{
	Solution sol;

	cout<<sol.longestConsecutive(a)<<endl;
}
