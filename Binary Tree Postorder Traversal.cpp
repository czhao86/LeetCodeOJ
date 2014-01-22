#include <iostream>
#include <vector>
#include <queue>
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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		postorder(res, root);
		return res;
	}
	void postorder(vector<int> &res, TreeNode *root)
	{
		if (root == NULL) return;
		postorder(res, root->left);
		postorder(res, root->right);
		res.push_back(root->val);
	}
};

int main()
{
	Solution sol;
	return 0;
}
