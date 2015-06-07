#include<stdio.h>

#define LEN 7
int a[LEN] = { 10, 5, 2, 4, 7, 6, 12 };

//插入排序
void insert_sort()
{
	int i, j, key;
	for (j  = 1; j < LEN; ++j) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}

//选择排序
void selsort(int l[])
{
	int i, j, mini, tem; 
	for (i = 0; i < LEN; i++)
	{
		mini = i;
		for (j = i+1; j < LEN; j++)
		{
			if (l[mini] > l[j]) 
				mini = j;
		}
		if (mini != i) { 
			l[i] = l[i] ^ l[mini];
			l[mini] = l[i] ^ l[mini];
			l[i] = l[i] ^ l[mini];
		} 
	}
}

//归并排序
void merge(int start, int mid, int end)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int left[n1], right[n2];
    int i, j, k;

	for (i = 0; i < n1; ++i)
		left[i] = a[start+i];
	for (j = 0; j < n2; ++j)
		right[j] = a[mid+1+j];
	
	i = j = 0;
	k = start;
	while (i < n1 && j < n2)
		if (left[i] < right[j])
			a[k++] = left[i++];
		else
			a[k++] = right[j++];
	while (i < n1)
		a[k++] = left[i++];
	while (j < n2)
		a[k++] = right[j++];
}

void sort(int start, int end)
{
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		sort(start, mid);
		sort(mid+1, end);
		merge(start, mid, end);
	}
}

//快速排序
void quick_sort(int a[], int left, int right)
{
	int i, j, key;
	if (left < right)
	{
		i = left;
		j = right;
		key = a[i];
		while (i < j) 
		{
			while (i < j && a[j] > key)
				j--;
			if (i < j)
				a[i++] = a[j];
			
			while (i < j && a[i] < key)
				i++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = key;
		quick_sort(a, left, i-1);
		quick_sort(a, i+1, right);
	}
}

void quicksort2(int a[], int left, int right)
{
    int key, mi;
    if (left < right)
    {
        key = a[left];
        mi = left;
        for (int k = left + 1; k <= right; ++k)
        {
            if (a[k] < key)
            {
                int temp = a[k];
                a[k] = a[++mi];
                a[mi] = temp;
            }
        }
        int temp = a[left];
        a[left] = a[mi];
        a[mi] = temp;
        quicksort2(a, left, mi-1);
        quicksort2(a, mi+1, right);
    }
}

int main()
{
	int i;
	quicksort2(a, 0, LEN - 1);
	for (i = 0; i < LEN; ++i)
		printf("%d\t", a[i]);
	return 0;
}


