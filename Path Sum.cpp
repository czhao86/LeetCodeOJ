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
	bool hasPathSum(TreeNode *root, int sum) {
		if (root == NULL) return false;
		if (sum == root->val && root->left==NULL && root->right==NULL) return true;
		else return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};

int main()
{
	Solution sol;
	return 0;
}
