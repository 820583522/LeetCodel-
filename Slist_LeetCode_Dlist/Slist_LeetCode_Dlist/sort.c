#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
	
};


struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* sorthead = head, *cur = head->next;
	sorthead->next = NULL;//¶Ï¿ªÁ´±í
	while (cur)
	{
		struct ListNode* next = cur->next;
		struct ListNode* p = NULL, *c = sorthead;
		while (c)
		{
			if (c->val > cur->val)
			{
				if (p == NULL)
				{
					sorthead = cur;
					cur->next = c;
				}
				else
				{
					p->next = cur;
					cur->next = c;
				}
				break;
			}
			else
			{
				p = c;
				c = c->next;
			}
		}
		if (c == NULL)
		{
			p->next = cur;
			cur->next = NULL;
		}
		cur = next;
	}
	return sorthead;
}