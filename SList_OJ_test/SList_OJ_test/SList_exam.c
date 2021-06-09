#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>


//1. ԭ���Ƴ����������е�Ԫ��val��Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)��
//��num[a]===valʱ����ֵnum[des]=num[src];���ֻ����des���Ǹ�����
int removeElement(int* nums, int numsSize, int vul)
{
	int src = 0;
	int des = 0;
	while (src < numsSize)
	{
		if (nums[src] != vul)
		{
			nums[des] = nums[src];
			des++;
			src++;
		}
		else
		{
			src++;
		}
	}
	return des;
}


//2. ɾ�����������е��ظ��OJ����
//˫ָ��ⷨ��һǰһ�����������У���ͬԪ�ر����ڣ������Ƚϣ�����ͬ��������ǰһ��ֵ��
int removeDuplicates(int* nums, int numsSize)
{
	int des = 0;
	int cur = 1;
	int prev = 0;
	if (numsSize <= 0)
	{
		return 0;
	}
	while (cur<numsSize)
	{
		if (nums[cur] == nums[prev])
		{
			cur++;
			prev++;
		}
		else
		{
			nums[des] = nums[prev];
			des++;
			prev++;
			cur++;
		}
	}
	nums[des] = nums[prev];
	return ++des;
}



//4. ��ת���顣Oj����
//12345����������
//1.��12345�ȷ�תΪ54321��
//2.�ٷָ��ߴ��ֱ�����߽��з�ת���͵õ�45123��
void rotate(int* nums, int numsSize, int k)
{
	if (numsSize <= 1)
		return;
	k %= numsSize;
	int left = 0; 
	int right = numsSize - 1;
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
	left = 0;
	right = k - 1;
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
	left = k;
	right = numsSize - 1;
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		left++;
		right--;
	}
	return;
}


//5. ������ʽ�������ӷ���OJ����
int* addToArrayForm(int* num, int numSize, int k,int* returnSize)
{
	int klen=0;
	int fk = k;
	while (k)
	{
		k /= 10;
		klen++;
	}
	int len = (klen > numSize ? klen:numSize);
	int* retArrey = (int*)malloc(sizeof(int)*(len + 1));
	int prev = 0;
	int sum = 0;
	for (int i = 0; i <= len; i++)
	{
		if (numSize - i-1 < 0)
		{
			 sum = fk % 10 + prev;
		}
		else
		{
			 sum = fk % 10 + num[numSize - i-1] + prev;
		}
		if (sum >= 10)
		{
			retArrey[len-i] = sum % 10;
			prev = 1;
		}
		else
		{
			retArrey[len-i] = sum;
			prev = 0;
		}
		fk /= 10;
	}
	if (prev)
	{
		*returnSize = len+1;
		return retArrey;
	}
	else
	{
		*returnSize = len;
		return retArrey + 4;
	}

}


//��ת��������
//��ָ�뷨��ǰ��������ͷ�壬������ָ��������¼��һ�����ĵ�ַ��һ����ǰ��
 typedef struct ListNode
{
	int date;
	struct ListNode* next;
}ListNode;
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* n1 = NULL;
	struct ListNode* n2 = head;
	struct ListNode* n3 = head->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}

//203.ȥ��������ĳ��ֵ����
//˫ָ�뷨���ؼ����ڷ�����һ��ֵ����Ҫɾ��ֵ����������׺��Ե�
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		if (cur->date == val)
		{
			if (cur == head)
			{
				head = cur->next;
				cur = head;
			}
			else
			{
				prev->next = cur->next;
				cur = cur->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}




////��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
////���ҵ�һ����ͷ��Ȼ��β��
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tail = head;
	while (l1&&l2)
	{
		if (l1->date < l2->date)
		{
			tail->next = l1;
			tail=l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			tail = l2;
			l2 = l2->next;
		}
	}
	while (l1)
	{
		tail->next = l1;
		tail = l1;
		l1 = l1->next;
	}
	while (l2)
	{
		tail->next = l2;
		tail = l2;
		l2 = l2->next;
	}
	struct ListNode* realhead = head->next;
	free(head);
	return realhead;
}


//�ϲ������������飬
//�Ȱ���������Ž�һ�������У���ð������
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	for (int i = 0; i<n; i++)
	{
		nums1[m + i] = nums2[i];
	}
	for (int i = 0; i<m + n - 1; i++)
	{
		for (int k = 0; k<m + n - 1 - i; k++)
		{
			if (nums1[k]>nums1[k + 1])
			{
				int tmp = nums1[k];
				nums1[k] = nums1[k + 1];
				nums1[k + 1] = tmp;
			}
		}
	}
	return;
}


//6. ��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ ��OJ����
//˼·����ԭ����ֳ���������������һ��
//����1.��������������ı�ͷ
//2.����ԭ�������࣬β�嵽����ͷ֮һ�ĺ�ߡ�
//3.��ֵ�������ӵ�ֵС�������β��
//ע�⣬�п������һ��ֵ��Ľ��ָ������һ��С�Ľ�㣻�����Ҫ�ֶ������óɿգ�
ListNode* partition(ListNode* pHead, int x) 
{
	ListNode* lesshead = (ListNode*)malloc(sizeof(ListNode));
	ListNode* greathead = (ListNode*)malloc(sizeof(ListNode));
	ListNode* lesstail = lesshead;
	ListNode* greattail = greathead;
	ListNode* cur = pHead;
	while (cur)
	{
		if (cur->date < x)
		{
			lesstail->next = cur;
			lesstail = lesstail->next;
			cur=cur->next;
		}
		else
		{
			greattail->next = cur;
			greattail = greattail->next;
			cur = cur->next;
		}
	}
	
	greattail->next = NULL;//�ǳ�ϸ�ڵ�һ���㣬���greattail��next����ָ��������һ��С�ģ������ѭ����



	lesstail->next = greathead->next;
	ListNode* HEAD = lesshead->next;
	free(lesshead);
	free(greathead);
	return HEAD;
}



//���������֣�ǡ������ֻ���ֹ�һ�ε����֣��������ֶ��������Ρ�
//��ҪҪ��Ϥ���^�Ͱ�λ��&���÷�;
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
	//ȫ�����ret���Ľ������x1��x2�������Ľ��
	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	//�ҳ�ret��Ϊ0�ĵ�mλ
	int m = 0;
	while (m < 31)
	{
		if (ret&(1 << m))
		{
			m++;
			break;
		}
		m++;
	}
	//����ԭ���飬mλΪ0Ϊһ�飬mλΪ1��Ϊһ��
	//���뷽����
	// a&(1<<(m-1)),��ֵΪ1��˵��a�ĵ�mλ��1��ֵΪ0��˵��a�ĵ�mλ��0��
	int x1 = 0;
	int x2 = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] & (1 << (m - 1)))
		{
			x1 ^= nums[i];
		}
		else
		{
			x2 ^= nums[i];
		}
	}
	int* retArr = (int*)malloc(sizeof(int)* 2);
	retArr[0] = x1;
	retArr[1] = x2;
	*returnSize = 2;
	return retArr;
}

//����Ļ��Ľṹ
//1.����ָ�����ҵ��м���
//2.��ת��������
//3.��ǰ���Ϊ�ж�������һһ�Ƚϣ�ȫ����Ϊ����
bool chkPalindrome(ListNode* A)
{
	ListNode* fast = A;
	ListNode* slow = A;
	ListNode* prev = NULL;
	while (fast&&fast->next)
	{
		prev = slow;
		fast = fast->next->next;
		slow = slow->next;
	}
	slow=reverseList(slow);
	prev->next = NULL;
	while (A)
	{
		if (A->date == slow->date)
		{
			A = A->next;
			slow = slow->next;
		}
		else
		{
			return false;
		}
	}
	return true;
}

//�ཻ�����ж��Ƿ����ཻ��������ǣ����ص�һ���ཻʱ�Ľ�㡣
//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣�����������û�н��㣬���� null ��
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
	int Alen = 0;
	int Blen = 0;
	ListNode* Acur = headA;
	ListNode* Bcur = headB;
	while (Acur)
	{
		Alen++;
		Acur = Acur->next;
	}
	while (Bcur)
	{
		Blen++;
		Bcur = Bcur->next;
	}
	ListNode* longer = headA;
	ListNode* shorter = headB;
	if (Alen < Blen)
	{
		longer = headB;
		shorter = headA;
	}
	int gap = abs(Alen - Blen);
	while (gap--)
	{
		longer = longer->next;
	}
	while (longer)
	{
		if (longer->next == shorter->next)
		{
			return longer->next;
		}
		longer = longer->next;
		shorter = shorter->next;
	}
	return NULL;
}

//main����
//int main()
//{
//	ListNode* a1 = (ListNode*)malloc(sizeof(ListNode));
//	
//	ListNode* a2 = (ListNode*)malloc(sizeof(ListNode));
//	a1->next = a2;
//	ListNode* a3 = (ListNode*)malloc(sizeof(ListNode));
//	a2->next = a3;
//	ListNode* a4 = (ListNode*)malloc(sizeof(ListNode));
//	a3->next = a4;
//	ListNode* a5 = (ListNode*)malloc(sizeof(ListNode));
//	a4->next = a5;
//	ListNode* a6 = (ListNode*)malloc(sizeof(ListNode));
//	a5->next = a6;
//	ListNode* a7 = (ListNode*)malloc(sizeof(ListNode));
//	a7->next = NULL;
//
//
//	ListNode* b1 = (ListNode*)malloc(sizeof(ListNode));
//
//	ListNode* b2 = (ListNode*)malloc(sizeof(ListNode));
//	b1->next = b2;
//	ListNode* b3 = (ListNode*)malloc(sizeof(ListNode));
//	b2->next = a4;
//	getIntersectionNode(a1, b1);
//}

//����һ�������ж��������Ƿ��л���
//����ָ��
bool hasCycle(struct ListNode *head) 
{
	ListNode* slow, *fast;
	slow = fast = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//����һ�����ÿ���ָ���ҵ���һ������ʱ��Ľ�㣻�������㴦�Ͽ�������������Ϊһ������ı�ͷ��ԭ��ı�ͷΪ��һ��ͷ��ת������������Ľ�������⣻
//������������ѧ���ƣ���Ϊ���뻷�ĳ���ΪL������ָ���һ������ʱ����ָ������L+X����ָ������2��L+X��==L+N*C�����У�CΪ�����ܳ���NΪ��ָ���ߵ�Ȧ����
//�ɵ� L=N*C-X������ʱ��ԭ��ͷ������ڵľ�����ڻ����ܳ���N��-X��
//ֻ������ͬʱ�ߣ���һ��������������ڣ�
struct ListNode *detectCycle(struct ListNode *head) 
{
	struct ListNode* fast, *slow;
	fast = slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}
	while (fast != head)
	{
		fast = fast->next;
		head = head->next;
	}
	return head;
}