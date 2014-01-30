#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* init(int a[], int n)
{
	ListNode *head = new ListNode(0), *q = new ListNode(0);
	for (int i = 0; i < n; ++i)
	{
		ListNode *p = new ListNode(0);
		p->val = a[i];
		if (i == 0) { q = p; head = p; }
		q->next = p;
		q = p;
	}
	return head;
}

void print(ListNode* head)
{
	while (head)
	{
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
}

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL|| head->next==NULL) return head;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *r = dummy, *p = r->next, *q = p->next;
		while (p&&q)
		{
			if (p->val == q->val)
			{
				while (q&&p->val == q->val)
					q = q->next;
				p = q;
				r->next = p;
				if (p)
					q = p->next;
			}
			else
			{
				r = r->next;
				p = r->next;
				q = p->next;
			}
		}
		return dummy->next;
	}
};

int main()
{
	int a[] = { 1, 1};
	int n = 2;
	ListNode *head = init(a, n);
	print(head);
	Solution sol;
	ListNode *head1=sol.deleteDuplicates(head);
	print(head1);
	return 0;
}
