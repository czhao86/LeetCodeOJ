#include <iostream>
#include <vector>
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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > ans;
		vector<int> elem;
		findpathsum(root, sum, ans, elem);
		return ans;
	}
	void findpathsum(TreeNode *root, int sum, vector<vector<int> > &ans, vector<int> elem)
	{
		if (root == NULL) return;
		elem.push_back(root->val);
		if (!root->left && !root->right && sum == root->val)
		{
			ans.push_back(elem);
		}
		else
		{
			findpathsum(root->left, sum - root->val, ans, elem);
			findpathsum(root->right, sum - root->val, ans, elem);
		}
	}
};

int main()
{
	Solution sol;
	return 0;
}
