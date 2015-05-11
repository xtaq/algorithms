/*
题目描述
求一个长度不超过15的字符串的回文子序列个数（子序列长度>=1）。

输入描述
输入一个长度不超过15的字符串,字符串均由小写字母表示

输出描述
输出其回文子序列个数

样例输入

abaa

样例输出

10

注释:
本例中其所有回文子序列为：
a,b,a,a,aba,aba,aa,aa,aa,aaa 
一个字符串的子序列是指在原字符串上去除某些字符但不破坏余下元素的相对位置（在前或在后）而形成的新字符串。
*/

//使用搜索找出每个字串，然后判断是否回文。

#include<iostream>
#include<string>
using namespace std;

string str, creat = "";
bool visit[20] = {0};
int total = 0;

bool ispal(string s)
{
	for (int i = 0; i < s.length() / 2; ++i)
	{
		if (s[i] != s[s.length() - i - 1])
			return false;
	}
	return true;
}

void search(int len, int start)
{
	if (len <= 0)
	{
		if (ispal(creat))
		{
			cout << creat << endl;
			total++;
		}
		return;
	}
	for (int i = start; i < str.length(); ++i)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			creat.append(str, i, 1);
			search(len - 1, i + 1);
			visit[i] = 0;
			creat.erase(creat.length()-1, 1);
		}
	}
}

int main()
{
	cin >> str;
	for (int i = 1; i <= str.length(); ++i)
		search(i, 0);
	cout << total << endl;
	return 0;
}


