// 问题描述：

/*现有一条单向单车道隧道，每一辆车从隧道的一端驶入，另一端驶出，不允许
超车,该隧道对车辆的高度有一定限制，在任意时刻，管理员希望知道此时隧道中最
高车辆的高度是多少,现在请你维护这条隧道的车辆进出记录，并支持查询最高车辆
*/

//算法设计：

/*
模拟实现队列存储车辆高度，用于输出车辆
模拟一个栈，维护这个栈的栈底为隧道里的车辆的最大高度，在栈底加一个指针，
当最大高度出队时，指针加一。
当车辆进队，把栈中比他小的车辆弹出，使栈维持一个车辆最大高度递减状态。
*/

#include<stdio.h> 

#define MAX 2000001

int head, tail;
int n, point, max;
int a[MAX];
int q[MAX];

void inque(int s)
{
	q[tail++] = s;
}

void outque()
{
	head++;
}

bool empty()
{
	if (point < max+1)
		return true;
	else
		return false;
}

void pop()
{
	point--;
}

int top()
{
	return a[point-1];
}

void push(int s)
{
	a[point++] = s;
}

int main()
{
	int i, j, k, n, x;
	char c;
	scanf("%d", &n);
	getchar();
	point = tail = head = max = 0;
	while(n--)
	{
		c = getchar();
		while( c == ' ' || c == '\n')
			c = getchar();
		if (c == 'E') 
		{
			scanf("%d", &x);
			inque(x);
			while(!empty())
			{
				if(top() >= x) 
				{
					push(x);
					break;
				}
				else
					pop();
			}
			if (empty()) 
				push(x);
		}
		if (c == 'D')
		{
			if ( q[head] == a[max]) 
				max++;
			printf("%d\n", q[head]);
			outque();
		}
		if (c == 'M') 
			printf("%d\n", a[max]);
		getchar();
	}
	return 0;
}

