#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		TreeNode *root;
		int n = 0;
		ListNode *p=head;
		for (; p; p = p->next) n++;
		return ltb(head, n);
	}
	TreeNode* ltb(ListNode *head, int n)
	{
		if (head == NULL || n == 0) return NULL;
		ListNode *temp = head;
		for (int i = 0; i < n / 2; ++i)
		{
			temp = temp->next;
		}
		TreeNode *root = new TreeNode(temp->val);
		root->left = ltb(head, n / 2);
		root->right = ltb(temp->next, n - n / 2 - 1);
		return root;
	}
};
