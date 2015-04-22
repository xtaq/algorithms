//问题描述：

/*
其中，A为入口，B为出口，S为中转盲端。所有铁道均为单轨单向式：列车行驶
的方向只能是从A到S，再从S到B；另外，不允许超车。
因为车厢可在S中驻留，所以它们从B端驶出的次序，可能与从A端驶入的次序不同。
不过S的容量有限，同时驻留的车厢不得超过m节。
设某列车由编号依次为{1, 2, ..., n}的n节车厢组成。调度员希望知道，按照以上
交通规则，这些车厢能否以{a1, a2, ..., an}的次序，重新排列后从B端驶出。
如果可行，应该以怎样的次序操作?
*/

//算法设计：

/*
模拟实现一个中转栈，对比进栈序列与最终序列
若第一个元素小与最终序列第一个元素，压入中转栈，进栈序列加一
若相等，最终序列加一
若小于，比较栈顶元素与最终序列元素，如不等，不匹配，break
        如相等，进栈元素减一，最终序列加一
进栈序列循环完毕，查看栈中剩余元素与最终序列匹配。
*/

#include<stdio.h>

#define MAX  1600001
int point;
int a[MAX];
int b[MAX];

void pop()
{
	a[--point] = 0;
}

void push(int s) 
{
	a[point++] = s;
}

int main()
{
	int i, j, k, n, m;
	int flag = 0;
	scanf("%d %d", &n, &m);
	point = 0;
	for (i = 0; i < n; i++) 
	{
		scanf("%d", &b[i]);
	}
	for(i = 1, j = 0 ; i <= n ; i++) 
	{
		if (b[j] - j > m)
		{
			flag = 1;
			break;
		}
		if (b[j] > i)
			push(i);
		else if (b[j] == i)
		{	j++;
		}
		else
		{	
			if (a[point-1] != b[j]) 
			{
				flag = 1;
				break;
			}
			else 
			{
				pop();
				i--;
				j++;
			}
		}
	}
	if (j < n)
	{
		for (; j < n; j++) 
		{
			if ( b[j] != a[point-1])
			{
				flag = 1;
				break;
			}
			else
				pop();
		}
	}
	if (flag)
	{
		printf("No\n");
		return 0;
	}
	point = 0;
	for(i = 1, j = 0 ; i <= n ; i++) 
	{
		if (b[j] > i)
		{
			push(i);
			printf("push\n");
		}
		else if (b[j] == i)
		{	
			j++;
			printf("push\npop\n");
		}
		else
		{	
				printf("pop\n");
				pop();
				i--;
				j++;
		}
	}
	while (point -- )
	{
		printf("pop\n");
	}
	return 0;
}

