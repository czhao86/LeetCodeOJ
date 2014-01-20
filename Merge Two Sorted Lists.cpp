#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		if (l1->val > l2->val)
		{
			ListNode *temp;
			temp = l1;
			l1 = l2;
			l2 = temp;
		}
		ListNode *result = l1, *p = l1;
		l1 = l1->next;
		while (l1&&l2)
		{
			if (l1->val < l2->val)
				l1 = l1->next;
			else
			{
				ListNode *q = l2;
				/*pay attention to the order of sentence below*/
				l2 = l2->next;
				p->next = q;
				q->next = l1;
			}
			p = p->next;
		}
		if (!l1) p->next = l2;
		return result;
	}
};
