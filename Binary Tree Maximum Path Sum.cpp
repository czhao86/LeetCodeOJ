#include <iostream>
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
	int maxPathSum(TreeNode *root) {
		int csum, maxsum=INT_MIN;
		_maxPathSum(root, csum, maxsum);
		return maxsum;
	}
	void _maxPathSum(TreeNode* root, int &csum, int &maxsum)
	{
		if (root == NULL)
		{
			csum = 0;
			return;
		}
		int lsum = 0, rsum = 0;
		_maxPathSum(root->left, lsum, maxsum);
		_maxPathSum(root->right, rsum, maxsum);
		csum = max(root->val, max(root->val + lsum, root->val + rsum));
		maxsum = max(maxsum, max(csum,root->val+lsum+rsum));
	}
};

int main()
{
	Solution sol;
	return 0;
}
