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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		preorderTraversal1(root, result);
		return result;
	}

	void preorderTraversal1(TreeNode *root, vector<int> &result)
	{
		if (root == NULL) return;
		result.push_back(root->val);
		preorderTraversal1(root->left, result);
		preorderTraversal1(root->right, result);
	}
};
