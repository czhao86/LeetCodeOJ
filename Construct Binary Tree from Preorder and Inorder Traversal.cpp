#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int ps = preorder.size();
		int is = inorder.size();
		if (is == 0 || ps == 0) return NULL;
		TreeNode *root = new TreeNode(preorder[0]);
		int mid = 0;
		while (inorder[mid] != preorder[0]) mid++;
		root->left = _buildTree(preorder, 1, mid, inorder, 0, mid-1);
		root->right = _buildTree(preorder, mid+1, ps-1, inorder, mid+1, is-1);
		return root;
	}
	TreeNode *_buildTree(vector<int> &preorder, int s1, int e1, vector<int> &inorder, int s2, int e2)
	{
		if (s1 > e1 || s2 > e2) return NULL;
		TreeNode *temp = new TreeNode(preorder[s1]);
		int mid = 0;
		while (inorder[mid] != preorder[s1]) mid++;
		temp->left = _buildTree(preorder, s1 + 1, mid - s2 + s1, inorder, s2, mid - 1);
		temp->right = _buildTree(preorder, mid - s2 + s1+1, e1, inorder, mid + 1, e2);
		return temp;
	}
};
