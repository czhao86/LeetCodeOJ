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
