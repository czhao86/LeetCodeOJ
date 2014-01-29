class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ans;
		if (matrix.empty()) return ans;
		int m = matrix.size();
		int n = matrix[0].size();
		int start = 0, end = n - 1, endd = m - 1;
		while (start < end && start<endd)
		{
			for (int i = start; i < end; ++i)
				ans.push_back(matrix[start][i]);
			for (int j = start; j < endd; ++j)
				ans.push_back(matrix[j][end]);
			for (int k = end; k>start; --k)
				ans.push_back(matrix[endd][k]);
			for (int l = endd; l>start; --l)
				ans.push_back(matrix[l][start]);
			start++;
			end--;
			endd--;
		}
		if (start == end)
		{
			for (int i = start; i < endd+1; ++i)
				ans.push_back(matrix[i][start]);
			return ans;
		}
		if (start == endd)
		{
			for (int i = start; i < end+1; ++i)
				ans.push_back(matrix[start][i]);
		}
		return ans;
	}
};
