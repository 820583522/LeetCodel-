#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>


//1. 原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)。
//当num[a]===val时，赋值num[des]=num[src];最后只返回des的那个数组
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


//2. 删除排序数组中的重复项。OJ链接
//双指针解法，一前一后，有序数组中，相同元素必相邻，两两比较，若不同，则留下前一个值。
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



//4. 旋转数组。Oj链接
//12345右移两步，
//1.将12345先反转为54321；
//2.再分割线处分别对两边进行反转，就得到45123；
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


//5. 数组形式的整数加法。OJ链接
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


//反转单向链表
//三指针法，前两个用来头插，第三个指针用来记录下一个结点的地址，一起往前走
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

//203.去除链表中某个值的数
//双指针法，关键在于分析第一个值就是要删的值的情况；容易忽略掉
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




////将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
////先找到一个表头，然后尾插
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


//合并两个有序数组，
//先把两个数组放进一个数组中，再冒泡排序
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


//6. 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前 。OJ链接
//思路，把原链表分成两个链表，最后合在一起；
//步骤1.创建两个子链表的表头
//2.遍历原链表；分类，尾插到两表头之一的后边。
//3.将值大的链表接到值小的链表表尾；
//注意，有可能最后一个值大的结点指的是下一个小的结点；这就需要手动把它置成空；
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
	
	greattail->next = NULL;//非常细节的一个点，最后greattail的next可能指的是最后的一个小的，造成死循环；



	lesstail->next = greathead->next;
	ListNode* HEAD = lesshead->next;
	free(lesshead);
	free(greathead);
	return HEAD;
}



//单独的数字：恰有两个只出现过一次的数字，其他数字都出现两次。
//主要要熟悉异或^和按位与&的用法;
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
	//全部异或。ret最后的结果就是x1和x2异或出来的结果
	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	//找出ret中为0的第m位
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
	//分离原数组，m位为0为一组，m位为1的为一组
	//分离方法：
	// a&(1<<(m-1)),的值为1，说明a的第m位是1；值为0，说明a的第m位是0；
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

//链表的回文结构
//1.快慢指针来找到中间结点
//2.反转后半段链表
//3.以前半段为判断条件，一一比较；全等则为回文
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

//相交链表，判断是否是相交链表，如果是，返回第一次相交时的结点。
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
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

//main函数
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

//给定一个链表，判断链表中是否有环。
//快慢指针
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

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//方法一：先用快慢指针找到第一次相遇时候的结点；再相遇点处断开环，以相遇点为一个链表的表头，原表的表头为另一表头，转换成求两链表的交点的问题；
//方法二：用数学来推，记为进入环的长度为L，快慢指针第一次相遇时，慢指针走了L+X，快指针走了2（L+X）==L+N*C，其中，C为环的周长，N为快指针走的圈数；
//可得 L=N*C-X，即此时，原表头到环入口的距离等于环得周长得N倍-X；
//只需两处同时走，第一次相遇即环的入口；
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