//问题描述：
/*
某广播公司要在一个地区架设无线广播发射装置。该地区共有n个小镇，每个小镇都要安装一台发射机并播放各自的节目.
不过，该公司只获得了FM104.2和FM98.6两个波段的授权，而使用同一波段的发射机会互相干扰。已知每台发射机的信号覆盖范围是以它为圆心，20km为半径的圆形区域
因此，如果距离小于20km的两个小镇使用同样的波段，那么它们就会由于波段干扰而无法正常收听节目。现在给出这些距离小于20km的小镇列表，试判断该公司能否使得整个地区的居民正常听到广播节目。
*/
//算法设计：
/*
任意三个点形成一个环即可判断不符合要求，用邻接矩阵表示图，搜索每个节点的后继元素，看他们两两之间有没有通路。
*/

#include<stdio.h>

#define MAX 10010

bool graph[MAX][MAX]= {0};
int n, m, s;
int q[MAX] = {0};

void push(int a)
{
	q[s++] = a;
}

void pop()
{
	s--;
}

void init()
{
	scanf("%d %d", &n, &m);
	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}
}

int main()
{
	int i, j, k;
	init();
	s = 0;
	for (i = 1; i<= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (graph[i][j])
				push(j);
		}
		for (j = 0; j < s; ++j)
		{
			for (k = j+1; k < s; ++k)
			{
				if (graph[q[j]][q[k]])
				{
					printf("-1\n");
					return 0;
				}
			}
		}
		s = 0;
	}
	printf("1\n");
	return 0;
}

