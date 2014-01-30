#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows <= 1) return s;
		int zigsize = 2 * nRows - 2;
		string ans;
		for (int i = 0; i < nRows; ++i)
		{
			for (int j = i; j < s.size(); j += zigsize)
			{
				ans.append(1, s[j]);
				if (i>0 && i < nRows - 1)
				{
					int tmp = j + zigsize - 2 * i;
					if (tmp<s.size())
						ans.append(1, s[tmp]);
				}
			}
		}
		return ans;
	}
};

int main(){
	Solution sln;
	cout << sln.convert("PAYPALISHIRING", 3)<<endl;
	return 0;
}
