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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int is = inorder.size();
		int ps = postorder.size();
		if (is == 0 || ps == 0) return NULL;
		TreeNode *root = new TreeNode(postorder[ps - 1]);
		int mid = 0;
		while (inorder[mid] != postorder[ps - 1]) mid++;
		root->left = _buildTree(inorder, 0, mid-1, postorder, 0, mid-1);
		root->right = _buildTree(inorder, mid+1, is-1, postorder, mid, ps-2);
		return root;
	}
	TreeNode *_buildTree(vector<int> &inorder, int s1, int e1, vector<int> &postorder, int s2, int e2)
	{
		if (s1 > e1 || s2 > e2) return NULL;
		TreeNode *temp = new TreeNode(postorder[e2]);
		int mid = 0;
		while (inorder[mid] != postorder[e2]) mid++;
		temp->left = _buildTree(inorder, s1, mid - 1, postorder, s2, mid - 1+s2-s1);
		temp->right = _buildTree(inorder, mid + 1, e1, postorder, mid - 1 + s2 - s1+1, e2 - 1);
		return temp;
	}
};
