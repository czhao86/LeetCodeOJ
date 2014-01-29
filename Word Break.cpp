#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> wb(s.length()+1,false);
		wb[0] = true;
		for (int i = 1; i < s.length()+1; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (wb[j] && dict.find(s.substr(j, i - j)) != dict.end())
				{
					wb[i] = true;
					break;
				}
			}
		}
		return wb[s.length()];
	}
};

int main()
{
	Solution sol;
	return 0;
}
