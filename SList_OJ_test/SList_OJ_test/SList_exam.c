#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//1. ԭ���Ƴ����������е�Ԫ��val��Ҫ��ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)��
//��num[a]===valʱ����ֵnum[des]=num[src];���ֻ����des���Ǹ�����
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

//2. ɾ�����������е��ظ��OJ����
//˫ָ��ⷨ��һǰһ�����������У���ͬԪ�ر����ڣ������Ƚϣ�����ͬ��������ǰһ��ֵ��
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



//4. ��ת���顣Oj����
//12345����������
//1.��12345�ȷ�תΪ54321��
//2.�ٷָ��ߴ��ֱ�����߽��з�ת���͵õ�45123��
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

//5. ������ʽ�������ӷ���OJ����


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

//��ת��������
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

//203.ȥ��������ĳ��ֵ����
//˫ָ�뷨���ؼ����ڷ�����һ��ֵ����Ҫɾ��ֵ����������׺��Ե�
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