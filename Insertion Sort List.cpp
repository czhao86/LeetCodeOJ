#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *p = dummy->next, *q;
		while (p&&p->next)
		{
			if (p->val <= p->next->val)
			{
				p = p->next;
				continue;
			}
			else
			{
				ListNode *tmp = dummy;
				q = p->next;
				p->next = q->next;
				while (q->val>tmp->next->val) tmp = tmp->next;
				q->next = tmp->next;
				tmp->next = q;
			}
		}
		return dummy->next;
	}
};

int main()
{
	return 0;
}
