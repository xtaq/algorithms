#include<stdio.h>
#include<string.h>

int t = 0;
bool valid[1000000];

void getprime(int n, int *ans)
{
		memset (valid, true, sizeof(valid));
		for (int i = 2; i <= n; ++i)
		{
				if (valid[i])
				{
						t++;
						ans[t] = i;
				}
				for (int j = 1; ((j <= t) && (i*ans[j] <= n)); ++j)
				{
						valid[i*ans[j]] = 0;
						if (i % ans[j] == 0) break;
				}
		}
}

int main()
{
		int ans[1000000];
		int n = 1000;
		getprime(n, ans);
		printf("%d\n", t);
		for (int i = 1; i <= t; ++i)
				printf("%d\t", ans[i]);
		return 0;
}

