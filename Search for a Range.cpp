#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ans;
		ans.push_back(-1);
		ans.push_back(-1);
		search(A, n, 0, n - 1, target, ans);
		return ans;
	}

	void search(int A[], int n, int start, int end, int target, vector<int> &ans)
	{
		if (start<=end)
		{
			int mid = start + (end - start) / 2;
			if (A[mid] == target)
			{
				int l = mid, r = mid;
				while (l>=start)
				{
					if (A[l] != target) break;
					else l--;
				}
				l++;
				while (r<=end)
				{
					if (A[r] != target) break;
					else r++;
				}
				r--;
				ans.pop_back();
				ans.pop_back();
				ans.push_back(l);
				ans.push_back(r);
				return;
			}
			else if (A[mid] > target)
			{
				search(A, n, start, mid - 1, target, ans);
			}
			else if (A[mid] < target)
			{
				search(A, n, mid + 1, end, target, ans);
			}
		}
		else return;
	}
};

int main()
{
	Solution sol;
	vector<int> res;
	int a[12] = { 1, 1, 2, 3, 4, 5, 5, 5, 5, 5, 6, 7 };
	res=sol.searchRange(a, 12, 5);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << ' ';
	cout << endl;
	return 0;
}
