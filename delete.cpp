#include<stdio.h>

int a[10] = {4, 2, 9, 7, 2, 5, 12, 1, 1, 2};

void swap(int &a, int &b)
{
		int temp;
		temp = a;
		a = b;
		b = temp;
}

void quicksort(int a[], int start, int end)
{
		int i, j, k;
		if (start < end)
		{
				i = start;
				j = end;
				k = a[i];
				while (i < j)
				{
						while (i < j && a[j] > k)
								j--;
						if (i < j)
								a[i++] = a[j];
						
						while (i < j && a[i] < k)
								i++;
						if (i < j)
								a[j--] = a[i];
				}
				a[i] = k;
				quicksort(a, start, i - 1);
				quicksort(a, i + 1, end);
		}
}

int main()
{
		int j = 0;
		quicksort(a, 0, 9);
		if (a[0] == a[1])
				j++;
		for (int i = 1; i < 10; ++i)
		{
				if(a[i] == a[i+1])
				{
						swap(a[i], a[j]);
						j++;
				}
		}
		for (int i = j; i < 10; ++i)
				printf("%d\t", a[i]);
		return 0;
}

