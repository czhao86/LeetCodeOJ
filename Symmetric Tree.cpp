#include <iostream>
#include <map>
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
	bool isSymmetric(TreeNode *root) {
		if (root == NULL) return true;
		return helper(root->left, root->right);
	}
	bool helper(TreeNode *left, TreeNode *right)
	{
		if (left == NULL && right == NULL) return true;
		if (left == NULL || right == NULL) return false;
		if (left->val != right->val) return false;
		return helper(left->left, right->right) && helper(left->right, right->left);
	}
};

int main()
{
	Solution sol;

	return 0;
}
