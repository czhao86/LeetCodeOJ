#include <iostream>
#include <vector>
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
	void recoverTree(TreeNode *root) {
		vector<TreeNode*> tmp;
		vector<int> n;
		inordertransverse(root, tmp, n);
		sort(n.begin(), n.end());
		for (int i = 0; i < tmp.size(); ++i)
			tmp[i]->val = n[i];
	}
	void inordertransverse(TreeNode *root, vector<TreeNode*> &tmp, vector<int> &n)
	{
		if (root == NULL) return;
		inordertransverse(root->left, tmp, n);
		n.push_back(root->val);
		tmp.push_back(root);
		inordertransverse(root->right, tmp, n);
	}
};

int main()
{
	TreeNode *p = new TreeNode(0);
	TreeNode *q = new TreeNode(1);
	p->left = q;
	Solution sol;
	sol.recoverTree(p);
	cout << q->val << ' ' << p->val << endl;
}
