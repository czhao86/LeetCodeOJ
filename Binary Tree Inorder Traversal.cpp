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
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		inorderTraversal1(root, result);
		return result;
	}

	void inorderTraversal1(TreeNode *root, vector<int> &result)
	{
		if (root == NULL) return;
		inorderTraversal1(root->left, result);
		result.push_back(root->val);
		inorderTraversal1(root->right, result);
	}
};
