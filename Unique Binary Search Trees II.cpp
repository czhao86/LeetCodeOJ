#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode *> ans;
		ans = _generateTrees(1, n);
		return ans;
	}
	vector<TreeNode *> _generateTrees(int start, int end)
	{
		vector<TreeNode *> ans;
		TreeNode* temp;
		if (start > end)
		{
			ans.push_back(NULL);
			return ans;
		}
		else
		{
			for (int i = start; i <= end; ++i)
			{
				vector<TreeNode *> l = _generateTrees(start, i - 1);
				vector<TreeNode *> r = _generateTrees(i+1, end);
				for (int ii = 0; ii < l.size(); ++ii)
				{
					for (int j = 0; j < r.size(); ++j)
					{
						TreeNode* temp = new TreeNode(i);
						temp->left = l[ii];
						temp->right = r[j];
						ans.push_back(temp);
					}
				}
			}
		}
		return ans;
	}
};

int main(){
	Solution sol;
	return 0;
}
