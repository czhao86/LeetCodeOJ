#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ans;
		Interval tmp;
		int n = intervals.size();
		int i = 0;
		while (i<n && intervals[i].end < newInterval.start)
			ans.push_back(intervals[i++]);
		while (i < n && intervals[i].start<=newInterval.end)
		{
			newInterval.start = min(intervals[i].start, newInterval.start);
			newInterval.end = max(intervals[i].end, newInterval.end);
			i++;
		}
		ans.push_back(newInterval);
		while (i < n)
		{
			ans.push_back(intervals[i++]);
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
