#include <stdio.h>
#define MAX 1600001
int s[MAX];
int b[MAX];
int top;
int pop()
{
	//printf("pop %d\n",s[top-1]);
	return s[--top];
}
void push(int a)
{
	//printf("push %d\n",a);
	s[top++]=a;
}
int pop1()
{
	printf("pop\n");
	return s[--top];
}
void push1(int a)
{
	printf("push\n");
	s[top++]=a;
}
void show()
{
	int i;
	for(i=0;i<top;i++)
	{
		printf("%d ",s[i]);
	}
	printf("\n");
}
int main ()
{
	int i , j ,k ;
	int m , n;
	int flag = 0;
	scanf ("%d%d",&n,&m);
	for(i = 0; i < n ; i++)
	{
		scanf ( "%d",&b[i]);
	}
	 top = 0;
	int count = 0;
	i = 0;
	j = 2;
	push (1);
	//show();
	while(count < n)
	{
		if (top > m)
		{
			flag = 1;
			break ;
		}
		
		//printf("%d %d\n",b[i],s[top-1]);
		if(b[i] > s[top-1])
		{
			push(j++);
		}
		else if (b[i] == s[top-1])
		{
			pop();
			i++;	
			count ++;		
		}
		else 
		{
			//show();
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		printf("No\n");
	}
	else{
 		top = 0;
 		count = 0;
		i = 0;
		j = 2;
		push1 (1);
		while(count < n)
		{
			if (top > m)
		{
			break ;
		}
	//	printf("%d %d\n",b[i],s[top-1]);
		if(b[i] > s[top-1]&&j < n+1)
		{
			push1(j++);
		}
		else if (b[i] == s[top-1])
		{
			pop1();
			i++;	
			count ++;		
		}
		else 
		{
			//show();
			flag = 1;
			break;
		}
	}
		
	}
	return 0;
}
