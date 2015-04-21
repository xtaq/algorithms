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

