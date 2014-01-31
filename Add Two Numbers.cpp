#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *ans = new ListNode(-1);
		ListNode *p = ans;
		int c = 0;
		while (l1&&l2)
		{
			int num = l1->val + l2->val + c;
			c = num / 10;
			ListNode *tmp = new ListNode(num % 10);
			p->next = tmp;
			p = tmp;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1)
		{
			int num = l1->val + c;
			c = num / 10;
			ListNode *tmp = new ListNode(num % 10);
			p->next = tmp;
			p = tmp;
			l1 = l1->next;
		}
		while (l2)
		{
			int num = l2->val + c;
			c = num / 10;
			ListNode *tmp = new ListNode(num % 10);
			p->next = tmp;
			p = tmp;
			l2 = l2->next;
		}
		if (c)
		{
			ListNode *tmp = new ListNode(1);
			p->next = tmp;
			tmp->next = NULL;
		}
		return ans->next;
	}
};
