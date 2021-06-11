#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//复制带随机指针的链表；
 typedef struct Node {
	 int val;
	 struct Node *next;
	 struct Node *random;
 }Node;
 typedef Node ListNode;
 struct Node* copyRandomList(struct Node* head)
 {
	 if (head == NULL)
		 return NULL;
	 //把新结点插在原链表的对应结点之后，并断开原链表的链接
	 Node* cur = head;
	 while (cur)
	 {
		 Node* next = cur->next;
		 Node*copy = (Node*)malloc(sizeof(Node));
		 copy->val = cur->val;
		 cur->next = copy;
		 copy->next = next;
		 cur = next;
	 }
	 //复制random
	 cur = head;
	 
	 while (cur)
	 {
		 Node *copy = cur->next;
		 if (cur->random == NULL)
		 {
			 copy->random = NULL;
		 }
		 else
		 {
			 copy->random = cur->random->next;
		 }
		 cur = copy->next;
	 }
	 //提取子链，即复制出来的新链表
	 Node* copyhead = (Node*)malloc(sizeof(Node));
	 Node* copytail = copyhead;
	 cur = head;
	 while (cur)
	 {
		 copytail->next = cur->next;
		 cur->next = cur->next->next;
		 cur = cur->next;
		 copytail = copytail->next;
	 }
	 Node* rethead = copyhead->next;
	 copyhead == NULL;
	 free(copyhead); 
	 copyhead = NULL;
	 return rethead;
 }

 //mian

 //int main()
 //{
 //	ListNode* a1 = (ListNode*)malloc(sizeof(ListNode));
 //	
 //	ListNode* a2 = (ListNode*)malloc(sizeof(ListNode));
 //	a1->next = a2;
	//a1->random = a2;
 //	ListNode* a3 = (ListNode*)malloc(sizeof(ListNode));
 //	a2->next = a3;
	//a2->random = a3;
 //	ListNode* a4 = (ListNode*)malloc(sizeof(ListNode));
 //	a3->next = a4;
	//a3->random = a4;
 //	ListNode* a5 = (ListNode*)malloc(sizeof(ListNode));
 //	a4->next = a5;
	//a4->random = a5;
 //	ListNode* a6 = (ListNode*)malloc(sizeof(ListNode));
 //	a5->next = a6;
	//a5->random = a6;
 //	ListNode* a7 = (ListNode*)malloc(sizeof(ListNode));
	//a6->next = a7;
	//a6->random = a7;
 //	a7->next = NULL;
	//a7->random = NULL;
 //
 //
 //	ListNode* b1 = (ListNode*)malloc(sizeof(ListNode));
 //
 //	ListNode* b2 = (ListNode*)malloc(sizeof(ListNode));
 //	b1->next = b2;
 //	ListNode* b3 = (ListNode*)malloc(sizeof(ListNode));
 //	b2->next = a4;
	//copyRandomList(a1);
	//
 //}
