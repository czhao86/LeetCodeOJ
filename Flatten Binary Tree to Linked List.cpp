#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
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
	void flatten(TreeNode *root) {
		if (root == NULL) return;
		TreeNode *cur=root, *p, *q;
		stack<TreeNode *> st;
		while (!st.empty() || cur)
		{
			if (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			else if (!st.empty())
			{
				p = q = st.top();
				st.pop();
				while (!q->right && !st.empty())
				{
					q = st.top();
					st.pop();
				}
				if (q->right)
				{
					p->left = q->right;
					cur = p->left;
				}
			}
		}
		p = root, q = root->left;
		while (q)
		{
			p->right = q;
			p->left = NULL;
			q = q->left;
			p = p->right;
		}
	}
};

int main(){
	Solution sol;
	return 0;
}
