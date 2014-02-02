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
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL || head->next == NULL || k == 0) return head;
		int n = 1;
		ListNode *pp = head;
		while (pp->next)
		{
			pp = pp->next;
			n++;
		}
		k = k%n;
		if (head == NULL||head->next==NULL || k==0) return head;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *qq = head;
		for (int i = k; i < n-1; ++i)
			qq = qq->next;
		ListNode *t = qq;
		qq = qq->next;
		t->next = NULL;
		ListNode *p = head;
		ListNode *q = NULL;
		swap(p, q);
		swap(p, qq);
		dummy->next = p;
		pp->next = q;
		return dummy->next;
	}
	void swap(ListNode* &p, ListNode* &q)
	{
		ListNode *tmp;
		tmp = p;
		p = q;
		q = tmp;
	}
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

int main()
{
	int a[] = { 1, 2 ,3,4,5,6,7,8};
	int n = 8;
	ListNode *head = init(a, n);
	print(head);
	Solution sol;
	ListNode *ans=sol.rotateRight(head, 3);
	print(ans);
	return 0;
}
