#include <iostream>
#include <stack>
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		stack<TreeNode*> s1, s2;
		vector<vector<int> > ans;
		if (root == NULL) return ans;
		int n = 1;
		s1.push(root);
		while (!s1.empty())
		{
			level(s1,s2,ans,n);
			level(s2,s1,ans,n);
		}
		return ans;
	}
	void level(stack<TreeNode*> &s1, stack<TreeNode*> &s2, vector<vector<int> > &ans, int &n)
	{
		vector<int> vi;
		while (!s1.empty())
		{
			TreeNode* test = s1.top();
			s1.pop();
			vi.push_back(test->val);
			if (n == 1)
			{
				if (test->left)
					s2.push(test->left);
				if (test->right)
					s2.push(test->right);
			}
			if (n == -1)
			{
				if (test->right)
					s2.push(test->right);
				if (test->left)
					s2.push(test->left);
			}
		}
		n *= -1;
		if (!vi.empty()) ans.push_back(vi);		
	}
};

int main()
{
	Solution sol;
	TreeNode* root = new TreeNode(1);
	TreeNode* l = new TreeNode(2);
	TreeNode* r = new TreeNode(3);
	root->left=l;
	root->right=r;
	vector<vector<int> > res = sol.zigzagLevelOrder(root);
	cout << res[0][0] << endl;
	cout << res[1][0] << endl;
	cout << res[1][1] << endl;
	return 0;
}
