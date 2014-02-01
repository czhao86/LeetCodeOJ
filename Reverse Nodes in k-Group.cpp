#include <iostream>
#include <vector>
#include <algorithm>
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
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pbegin = dummy;
		ListNode *qbegin = head;
		ListNode *p, *q;
		int tmp;
		while (head)
		{
			tmp = 0;
			p = qbegin, q = NULL;
			while (head)
			{
				head = head->next;
				tmp++;
				if (tmp == k) break;
			}
			if (tmp < k) break;
			for (int i = 0; i < k; ++i)
			{
				swap(p, q);
				swap(p, q->next);
			}
			swap(p, q);
			pbegin->next = p;
			qbegin->next = q;
			pbegin = qbegin;
			qbegin = pbegin->next;
		}
		return dummy->next;
	}
	void swap(ListNode* &x, ListNode* &y)
	{
		ListNode *t;
		t = x;
		x = y;
		y = t;
	}
};

int main()
{
	int a[] = { 1, 2,3,4,5,6,7 };
	int n = 7;
	ListNode *head = init(a, n);
	print(head);
	Solution sol;
	ListNode *head1 = sol.reverseKGroup(head,4);
	print(head1);
	return 0;
}
