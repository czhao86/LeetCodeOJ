#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
};

ListNode* init(int a[], int n)
{
	ListNode *head = new ListNode(), *q = new ListNode();
	for (int i = 0; i < n; ++i)
	{
		ListNode *p = new ListNode();
		p->val = a[i];
		if (i == 0) { q = p; head = p; }
		q->next = p;
		q = p;
	}
	return head;
}

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if (!head || !head->next) return head;
		ListNode *he=head, *res;
		res = he->next;
		he->next=res->next;
		res->next = he;
		ListNode *t = res->next;
		while (t->next)
		{
			if (t->next && t->next->next)
			{

				ListNode *hee=t->next, *ress=t->next->next;
				hee->next=ress->next;
				ress->next = hee;
				t->next = ress;
				t = t->next->next;
			}
			if (t->next && !t->next->next)
			{
				break;
			}
		}
		return res;
	}
};

void print(ListNode* head)
{
	while (head)
	{
		cout << head->val << ' ';
		head = head->next;
	}
}

int main()
{
	int a[] = {11,22,33,44};
	int n = 4;
	ListNode *head = init(a, n);
	print(head);
	Solution sol;
	print(sol.swapPairs(head));
	cout << endl;
	return 0;
}
