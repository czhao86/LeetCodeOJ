#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return NULL;
		ListNode *p, *q;
		p = head;
		q = head;
		while (q&&q->next)
		{
			p = p->next;
			q = q->next->next;
			if (p == q)
			{
				ListNode *f = head;
				while (f != p)
				{
					f = f->next;
					p = p->next;
				}
				return f;
			}
		}
		return NULL;
	}
};
