#include <iostream>
using namespace std;

//Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root==NULL) return;
		if (root->left)
			root->left->next = root->right;
		if (root->right && root->next)
			root->right->next = root->next->left;
		if (root->left) connect(root->left);
		if (root->right) connect(root->right);
	}
};
