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
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		if (root == NULL) return ans;
		queue<TreeNode*> p, q;
		p.push(root);
		while (!p.empty())
		{
			level(p, q, ans);
			level(q, p, ans);
		}
		return ans;
	}
	void level(queue<TreeNode*> &p, queue<TreeNode*> &q, vector<vector<int> > &ans)
	{
		vector<int> vi;
		while (!p.empty())
		{
			TreeNode* tmp = p.front();
			p.pop();
			vi.push_back(tmp->val);
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
		}
		if (!vi.empty()) ans.push_back(vi);
	}
};
