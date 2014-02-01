#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		int n = s.length();
		vector<vector<vector<string>>> ans;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				bool palin = true;
				int x = j, y = i;
				while (x<=y)
				{
					if (s[x] != s[y])
					{
						palin = false;
						break;
					}
					else
					{
						x++;
						y--;
					}
				}
				if (palin)
				{
					string temp = s.substr(j, i - j + 1);
					if (j == 0)
					{
						vector<string> vs;
						vs.push_back(temp);
						ans[i].push_back(vs);
					}
					else
					{
						vector<vector<string>> m = ans[j - 1];;
						for (int j = 0; j < m.size(); ++j)
						{
							vector<string> tmp = m[j];
							m[j].push_back(temp);
							ans[i].push_back(m[j]);
						}

					}
				}

			}
		}
		return ans[n - 1];
	}
};

int main()
{
	return 0;
}
