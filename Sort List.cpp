#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *fast = head, *slow = head;
		while (fast->next&&fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		fast=slow->next;
		slow->next = NULL;
		ListNode *l=sortList(head);
		ListNode *r=sortList(fast);
		return mergeList(l, r);
	}
	ListNode *mergeList(ListNode *l, ListNode *r)
	{
		if (l == NULL) return r;
		if (r == NULL) return l;
		ListNode *ans;
		if (l->val > r->val)
		{
			ans = r;
			r = r->next;
		}
		else
		{
			ans = l;
			l = l->next;
		}
		ListNode *tmp = ans;
		while (l&&r)
		{
			if (l->val > r->val)
			{
				tmp->next = r;
				r = r->next;
			}
			else
			{
				tmp->next = l;
				l = l->next;
			}
			tmp = tmp->next;
		}
		if (l) tmp->next = l;
		if (r) tmp->next = r;
		return ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
