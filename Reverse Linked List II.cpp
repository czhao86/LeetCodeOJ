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
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pbegin=dummy, *qbegin;
		for (int i = 0; i < m-1; ++i) pbegin = pbegin->next;
		qbegin = pbegin->next;
		ListNode *p = qbegin, *q = NULL;
		for (int j = 0; j < n - m+1; ++j)
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
	return 0;
}
