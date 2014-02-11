#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		int n = T.length();
		map<char, int> tmp, fort;
		for (int i = 0; i < n; ++i)
			fort[T[i]]++;	
		int i, j = 0, num = 0, minn = 1 << 29, start = 0, end = n - 1;
		for (i = 0; i < S.length(); ++i)
		{
			if (num < n)
			{
				if (tmp[S[i]] < fort[S[i]]) num++;
				tmp[S[i]]++;
			}
			if (num == n)
			{
				while (j <= i && tmp[S[j]]>fort[S[j]])
				{
					tmp[S[j]]--;
					j++;
				}
				if (minn > i - j + 1)
				{
					minn = i - j + 1;
					end = i;
					start = j;
				}
				while (j <= i && num == n)
				{
					tmp[S[j]]--;
					if (tmp[S[j]] < fort[S[j]]) num--;
					j++;
				}
			}
		}
		if (minn<1<<29) return S.substr(start, minn);
		else return "";
	}
};

int main()
{
	string a = "onlswwtraopuasovmrmdouldsqiryidoxpgtlcmnschswxpirbmfxzkqpsjncnebekupoheglmyhlqsctgirfsjunskrfotj", b = "apapyfvjtwtemnhf";
	Solution sol;
	cout << sol.minWindow(a, b) << endl;
	return 0;
}
