#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(void)
{
	string input1, input2;
	cin >> input1;
	cin >> input2;
	if (input1.size() < 5 || input2.size() < 5 || input1.size() <= input2.size())
		return 0;
	int *ZM = new int[26];  //记录26字母  //flag
	for (int i = 0; i < 26; i++)
		ZM[i] = 0;
	for (int i = 0; i < input1.size(); i++)
	{
		int tmp;
		tmp = input1[i] - 'A';
		if (ZM[tmp] == 1) continue;
		else ZM[tmp] = 1;  //做标记
	}
	int i;
	for (i = 0; i < input2.size(); i++)
	{
		int tmp;
		tmp = input2[i] - 'A';
		if (ZM[tmp] == 1) continue;
		else {
			printf("false");
			return 0;
		}
	}
	if (i == input2.size()) printf("true");
	return 0;
}
/*
   *输入两个字符串input1和input2，其中input1的长度大于input2。要求两个输入字符input1和input2的长度不小于5。
   *如果input2的全部字母都包含在input1中那么返回true，否则返回false。
*/