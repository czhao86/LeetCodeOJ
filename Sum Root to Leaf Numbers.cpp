#include <iostream>
#include <vector>
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
	int sumNumbers(TreeNode *root) {
		int num = 0, sum = 0;
		sum1(root, num, sum);
		return sum;
	}
	void sum1(TreeNode *root, int num, int &sum)
	{
		if (root == NULL) return;
		num = num * 10 + root->val;
		if (!root->left && !root->right) sum += num;
		else
		{
			sum1(root->left, num, sum);
			sum1(root->right, num, sum);
		}
	}
};

int main()
{
	return 0;
}
