#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *p = head;
		if (head == NULL) return p;
		while (p)
		{
			RandomListNode *tmp = new RandomListNode(p->label);
			tmp->next = p->next;
			p->next = tmp;
			p = p->next->next;
		}
		RandomListNode *q = head;
		while (q)
		{
			if (q->random)
				q->next->random = q->random->next;
			else q->next->random = NULL;
			q = q->next->next;
		}
		RandomListNode *r = head->next;
		RandomListNode *ans = head->next;
		RandomListNode *h = head;
		while (h->next&&h->next->next)
		{
			h->next = h->next->next;
			h = h->next;
			r->next = r->next->next;
			r = r->next;
		}
		h->next = NULL;
		r->next = NULL;
		return ans;
	}
};

RandomListNode* init(int a[], int n)
{
	RandomListNode *head = new RandomListNode(0), *q = new RandomListNode(0);
	for (int i = 0; i < n; ++i)
	{
		RandomListNode *p = new RandomListNode(0);
		p->label = a[i];
		if (i == 0) { q = p; head = p; }
		q->next = p;
		q = p;
	}
	return head;
}

void print(RandomListNode* head)
{
	while (head)
	{
		cout << head->label << ' ';
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int a[] = { 1, 2 };
	int n = 2;
	//RandomListNode *head = init(a, n);
	RandomListNode *tmp1 = new RandomListNode(-1);
	tmp1->random = NULL;
	RandomListNode *tmp2 = new RandomListNode(1);
	tmp1->next = tmp2;
	tmp2->random = NULL;
	print(tmp1);
	Solution sol;
	RandomListNode *head1=sol.copyRandomList(tmp1);
	print(head1);
	return 0;
}
