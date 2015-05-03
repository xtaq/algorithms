//问题描述：
/*
Epicure先生正在编撰一本美食百科全书。为此，他已从众多的同好者那里搜集到了一份冗长的美食提名清单。既然源自多人之手，其中自然不乏重复的提名，故必须予以筛除。Epicure先生因此登门求助，并认定此事对你而言不过是“一碟小菜”，相信你不会错过在美食界扬名立万的这一良机。
输出
所有出现重复的提名（多次重复的仅输出一次），且以其在原清单中首次出现重复（即第二次出现）的位置为序
*/

//算法设计：
/*
构造hash表，拉链法解决冲突，当hash值相等时，判断链表节点字符串是否相等。
若相等，标记这个节点以防再次输出。
*/

#include<stdio.h>

#define MAX 1000001
int n;

typedef struct node{
	bool f;
	char c[41];
	struct node *next;
}node;

typedef struct vnode{
	node *first;
}vnodes;

vnodes list[MAX];

int hash(char *s)
{
	int seed = 31;
	long hash = 0;
	while (*s)
		hash = hash * seed -'a'+1+ (*s++);
	return (hash & 600000);
}

void strcpy(char *s2, char *s1)
{
	int i;
	for (i = 0; s1[i]; ++i)
	{
		s2[i] = s1[i];
	}
}

int strcmp(char *s1, char *s2)
{
	int i;
	for (i = 0; s1[i] || s2[i]; ++i)
	{
		if(s1[i] != s2[i])
			return 0;
	}
	return 1;
}

void init()
{
	scanf("%d", &n);
	getchar();
	char s[41];
	int i, j;
	while (n--)
	{
		scanf("%s", s);
		int flag = 0;
		int x = hash(s);
		node *a = new node;
		a = list[x].first;
		while (a)
		{
			if (strcmp(a->c, s))
			{
				flag = 1;
				if (a->f == 0)
				{
					printf("%s\n", s);
					a->f = 1;
					break;
				}
			}
			a = a->next;
		}
		if (flag)
			continue;
		node *p = new node;
		strcpy(p->c, s);
		p->next = list[x].first;
		list[x].first = p;
	}
}

int main()
{
	init();
	return 0;
}
