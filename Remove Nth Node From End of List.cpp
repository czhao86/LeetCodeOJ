class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (head == NULL) return NULL;
		ListNode dummyhead(0);
		dummyhead.next = head;
		ListNode *p = &dummyhead, *q = &dummyhead;
		for (int i = 0; i < n; ++i)
			q = q->next;
		while (q && q->next)
		{
			p = p->next;
			q = q->next;
		}
		p->next = p->next->next;
		return dummyhead.next;
	}
};
