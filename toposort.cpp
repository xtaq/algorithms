//问题描述：
/*
Shrek是一个大山里的邮递员，每天负责给所在地区的n个村庄派发信件。但杯具的是，由于道路狭窄，年久失修，村庄间的道路都只能单向通过，甚至有些村庄无法从任意一个村庄到达。这样我们只能希望尽可能多的村庄可以收到投递的信件。
Shrek希望知道如何选定一个村庄A作为起点（我们将他空投到该村庄），依次经过尽可能多的村庄，路途中的每个村庄都经过仅一次，最终到达终点村庄B，完成整个送信过程。这个任务交给你来完成。
*/
//算法设计：
/*
拓扑排序算法主要是循环执行以下两步，直到不存在入度为0的顶点为止。
(1) 选择一个入度为0的顶点并输出之；
(2) 从网中删除此顶点及所有出边。
根据拓扑排序，找出入度为0的循环总数即为所求，用图的邻接表表示法。
*/

#include<stdio.h>

#define MAX 100010

int ind[MAX] = {0};
int q[MAX], q1[MAX];
int m, n, s, s1;

void push(int a)
{
	q[s++] = a;
}

int pop()
{
	return q[--s];
}

void push2(int a)
{
	q1[s1++] = a;
}

int pop2()
{
	return q1[--s1];
}

typedef struct node{
	int val;
	struct node *next;
}node;

typedef struct vnode{
	node *first;
}vnodes;

vnodes graph[MAX];

int main()
{
	int i, j;
	int max  = 0;
	int k = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		ind[b]++;
		node *d = new node;
		d->val = b;
		d->next = graph[a].first;
		graph[a].first = d;
	}
	for (i = 1; i <= n; ++i)
	{
		if(ind[i] == 0)
		{
			ind[i]--;
			push(i);
			k++;
		}
	}
	while (true)
	{
		max++;
		if (k == n)	break;
		while(s)
		{
			node *p = graph[pop()].first;
			while(p)
			{
				ind[p->val]--;
				if (ind[p->val]==0)
				{
					push2(p->val);
				}
				p = p->next;
			}
		}
		while (s1)
		{
			push(pop2());
			k++;
		}
	}
	printf("%d\n", max);
	return 0;
}

