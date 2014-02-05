#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool Comp(const Interval &a, const Interval &b){
		return a.start<b.start;
	};
	vector<Interval> merge(vector<Interval> &intervals) {
		sort(intervals.begin(), intervals.end(), Comp);
		int n = intervals.size();
		if (n <= 1) return intervals;
		vector<Interval> ans;
		int i = 0;
		while (i < n)
		{
			while (i<n - 1 && intervals[i + 1].start>intervals[i].end)
				ans.push_back(intervals[i++]);
			int b = intervals[i].start;
			int e = intervals[i].end;
			while (i < n - 1 && intervals[i + 1].start <= e)
			{
				b = min(b, intervals[i + 1].start);
				e = max(e, intervals[i + 1].end);
				i++;
			}
			Interval tmp;
			tmp.start = b;
			tmp.end = e;
			ans.push_back(tmp);
			i++;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<Interval> res;
	Interval t1, t2, t3, t4;
	t1.start = 2;
	t1.end = 4;
	t2.start = 3;
	t2.end = 7;
	t3.start = 8;
	t3.end = 10;
	t4.start = 1;
	t4.end = 18;
	res.push_back(t1);
	res.push_back(t2);
	res.push_back(t3);
	res.push_back(t4);
	vector<Interval> ans=sol.merge(res);
	vector<Interval>::iterator it;
	for (it = ans.begin(); it != ans.end(); ++it)
	{
		cout << (*it).start << ' ' << (*it).end << endl;
	}
	return 0;
}
