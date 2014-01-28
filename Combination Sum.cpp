class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > ans;
		vector<int> tmp;
		sort(candidates.begin(), candidates.end());
		_combinationSum(ans, tmp, candidates, 0, target);
		return ans;
	}
	void _combinationSum(vector<vector<int> > &ans, vector<int> &tmp, vector<int> &candidates, int start, int target)
	{
		if (target == 0)
		{
			ans.push_back(tmp);
			return;
		}
		for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i)
		{
			tmp.push_back(candidates[i]);
			_combinationSum(ans, tmp, candidates, i, target - candidates[i]);
			tmp.pop_back();
		}
	}
};
