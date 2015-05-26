//问题描述：
//两个字符串，判断第二个字符串是否是第一个字符串循环位移得到的。

#include<stdio.h>

#define MAX 100001

char s1[MAX];
char s2[MAX];
int m;

int len(char *p)
{
		int i=0;
		while(*p++)
				i++;
		return i;
}

bool strcmp(int k, int len)
{
		int m = k;
		int n = len - k;
		for (int i = 0; i < len - k; ++i, ++m)
		{
				if (s1[i] != s2[m])
						return 0;
		}
		for (int i = 0; i < k; ++i, ++n)
		{
				if (s1[n] != s2[i])
						return 0;
		}
		return 1;
}

int main()
{
		while(~scanf("%s %s", s1, s2))
		{
				if (len(s1) != len(s2))
				{
						printf("NO\n");
						continue;
				}
				else
				{
						int a[MAX]={0};
						int k = 0;
						int flag = 0;
						for (int j = 0; j < len(s2); ++j)
						{
								if (s1[0] == s2[j])
										a[k++] = j;
						}
						while(k--)
						{
								if (strcmp(a[k], len(s1)))
								{
										printf("YES\n");
										flag = 1;
										break;
								}
						}
						if (flag == 0)
							printf("NO\n");
				}
		}
		return 0;
}

