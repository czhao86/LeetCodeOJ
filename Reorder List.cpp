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
	void reorderList(ListNode *head) {
		if (head == NULL || head->next == NULL) return;
		ListNode *s = head;
		ListNode *f = head;
		ListNode *ans = head;
		while (f->next&&f->next->next)
		{
			s = s->next;
			f = f->next->next;
		}
		ListNode *tmp = s->next;
		ListNode *temp = s->next;
		s->next = NULL;
		int i = 0;
		while (tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		ListNode* r = reverseBetween(temp, 0, i);
		while (ans)
		{
			ListNode *con = r->next;
			r->next = ans->next;
			ans->next = r;
			r = con;
			ans = ans->next->next;
			if (ans != NULL && r == NULL) break;
		}
	}
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pbegin = dummy, *qbegin;
		for (int i = 0; i < m - 1; ++i) pbegin = pbegin->next;
		qbegin = pbegin->next;
		ListNode *p = qbegin, *q = NULL;
		for (int j = 0; j < n - m + 1; ++j)
		{
			swap(p, q);
			swap(p, q->next);
		}
		swap(p, q);
		pbegin->next = p;
		qbegin->next = q;
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
	int a[] = { 1, 2, 3};
	int n = 3;
	ListNode *head = init(a, n);
	Solution sol;
	print(head);
	sol.reorderList(head);
	print(head);
}
