#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//1. 原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)。
//当num[a]===val时，赋值num[des]=num[src];最后只返回des的那个数组
//int removeElement(int* nums, int numsSize, int vul)
//{
//	int src = 0;
//	int des = 0;
//	while (src < numsSize)
//	{
//		if (nums[src] != vul)
//		{
//			nums[des] = nums[src];
//			des++;
//			src++;
//		}
//		else
//		{
//			src++;
//		}
//	}
//	return des;
//}
//
//
//int main()
//{
//	int nums[] = { 1, 2, 2, 3, 4, 2 ,4};
//	int num = removeElement(nums, 7, 2);
//	printf("%d\n", num);
//}

//2. 删除排序数组中的重复项。OJ链接
//双指针解法，一前一后，有序数组中，相同元素必相邻，两两比较，若不同，则留下前一个值。
//int removeDuplicates(int* nums, int numsSize)
//{
//	int des = 0;
//	int cur = 1;
//	int prev = 0;
//	if (numsSize <= 0)
//	{
//		return 0;
//	}
//	while (cur<numsSize)
//	{
//		if (nums[cur] == nums[prev])
//		{
//			cur++;
//			prev++;
//		}
//		else
//		{
//			nums[des] = nums[prev];
//			des++;
//			prev++;
//			cur++;
//		}
//	}
//	nums[des] = nums[prev];
//	return ++des;
//}



//4. 旋转数组。Oj链接
//12345右移两步，
//1.将12345先反转为54321；
//2.再分割线处分别对两边进行反转，就得到45123；
//void rotate(int* nums, int numsSize, int k)
//{
//	if (numsSize <= 1)
//		return;
//	k %= numsSize;
//	int left = 0; 
//	int right = numsSize - 1;
//	while (left < right)
//	{
//		int tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//		left++;
//		right--;
//	}
//	left = 0;
//	right = k - 1;
//	while (left < right)
//	{
//		int tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//		left++;
//		right--;
//	}
//	left = k;
//	right = numsSize - 1;
//	while (left < right)
//	{
//		int tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//		left++;
//		right--;
//	}
//	return;
//}
//int main()
//{
//	int arr[] = {1};
//	rotate(arr,1, 10);
//	for (int i = 0; i < 1; i++)
//	{
//		printf("%d  ",arr[i]);
//	}
//}

//5. 数组形式的整数加法。OJ链接


//int* addToArrayForm(int* num, int numSize, int k,int* returnSize)
//{
//	int klen=0;
//	int fk = k;
//	while (k)
//	{
//		k /= 10;
//		klen++;
//	}
//	int len = (klen > numSize ? klen:numSize);
//	int* retArrey = (int*)malloc(sizeof(int)*(len + 1));
//	int prev = 0;
//	int sum = 0;
//	for (int i = 0; i <= len; i++)
//	{
//		if (numSize - i-1 < 0)
//		{
//			 sum = fk % 10 + prev;
//		}
//		else
//		{
//			 sum = fk % 10 + num[numSize - i-1] + prev;
//		}
//		if (sum >= 10)
//		{
//			retArrey[len-i] = sum % 10;
//			prev = 1;
//		}
//		else
//		{
//			retArrey[len-i] = sum;
//			prev = 0;
//		}
//		fk /= 10;
//	}
//	if (prev)
//	{
//		*returnSize = len+1;
//		return retArrey;
//	}
//	else
//	{
//		*returnSize = len;
//		return retArrey + 4;
//	}
//
//}
//int main()
//{
//	int arr[] = { 1,2,0,0 };
//	int returnSize = 0;
//	int* ret = addToArrayForm(arr, 4 ,34,&returnSize);
//	for (int i = 0; i < returnSize; i++)
//	{
//		printf("%d  ", ret[i]);
//	}
//	return 0;
//}

//反转单向链表
//struct ListNode* reverseList(struct ListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//	{
//		return head;
//	}
//	struct ListNode* n1 = NULL;
//	struct ListNode* n2 = head;
//	struct ListNode* n3 = head->next;
//	while (n2)
//	{
//		n2->next = n1;
//		n1 = n2;
//		n2 = n3;
//		if (n3)
//			n3 = n3->next;
//	}
//	return n1;
//
//}

//203.去除链表中某个值的数
//双指针法，关键在于分析第一个值就是要删的值的情况；容易忽略掉
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			if (cur == head)
//			{
//				head = cur->next;
//				cur = head;
//			}
//			else
//			{
//				prev->next = cur->next;
//				cur = cur->next;
//			}
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//}