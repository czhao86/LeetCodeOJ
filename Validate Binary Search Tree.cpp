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
	bool isValidBST(TreeNode *root) {
		if (root == NULL) return true;
		if (!root->left && !root->right) return true;
		TreeNode* prev = root->left;
		TreeNode* next = root->right;
		if (prev)
		{
			while (prev->right) prev = prev->right;
		}
		if (next)
		{
			while (next->left) next = next->left;
		}
		if (root->left && !root->right) return prev->val < root->val && isValidBST(root->left);
		if (!root->left && root->right) return next->val>root->val && isValidBST(root->right);
		if (root->left && root->right)
			return prev->val < root->val && next->val>root->val && isValidBST(root->left) && isValidBST(root->right);
	}
};

int main()
{
}
