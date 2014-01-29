#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Definition for singly-linked list.
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
	ListNode *partition(ListNode *head, int x) {
		ListNode *p = new ListNode(-1);
		ListNode *q = new ListNode(x);
		ListNode *pp = p, *qq = q;
		while (head!=NULL)
		{
			ListNode *next = head->next;
			int n = head->val;
			if (n < x)
			{
				pp->next = head;
				pp = head;
			}
			else
			{
				qq->next = head;
				qq = head;
				qq->next = NULL;
			}
			head = next;
		}
		pp->next = q->next;
		return p->next;
	}
};

int main()
{
	int a[] = { 1,2,3 };
	int n = 3;
	ListNode *head = init(a, n);
	Solution sol;
	ListNode *ans = sol.partition(head, 2);
	print(ans);
}
