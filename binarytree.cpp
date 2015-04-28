//真二叉树重构

//描述：
/*
对于“真二叉树”（每个内部节点都有两个孩子的二叉树），给定它的先序、后序遍历序列足以完全确定它的结构。
将二叉树的n个节点用[1, n]内的整数进行编号，输入一棵真二叉树的先序、后序遍历序列，请输出它的中序遍历序列。
*/

//算法设计：
/*
根据先序遍历和后序遍历的规律，递归寻找左子数和右子数。
*/

#include<stdio.h>

#define MAX 4000001

int pre[MAX];
int post[MAX];
int in[MAX];
int n, m;

void inorder(int l1, int r1, int l2, int r2) 
{
	int i;
	if (r1 - l1 == 0) 
	{
		in[m++] = pre[l1];
		return;
	}
	for (i = l2; i <= r2; i++)
	{
		if (pre[l1+1] == post[i])
			break;
	}
	inorder(l1+1, l1+1+i-l2, l2, i);
	in[m++] = pre[l1];
	inorder(l1+2+i-l2, r1, i+1, r2-1);
}

int main()
{
	int i;
	m = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d",&pre[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &post[i]);
	inorder(0, n-1, 0, n-1);
	for (i = 0; i < n; i++)
		printf("%d ", in[i]);
	return 0;
}

