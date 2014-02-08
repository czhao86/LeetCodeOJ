#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<string> q1, q2;
		q1.push(start);
		int ans = 1;
		while (!q1.empty() && dict.size()>=0)
		{
			while (!q1.empty())
			{
				string word(q1.front());
				q1.pop();
				for (int i = 0; i < word.size(); ++i)
				{
					for (char c = 'a'; c <= 'z'; ++c)
					{
						if (word[i] == c) continue;
						char tmp = word[i];
						word[i] = c;
						if (word == end) return ans + 1;
						if (dict.count(word)>0)
						{
							q2.push(word);
							dict.erase(word);
						}
						word[i] = tmp;
					}
				}
			}
			swap(q1, q2);
			ans++;
		}
		return 0;
	}
};

int main()
{
	unordered_set<string> ans;
	ans.insert("hot");
	ans.insert("dot");
	ans.insert("dog");
	ans.insert("lot");
	ans.insert("log");
	Solution sol;
	cout << sol.ladderLength("hit", "cog", ans) << endl;
	return 0;
}
