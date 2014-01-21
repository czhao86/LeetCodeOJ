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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		TreeNode *root = NULL;
		sorted(root, num, 0, num.size() - 1);
		return root;
	}
	void sorted(TreeNode* &root, vector<int> &num, int start, int end)
	{
		if (start <= end)
		{
			int mid = start + (end - start) / 2;
			root = new TreeNode(num[mid]);
			sorted(root->left, num, start, mid - 1);
			sorted(root->right, num, mid + 1, end);
		}
	}
};

int main()
{
	Solution sol;
	int a[11] = { 10,20,30 };
	int b[8] = { 2,5,6,11,12,13,16,19 };
	sol.merge(a, 3, b, 7);

	return 0;
}
